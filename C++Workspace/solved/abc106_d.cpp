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

//解説
//二次元累積和
int N,M,Q;
int L[200005],R[200005];
int dp[505][505];
signed main(){
    scanf("%lld %lld %lld",&N,&M,&Q);
    rep(l,N+1)rep(r,N+1)dp[l][r]=0;
    rep(i,M){
        int l,r;
        scanf("%lld %lld",&l,&r);r--;l--;
        dp[l][r]+=1;
    }
    rep(i,N)rep(j,N)if(i!=0)dp[i][j]+=dp[i-1][j];
    rep(j,N)rep(i,N)if(j!=0)dp[i][j]+=dp[i][j-1];
    rep(i,Q){
        int p,q;
        scanf("%lld %lld",&p,&q);p--;q--;
        int ans=dp[q][q];
        if(p>0)ans-=dp[p-1][q]+dp[q][p-1]-dp[p-1][p-1];
        printf("%lld\n",ans);
    }
}