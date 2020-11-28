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
int N;
int X[20],Y[20],Z[20];
int caluculate_cost(int from,int to){
    return abs(X[to]-X[from])+abs(Y[to]-Y[from])+max((int)0,Z[to]-Z[from]);
}
int dp[1<<20][20];
signed main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld %lld %lld",&X[i],&Y[i],&Z[i]);
    }
    rep(i,1<<N)rep(j,N)dp[i][j]=INF;
    //go to first town
    dp[1<<0][0]=0;
    //do transition
    rep(i,1<<N){
        rep(j,N){
            rep(k,N){
                //transition from j to k
                if(i&(1<<k))continue;//check if k hasn't be visited
                dp[i|(1<<k)][k]=min(dp[i|(1<<k)][k],dp[i][j]+caluculate_cost(j,k));
            }
        }
    }
    //return to first city and print answer
    int ans=INF;
    rep(i,N){
        ans=min(ans,dp[(1<<N)-1][i]+caluculate_cost(i,0));
    }
    printf("%lld\n",ans);
}