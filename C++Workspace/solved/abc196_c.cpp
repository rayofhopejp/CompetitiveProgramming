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

int N;
int keta(int i){
    int cnt=0;
    while(i>0){
        i/=10;
        cnt++;
    }
    return cnt;
}
signed main(){
    scanf("%lld",&N);
    //何桁か数える
    int n=N;
    int cnt=0;
    while(n>0){
        n/=10;
        cnt++;
    }
    int ans=0;
    ////10^6以下なので間に合う
    for(int i=1;i+i*pow(10,keta(i))<=N;i++){
        ans++;
    }
    printf("%lld\n",ans);
    
}