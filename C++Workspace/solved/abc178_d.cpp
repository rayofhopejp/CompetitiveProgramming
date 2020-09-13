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

int S;
struct Combination{
    int MAX_N;
    int MOD;
    int *fac, *finv, *inv;
    Combination(int max_n,int MOD): MAX_N(max_n+1),MOD(MOD){ //make table
        fac = new int[MAX_N];finv = new int[MAX_N];inv = new int[MAX_N];
        fac[0]=fac[1]=1;
        finv[0]=finv[1]=1;
        inv[1]=1;
        for (int i = 2; i < MAX_N; i++){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
    int COM(int n,int k){
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
    void free_COM(){
        delete[] fac;
        delete[] finv;
        delete[] inv;
    }
    
};

signed main(){
    scanf("%lld",&S);
    int ans=0;
    Combination comb(S,mod);
    for(int i=1;i<=S;i++){
        int wakeru=S-3*i;
        if(wakeru<0)break;
        if(wakeru==0){ans+=1;continue;}
        //wakeru個をiのグループに分ける(0このグループがあっても良い)
        //wakeruこのoとi-1個の×を並べる並べ方
        int sans=comb.COM(wakeru+i-1,i-1);
        ans+=sans;
        ans%=mod;
    }
    printf("%lld\n",ans%mod);
}