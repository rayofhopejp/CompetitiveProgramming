#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
#include<map>
 
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2877

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
int a[505];
int sum_a[505];//平均のために累積和を求める
double dp[505][505];
double mean_a(int i,int j){//[i,j)の平均を返す
    if(i>=j)return 0;
    if(j==0) return 0;
    if(i==0)return (double)sum_a[j-1]/(double)j;
    return (double)(sum_a[j-1]-sum_a[i-1])/(double)(j-i);
}
signed main(){
    scanf("%lld %lld",&N,&M);
    rep(i,N){
        scanf("%lld",&a[i]);
        if(i==0)sum_a[i]=a[i];
        else sum_a[i]=sum_a[i-1]+a[i];
    }
    rep(i,N+1)rep(j,M+1)dp[i][j]=-INF;//初期化をちゃんと、しようね！
    dp[0][0]=0;
    for(int i=0;i<=N;i++){//dp[i][j]:[0,i)番目までを適切にj個に分けた時の平均値の合計を調べる
        for(int j=1;j<=M;j++){
             for(int k=0;k<i;k++){//kは0~N-1,i=0の時は動かない
                dp[i][j]=max(dp[i][j],dp[k][j-1]+mean_a(k,i));
            }
        }
    }
    double ans=-INF;
    rep(i,M+1){
        ans=max(ans,dp[N][i]);
    }
    printf("%.10lf\n",ans);
    return 0;
}