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
int A[1005],B[1005];
signed main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld %lld",&A[i],&B[i]);
    }
    int ans=LLINF;
    rep(i,N){
        rep(j,N){
            if(i==j)ans=min(ans,A[i]+B[j]);
            else ans=min(ans,max(A[i],B[j]));
        }
    }
    printf("%lld\n",ans);
}