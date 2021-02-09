#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
#include<map>
 
//https://atcoder.jp/contests/tdpc/tasks/tdpc_contest
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
bool dp[105][10005];
int p[105];
signed main(){
    scanf("%lld",&N);
    int max_p=0;
    rep(i,N){
        scanf("%lld",&p[i]);
        max_p=max(max_p,p[i]);
    }
    int W=max_p*N;
    dp[0][0]=true;
    rep(i,N){
        rep(j,W+1){//配るdp
            if(!dp[i][j])continue;
            //i番目の問題を解く
            if(j+p[i]<=W)dp[i+1][j+p[i]]=true;
            //i-1番目の問題を解かない
            dp[i+1][j]=true;
        }
    }
    int ans=0;
    rep(i,W+1){
        if(dp[N][i])ans++;
    }
    printf("%lld\n",ans);
    return 0;
}