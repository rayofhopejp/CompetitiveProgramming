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

int N,K;

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
    scanf("%lld %lld",&N,&K);
    Combination CMB(N,mod);
    int ans=0;
    rep(i,min(K+1,N)){//0の部屋はK個またはN-1個まで
        ans+=(CMB.COM(N,i)*CMB.COM(N-1,i))%mod;
        ans%=mod;
    }
    printf("%lld\n",ans);
    CMB.free_COM();
    return 0;
}