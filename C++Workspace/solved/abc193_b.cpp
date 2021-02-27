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
int A[100005],P[100005],X[100005];
signed main(){
    scanf("%lld",&N);
    int ans=LLINF;
    rep(i,N){
        scanf("%lld %lld %lld",&A[i],&P[i],&X[i]);
        if(A[i]<X[i])ans=min(ans,P[i]);
    }
    if(ans==LLINF)printf("-1\n");
    else printf("%lld\n",ans);
}