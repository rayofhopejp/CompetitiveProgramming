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

int A,B,C;
double dp[105][105][105];

double dfs(int i,int j, int k){
    if(dp[i][j][k]) return dp[i][j][k];
    if(i==100 || j==100 || k==100)return 0.0;
    double ret=0.0;
    ret+=((double)i/(double)(i+j+k))*(1.0+dfs(i+1,j,k));
    ret+=((double)j/(double)(i+j+k))*(1.0+dfs(i,j+1,k));
    ret+=((double)k/(double)(i+j+k))*(1.0+dfs(i,j,k+1));
    dp[i][j][k]=ret;
    return ret;
}
signed main(){
    scanf("%lld %lld %lld",&A,&B,&C);
    printf("%.9lf\n",dfs(A,B,C));
}