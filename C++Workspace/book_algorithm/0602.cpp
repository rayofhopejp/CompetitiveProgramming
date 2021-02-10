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

int N;//100000まで
int a[100005];
int b[100005];
int c[100005];
signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&a[i]);
    rep(i,N)scanf("%lld",&b[i]);
    rep(i,N)scanf("%lld",&c[i]);
    sort(a,a+N);sort(b,b+N);sort(c,c+N);
    int ans=0;
    rep(i,N){
        int x=lower_bound(a,a+N,b[i])-a;
        int y=N-(upper_bound(c,c+N,b[i])-c);
        ans+=x*y;
    }
    printf("%lld\n",ans);
    return 0;
}