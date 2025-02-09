#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
#include<map>
 
 
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007
//#define mod 998244353

int N,M;
struct union_find_kaizou{
    int *parent; //parent[i]=parent of i
    int N;
    vector<pair<int,pair<int,int>>> waste_edge;
    union_find_kaizou(int N):N(N){
        parent=new int[N];
        rep(i,N)parent[i]=i; //init
    }
    int root(int x){ // take the root of x 
        if(parent[x]==x) return x;
        parent[x]=root(parent[x]); // recursion
        return parent[x];
    }
    void unite(int x,int y,int edge){// unite tree y to tree x
        int rx=root(x);
        int ry=root(y);
        if(rx==ry){
            waste_edge.push_back(make_pair(edge,make_pair(x,y)));
            return;
        }
        parent[ry]=rx;
    }
    bool same(int x,int y){
        int rx=root(x);
        int ry=root(y);
        return rx==ry;
    }
    bool IsAllSameTree(){
        rep(i,N)root(i);
        int rt=parent[0];
        rep(i,N){
            if(rt!=parent[i])return false;
        }
        return true;
    }
    vector<pair<int,pair<int,int>>> reuse_waste_edge(){
        vector<pair<int,pair<int,int>>> ans;//edge, f->s
        vector<int> reps;//roots
        rep(i,N){
            if(root(i)==i)reps.push_back(i);
        }
        int ans_size=reps.size()-1;
        for(auto e: waste_edge){
            if(ans.size()==ans_size)return ans;
            int rf=root(e.second.first);
            int to=reps[reps.size()-1]==rf ?reps[reps.size()-2] : reps[reps.size()-1];
            if(reps[reps.size()-1]==rf)reps.erase(reps.end()-2);
            else reps.pop_back();
            int edge=e.first;
            //付け替え
            ans.push_back(make_pair(edge,make_pair(e.second.second,to)));
            unite(rf,to,-1);
        }
        return ans;
    }
};
signed main(){
    scanf("%d %d",&N,&M);
    union_find_kaizou uf(N);
    rep(i,M){
        int a,b;
        scanf("%d %d",&a,&b);a--;b--;
        uf.unite(a,b,i+1);
    }
    vector<pair<int,pair<int,int>>> ans=uf.reuse_waste_edge();
    printf("%d\n",ans.size());
    for(auto a:ans){
        printf("%d %d %d\n",a.first,a.second.first+1,a.second.second+1);
    }
}