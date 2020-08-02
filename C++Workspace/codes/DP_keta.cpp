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

char L[100005];
int dp1[100005];
int dp2[100005];
signed main(){
    scanf("%s",L);
    int Ll=strlen(L);
    dp1[0]=2;//一番上の桁が1
    dp2[0]=1;//一番上の桁が0(確定)
    for(int i=1;i<Ll;i++){
        if(L[i]=='0'){
            //A XOR B = 0 <=> A=0,B=0
            dp1[i]+=dp1[i-1];
            dp2[i]+=dp2[i-1];
            //A XOR B = 1 //dp1は超えちゃうからだめ
            dp2[i]+=dp2[i-1]*2;
        }else{
            //A XOR B =0 //dp1にはならない
            dp2[i]+=dp1[i-1]+dp2[i-1];
            //A XOR B = 1
            dp1[i]+=dp1[i-1]*2;
            dp2[i]+=dp2[i-1]*2;
        }
        dp1[i]%=mod;
        dp2[i]%=mod;
        //rintf("%lld/%lld-",dp1[i],dp2[i]);

    }
    printf("%lld",(dp2[Ll-1]+dp1[Ll-1])%mod);
    return 0;
}
