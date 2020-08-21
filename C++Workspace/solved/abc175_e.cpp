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

int R,C,K;
int map_item[3005][3005];
int dp[3005][3005][5];
signed main(){
    scanf("%lld %lld %lld",&R,&C,&K);
    rep(i,K){
        int r,c,v;
        scanf("%lld %lld %lld",&r,&c,&v);r--;c--;
        map_item[r][c]=v;
    }
    rep(i,R){
        rep(j,C){
            rep(k,4){
                //拾わないで横に移動
                dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]);
                //拾わないで下に移動
                dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][k]);
                //拾って横に移動
                dp[i][j+1][k+1]=max(dp[i][j+1][k+1],dp[i][j][k]+map_item[i][j]);
                //拾って下に移動
                if(k!=3)dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][k]+map_item[i][j]);
            }
        }
    }
    int ans=0;
    ans=max(ans,dp[R-1][C-1][0]+map_item[R-1][C-1]);
    ans=max(ans,dp[R-1][C-1][1]+map_item[R-1][C-1]);
    ans=max(ans,dp[R-1][C-1][2]+map_item[R-1][C-1]);
    ans=max(ans,dp[R-1][C-1][3]);
    printf("%lld\n",ans);
    return 0;
}