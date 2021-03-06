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

int A,B;
signed main(){
    scanf("%lld %lld",&A,&B);
    if(A+B>=15&&B>=8)printf("1\n");
    else if(A+B>=10&&B>=3)printf("2\n");
    else if(A+B>=3)printf("3\n");
    else printf("4\n");
    return 0;
}