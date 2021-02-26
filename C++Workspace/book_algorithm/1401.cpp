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

int N,M;
vector<int> edges[100005];
int inedgecount[100005];
int dp[100005];
vector<int> sorted_nodes;
int num_in_sorted_nodes[100005];
signed main(){
    scanf("%lld %lld",&N,&M);
    rep(i,M){
        int a,b;
        scanf("%lld %lld",&a,&b);
        a--;b--;
        edges[a].pb(b);
        inedgecount[b]++;
    }
    //トポロジカルソート(幅優先探索による)
    queue<int> que;
    rep(i,N)if(inedgecount[i]==0)que.push(i);
    while(!que.empty()){
        int now=que.front();que.pop();
        num_in_sorted_nodes[now]=sorted_nodes.size();
        sorted_nodes.pb(now);
        for(auto next:edges[now]){
            inedgecount[next]--;
            if(inedgecount[next]==0)que.push(next);
        }
    }
    //rep(i,N)printf("%lld,",sorted_nodes[i]);
    //動的計画法
    int ans=0;
    rep(i,N){
        int now=sorted_nodes[i];
        ans=max(ans,dp[i]);
        rep(e,edges[now].size()){
            int next=num_in_sorted_nodes[edges[now][e]];
            dp[next]=max(dp[next],dp[i]+1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}