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

char S[200010];
int N,A,B;

int calc_pow(int x, int pow,int m) {
    if (pow == 0) return 1;
    int a = calc_pow(x, pow / 2,m);
    a = a * a % m;
    if (pow % 2 == 1) a *= x;
    return a % m;
}//最小二乗法

int calc_div(int a,int b,int m) {
    return a * calc_pow(b, m - 2,m) % m;
}//フェルマーの小定理

signed main(){
    scanf("%lld %lld %lld",&N,&A,&B);
    int ans=0;
    ans+=(calc_pow(2,N,mod)-1)%mod;
    int X=1,Y=1;
    for(int i=1;i<=A;i++){
        X*=i;X%=mod;
        Y*=(N-i+1);Y%=mod;
    }
    ans-=calc_div(Y,X,mod);
    ans=(ans+mod)%mod;
    X=1,Y=1;
    for(int i=1;i<=B;i++){
        X*=i;X%=mod;
        Y*=(N-i+1);Y%=mod;
    }
    ans-=calc_div(Y,X,mod);
    ans=(ans+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}
