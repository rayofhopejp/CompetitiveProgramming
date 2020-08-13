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

char S[100005];
int dp[100005][15];
signed main(){
    scanf("%s",S);
    int N=strlen(S);
    for(int i=N-1;i>=0;i--){
        rep(j,13){
            int num=S[i]-'0';
            int keta=N-1-i;
            int mod10keta=1;
            rep(k,keta%12)mod10keta=mod10keta*10%13;
            mod10keta%=13;
            if(i==N-1){
                if(S[i]=='?'){
                    if(j<10)dp[i][j]=1;
                }else{
                    if(num==j)dp[i][j]=1;
                }
            }else{
                if(S[i]=='?'){
                    rep(k,10)dp[i][j]+=dp[i+1][((j-k*mod10keta)%13+13)%13];
                }else{
                    dp[i][j]+=dp[i+1][((j-num*mod10keta)%13+13)%13];
                }
            }
            dp[i][j]%=mod;
        }
    }
    printf("%lld\n",dp[0][5]);
    return 0;
}