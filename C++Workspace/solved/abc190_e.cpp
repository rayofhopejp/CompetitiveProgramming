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

int N,M,K;//K<=17
vector<int> edges[100005];
int C[20];
int dist[20][100005];
int dp[1<<20][20];
signed main(){
    scanf("%lld %lld",&N,&M);
    rep(i,M){
        int a,b;
        scanf("%lld %lld",&a,&b);
        a--;b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    scanf("%lld",&K);
    rep(i,K){scanf("%lld",&C[i]);C[i]--;}
    //幅優先探索
    rep(i,K)rep(j,N)dist[i][j]=LLINF;
    rep(i,K){
        queue<int> q;
        q.push(C[i]);
        dist[i][C[i]]=0;
        while(!q.empty()){
            int now=q.front();q.pop();
            for(auto e:edges[now]){
                if(dist[i][e]<LLINF)continue;
                dist[i][e]=dist[i][now]+1;
                q.push(e);
            }
        }
    }
    //動的計画法
    rep(i,1<<K)rep(j,K)dp[i][j]=LLINF;
    rep(i,K)dp[1<<i][i]=1;
    rep(i,1<<K){
        rep(j,K){//最後の宝石
            if(dp[i][j]>=LLINF)continue;
            if(!(i&(1<<j)) )continue;//最後の宝石が存在しない時は飛ばす
            //配るdp
            rep(k,K){//次の宝石
                if(j==k)continue;
                int newi=i|(1<<k);
                dp[newi][k]=min(dp[newi][k],dp[i][j]+dist[j][C[k]]);
            }
        }
    }
    int ans=LLINF;
    /*
    rep(i,K){
        rep(j,K)printf("%lld ",dist[i][C[j]]);
        printf("\n");
    }
    
    rep(i,1<<K){
        rep(j,K)printf("%lld ",dp[i][j]);
        printf("\n");
    }
    */
    rep(i,K)ans=min(dp[(1<<K)-1][i],ans);
    if(ans>=LLINF)printf("-1\n");
    else printf("%lld\n",ans);
}