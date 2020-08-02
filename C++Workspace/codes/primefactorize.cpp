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
#define MOD 1000000007



int N;
int A[10009];
map<int,int> P[10009];
map<int,int> L;

//素因数分解
map<int,int> PrimeF(int N){
    int M=N;
    map<int,int> ret;
    for(int i=2;i<sqrt(N)+1;i++){
        int cnt=0;
        while(M%i==0){
            M/=i;
            cnt++;
        }
        if(cnt>0)ret[i]=cnt;
        if(cnt>0&&cnt>L[i])L[i]=cnt;//この問題でだけ使う
    }
    if(M!=1)ret[M]=1;
    if(M!=1&&1>L[M])L[M]=1;//この問題でだけ使う
    return ret;
}

int calc_pow(int x, int pow) {
    if (pow == 0) return 1;
    int a = calc_pow(x, pow / 2);
    a = a * a % MOD;
    if (pow % 2 == 1) a *= x;
    return a % MOD;
}
int calc_div(int a,int b) {
    return a * calc_pow(b, MOD - 2) % MOD;
}

signed main(){
    scanf("%lld",&N);
    int maxA=0;
    rep(i,N){
        scanf("%lld",&A[i]);
         P[i]=PrimeF(A[i]);
         if(A[i]>maxA)maxA=A[i];
    }
    int l=1;
    int ans=0;
    for(auto itr = L.begin(); itr != L.end(); ++itr) {
        l*=calc_pow(itr->first,itr->second);
        l%=MOD;
    }
    rep(i,N){
        ans+=calc_div(l,A[i]);
        ans%=MOD;
    }
    printf("%lld\n",ans);
    return 0;
}
