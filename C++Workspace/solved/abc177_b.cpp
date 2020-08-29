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

char S[1005],T[1005];
signed main(){
    scanf("%s",S);
    scanf("%s",T);
    int SN=strlen(S);
    int TN=strlen(T);
    int ans=INF;
    rep(i,SN-TN+1){
        int sans=0;
        rep(j,TN){
            if(S[i+j]!=T[j]){
                sans+=1;
            }
        }
        ans=min(ans,sans);
    }
    printf("%lld\n",ans);
}