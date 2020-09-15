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
//5で割ってx余る素数を5つ集めれば必ず合成数になる
//また，そのような数をN個集めても55555以下になる．
int N;
//エラトステネスの篩で素数をNまで求める
bool isPrime[60000];
void eratosthenes(int n){
    rep(i,n+1)isPrime[i]=true;
    isPrime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*2;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
}
signed main(){
    scanf("%lld",&N);
    eratosthenes(55555);
    int cnt=0;
    for(int i=7;cnt<N;i+=5){
        if(isPrime[i]){
            printf("%lld",i);
            cnt++;
            if(cnt!=N)printf(" ");
            else printf("\n");
        }
    }
}