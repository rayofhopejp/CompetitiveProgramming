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

int a,b,c,d;
signed main(){
    scanf("%lld %lld",&a,&b);
    scanf("%lld %lld",&c,&d);
    int ans=b-c;
    printf("%lld\n",ans);
}