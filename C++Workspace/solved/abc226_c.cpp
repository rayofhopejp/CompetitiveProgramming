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

int N;
int T[200005];
int K [200005];
vector<int> edge[200005];
bool visited[200005];

int dfs(int now){
    visited[now]=true;
    int ans=0;
    for(auto to:edge[now]){
        if(visited[to])continue;
        ans+=dfs(to);
    }
    ans+=T[now];
    return ans;
}
signed main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld %lld",&T[i],&K[i]);
        rep(j,K[i]){
            int e;
            scanf("%lld",&e);e--;
            edge[i].pb(e);
        }
        visited[i]=false;
    }
    //深さ優先探索
    int ans=dfs(N-1);
    printf("%lld\n",ans);
    return 0;
}