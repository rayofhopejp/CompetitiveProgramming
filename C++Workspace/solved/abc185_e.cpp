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
int A[1005],B[1005];
int dp[1005][1005];
signed main(){
    scanf("%lld %lld",&N,&M);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,M)scanf("%lld",&B[i]);
    rep(i,N+1)rep(j,M+1)dp[i][j]=LLINF;
    dp[0][0]=0;
    rep(i,N+1){
        rep(j,M+1){
            //A[i]を取り除く
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
            //B[j]を取り除く
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
            //A[i]B[j]を使う
            if(A[i]==B[j])dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
            else dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+1);
        }
    }
    printf("%lld\n",dp[N][M]);
}