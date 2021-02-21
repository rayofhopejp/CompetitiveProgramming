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
//#define mod 1000000007
#define mod 998244353

int N,M,K;
int calc_pow(int x, int pow,int m) {
    if (pow == 0) return 1;
    int a = calc_pow(x, pow / 2,m);
    a = a * a % m;
    if (pow % 2 == 1) a *= x;
    return a % m;
}//最小二乗法
signed main(){
    scanf("%lld %lld %lld",&N,&M,&K);
    int ans=0;
    if(N==1&&M==1){
        printf("%lld\n",K);
        return 0;
    }else if(N==1||M==1){
        //A_imin==B_imin
        for(int i=1;i<=K;i++){
        ans+=((calc_pow(K-i+1,M,mod)-calc_pow(K-i+1-1,M,mod))*(calc_pow(i,N,mod)-calc_pow(i-1,N,mod)))%mod;
        ans%=mod;
        }
        printf("%lld\n",(ans+mod)%mod);
        return 0;
    }
    //A_imax<=B_imin
    for(int i=1;i<=K;i++){
        ans+=(calc_pow(K-i+1,M,mod)*(calc_pow(i,N,mod)-calc_pow(i-1,N,mod)))%mod;
        ans%=mod;
    }
    printf("%lld\n",(ans+mod)%mod);
}