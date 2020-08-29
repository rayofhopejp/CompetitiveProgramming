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
int A[200005];
int R[200005];
signed main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld",&A[i]);
        if(i==0)R[i]=A[i];
        else R[i]=R[i-1]+A[i];
        R[i]%=mod;
    }
    int ans=0;
    for(int i=N;i>=1;i--){
        ans+=R[i-1]*A[i];
        ans%=mod;        
    }
    printf("%lld\n",ans);
}