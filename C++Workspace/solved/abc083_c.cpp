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

int X,Y;
signed main(){
    scanf("%lld %lld",&X,&Y);
    int now=X;
    int ans=0;
    while(now<=Y){
        now*=2;
        ans++;
    }
    printf("%lld\n",ans);
}