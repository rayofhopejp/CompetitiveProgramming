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
//ソートして上から取ることでパターンごとのNlogNにできる．
//当たり前だが重さが全部1であるようなナップサックはソートで解けるので二度手間しないように注意
//ちなみにソートした時に上からM番目をO(N)で探すこともできる
int N,M;
int xyz[3][1005];
int dp[10][1005][1005];
signed main(){
    scanf("%lld %lld",&N,&M);
    rep(i,N){
        scanf("%lld %lld %lld",&xyz[0][i],&xyz[1][i],&xyz[2][i]);
    }
    rep(p,8)rep(i,N+1)rep(j,M+1)dp[p][i][j]=-LLINF;
    rep(p,8)dp[p][0][0]=0;
    rep(p,8){
        rep(i,N){
            int plus=0;
            rep(t,3){
                if((p>>t)%2==1)plus+=xyz[t][i];
                else plus-=xyz[t][i];
            }
            rep(j,M+1){
                //itr=iのケーキを食べる   
                dp[p][i+1][j+1]=max(dp[p][i+1][j+1],dp[p][i][j]+plus);
                //itr=iのケーキを食べない
                dp[p][i+1][j]=max(dp[p][i+1][j],dp[p][i][j]);
            }
        }
    }
    int ans=-LLINF;
    rep(p,8)ans=max(ans,dp[p][N][M]);
    printf("%lld\n",ans);
}
