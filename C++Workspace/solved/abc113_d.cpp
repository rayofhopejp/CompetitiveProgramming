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

int H,W,K;
int dp[105][15];
signed main(){
    scanf("%lld %lld %lld",&H,&W,&K);
    rep(h,H+1){
        rep(w,W){
            if(h==0&&w==0)dp[h][w]=1;
            dp[h][w]%=mod;
            rep(i,1<<(W-1)){
                //この掛け方がOKかどうかを試す
                int ifok=true;
                rep(j,W-2){
                    if( ( (i>>j)%2 ) & ( (i>>(j+1))%2 ) ){ifok=false;break;}
                }
                if(!ifok)continue;
                //この掛け方で現在の1からの位置がどこへ移るか
                if(w!=W-1&&(i>>w)%2==1){//右
                    dp[h+1][w+1]+=dp[h][w];
                    dp[h+1][w+1]%=mod;
                }else if(w!=0&&(i>>(w-1))%2==1){//左
                    dp[h+1][w-1]+=dp[h][w];
                    dp[h+1][w-1]%=mod;
                }else{//真ん中
                    dp[h+1][w]+=dp[h][w];
                    dp[h+1][w]%=mod;
                }
            }
            //printf("%lld ",dp[h][w]);
        }
        //printf("\n");
    }
    printf("%lld\n",dp[H][K-1]%mod);
}