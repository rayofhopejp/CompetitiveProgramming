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

int X,K,D;
signed main(){
    scanf("%lld %lld %lld",&X,&K,&D);
    X=abs(X);
    int kaisu=X/D;
    if(kaisu>K){printf("%lld\n",X-D*K);return 0;}
    int d=X-kaisu*D;
    int ans=0;
    if((K-kaisu)%2==1)ans=D-d;
    else ans=d;
    printf("%lld\n",ans);return 0;
    return 0;
}