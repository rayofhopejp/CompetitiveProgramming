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


int N;
int A[100005];
//最長部分広義減少列を求めます
//はめんどくさいので、Aの中身の符号を逆にして最長部分広義増加列を求めます
int LIS(int *A,const int A_len){
    int dp[A_len+5];
    rep(i,A_len+3)dp[i]=LLINF;
    dp[0]=-A[0];
    //dpは広義単調増加、出来るだけ小さく更新したい
    for(int i=1;i<A_len;i++){
        //二分探索で更新箇所を求める 
        //追加した文字がdp[i]以上ならばもっと伸ばせる
        //(更新場所は、追加した文字より大きいところで一番小さいの)
        int p=upper_bound(dp,dp+A_len,-A[i])-dp;
        //大きいところがあればそこを更新する
        if(p>0)dp[p]=-A[i];
        else if(dp[p]>-A[i])dp[p]=-A[i];
    }
    //一番最後の更新されたところを探す
    //rep(i,A_len)printf("%lld/",dp[i]);
    int p=lower_bound(dp,dp+A_len,LLINF)-dp;
    return p;
}
signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld\n",&A[i]);
    int ans=LIS(A,N);
    printf("%lld\n",ans);
    return 0;
}
