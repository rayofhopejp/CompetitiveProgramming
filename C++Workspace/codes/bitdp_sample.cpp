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

int N,M;
int a[1005],b[1005];
int c[1005][20];
int dp[1005][1<<12];//dp[i][j]:i番目まで使った時、状態jになるための最低値
vector<int> ans;
signed main(){
    scanf("%lld %lld",&N,&M);
    rep(i,M){
        scanf("%lld %lld",&a[i],&b[i]);
        rep(j,b[i]){
            scanf("%lld",&c[i][j]);c[i][j]--;
        }
    }
    //bitDP
    //dp[i][j]:i番目まで使った時、状態jになるための最低値
    rep(i,M+1)for(int j=0;j<(1<<N);j++)dp[i][j]=LLINF;
    dp[0][0]=0;//0この鍵までしか使わないと0
    rep(i,M){
        //鍵で開けられる箱が1になった数字を求める
        int boxes=0;
        for(int j=0;j<b[i];j++){
            boxes|=1<<c[i][j];
        }
        //printf("boxes:%lld\n",boxes);
        for(int j=0;j<(1<<N);j++){
            //状態jから、鍵iで開けられる状態について遷移
            dp[i+1][j|boxes]=min(dp[i+1][j|boxes],dp[i][j]+a[i]);
            //鍵を使わないとき
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
        }
    }
    /*rep(i,M){
        for(int j=0;j<(1<<N);j++)printf("%lld ",dp[i][j]);
        printf("\n");
    }*/
    if(dp[M][(1<<N)-1]<LLINF)printf("%lld\n",dp[M][(1<<N)-1]);
    else printf("%lld\n",(int)-1);
    return 0;
}
