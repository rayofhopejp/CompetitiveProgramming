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
int H,W;
char S[2000][2000];
int X[2000][2000];//dp[i][j-1]+dp[i][j-2]+...
int Y[2000][2000];
int Z[2000][2000];
int dp[2000][2000];
signed main(){
    scanf("%lld %lld",&H,&W);
    rep(i,H){
        rep(j,W){
            while(S[i][j]!='.' && S[i][j]!='#'){
                scanf("%c",&S[i][j]);
            }
            X[i][j]=0;Y[i][j]=0;Z[i][j]=0;
            dp[i][j]=0;
        }
    }
    //Queen is at (0,0)
    dp[0][0]=1;
    rep(y,H){
        rep(x,W){
            if(y==0&&x==0)continue;
            if(S[y][x]=='.'){
                if(x>0)X[y][x]=dp[y][x-1]+X[y][x-1];
                if(y>0)Y[y][x]=dp[y-1][x]+Y[y-1][x];
                if(x>0&&y>0)Z[y][x]=dp[y-1][x-1]+Z[y-1][x-1];
            }else{
                X[y][x]=0;
                Y[y][x]=0;
                Z[y][x]=0;
            }
            dp[y][x]=X[y][x]+Y[y][x]+Z[y][x];
            X[y][x]%=mod;
            Y[y][x]%=mod;
            Z[y][x]%=mod;
            dp[y][x]%=mod;
        }
    }
    //print the answer
    printf("%lld\n",dp[H-1][W-1]%mod);
    return 0;
}