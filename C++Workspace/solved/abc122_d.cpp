#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
#include<map>
 
//解説
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

signed main(){
    scanf("%lld",&N);
    int ans=0;
    int dp[105][64+5];
    rep(i,N){
        rep(j,64){
            int one=j%4;
            int two=(j/4)%4;
            int thr=(j/16)%4;
            dp[i][j]=0;
            if(i==0){
                if(two==3&&thr==3)dp[i][j]=1;
            }else{
                rep(k,64){
                    int one_=k%4;
                    int two_=(k/4)%4;
                    int thr_=(k/16)%4;
                    if(one_==two&&two_==thr){
                        if(thr==0&&two==1&&one==2)continue;//AGC
                        if(thr==0&&two==2&&one==1)continue;//ACG
                        if(thr==1&&two==0&&one==2)continue;//GAC
                        if(thr_==0&&two==1&&one==2)continue;//AxGC
                        if(thr_==0&&thr==1&&one==2)continue;//AGxC
                        dp[i][j]+=dp[i-1][k]%mod;
                        dp[i][j]%=mod;
                    }   
                }
            }
        }
    }
    rep(i,64){
        ans+=dp[N-1][i];
        ans%=mod;
    }
    printf("%lld\n",ans);
}