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
int a[405];
int sum_a[405];
int dp[405][405];
int bubun_sum(int i,int j){//[i,j]の部分和
    if(i==0)return sum_a[j];
    else return sum_a[j]-sum_a[i-1];
}
signed main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld",&a[i]);
        if(i==0)sum_a[i]=a[i];
        else sum_a[i]=sum_a[i-1]+a[i];
    }
    //初期化
    rep(i,N)rep(j,N)dp[i][j]=LLINF;
    rep(i,N)dp[i][i]=0;
    for(int i=0;i<N;i++){
        for(int j=i-1;j>=0;j--){//[j,i]が大きなスライムになっている時
            //どこで切るか全通り試す
            int min_cut=LLINF;
            for(int k=j;k<i;k++)min_cut=min(min_cut,dp[j][k]+dp[k+1][i]);
            //くっつける
            dp[j][i]=min_cut+bubun_sum(j,i);
        }
    }
    printf("%lld\n",dp[0][N-1]);
    return 0;
}