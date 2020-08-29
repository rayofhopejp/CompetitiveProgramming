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
struct union_find{
    int *parent; //parent[i]=parent of i
    int N;
    union_find(int N):N(N){
        parent=new int[N];
        rep(i,N)parent[i]=i; //init
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
    int countmax(){//破壊的
        rep(i,N)root(i);
        sort(parent,parent+N);
        //rep(i,N)printf("%lld-",parent[i]);
        int maxcnt=1;
        int cnt=1;
        rep(i,N-1){
            if(parent[i]!=parent[i+1]){
                maxcnt=max(cnt,maxcnt);
                cnt=1;
            }else{
                cnt++;
            }
        }
        maxcnt=max(cnt,maxcnt);
        return maxcnt;
    }
};

int N,M;
signed main(){
    scanf("%lld %lld",&N,&M);
    union_find uf(N);
    rep(i,M){
        int a,b;
        scanf("%lld %lld",&a,&b);
        a--;b--;
        uf.unite(a,b);
    }
    int ans=uf.countmax();
    printf("%lld\n",ans);
}