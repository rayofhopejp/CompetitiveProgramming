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
#define int long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007
//#define mod 998244353

//union find
//解説AC
//↑誤読して最短経路の和だと思っていた…
struct union_find{
    int *parent; //parent[i]=parent of i
    int N;
    int *size;
    union_find(int N):N(N){
        parent=new int[N];
        size=new int[N];
        rep(i,N)parent[i]=i; //init
        rep(i,N)size[i]=1;
    }
    int root(int x){ // take the root of x 
        if(parent[x]==x) return x;
        parent[x]=root(parent[x]); // recursion
        return parent[x];
    }
    void unite(int x,int y){// unite tree y to tree x
        int rx=root(x);
        int ry=root(y);
        if(rx==ry) return;
        parent[ry]=rx;
        size[rx]+=size[ry];
    }
    bool same(int x,int y){
        int rx=root(x);
        int ry=root(y);
        return rx==ry;
    }
    bool IsAllSameTree(){
        int rt=parent[0];
        rep(i,N){
            if(rt!=parent[i])return false;
        }
        return true;
    }
    int size_of_tree(int x){
        return size[root(x)];
    }
};

int N;
vector< pair<int,pair<int,int>> > edges;//edges, <weight <from,to>>

signed main(){
    scanf("%lld",&N);
    rep(i,N-1){
        int u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        u--;v--;
        edges.pb(mp(w,mp(u,v)));
    }
    sort(edges.begin(),edges.end());
    union_find uf(N);
    int ans=0;
    for(int i=0;i<N-1;i++){
        int cost=edges[i].first;
        int from=edges[i].second.first;
        int to=edges[i].second.second;
        ans+=cost*uf.size_of_tree(from)*uf.size_of_tree(to);
        uf.unite(from,to);
    }
    printf("%lld\n",ans);
}