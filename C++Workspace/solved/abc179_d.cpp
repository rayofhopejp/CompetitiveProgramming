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
//#define mod 1000000007
#define mod 998244353

int N,K;
int L[15],R[15];
int dp[200005];
signed main(){
    scanf("%lld %lld",&N,&K);
    rep(i,K){
        scanf("%lld %lld",&L[i],&R[i]);
    }
    rep(i,N)dp[i]=0;
    dp[0]=1;dp[1]=-1;
    rep(i,N){
        if(i!=0)dp[i]+=dp[i-1];
        dp[i]=(dp[i]+mod)%mod;
        rep(j,K){
            if(i+L[j]<N)dp[i+L[j]]+=dp[i]%mod;
            if(i+R[j]+1<N)dp[i+R[j]+1]-=dp[i]%mod;
        } 
        dp[i]=(dp[i]+mod)%mod;
    }
    printf("%lld\n",(dp[N-1]+mod)%mod);
}