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
signed main(){
    scanf("%lld",&N);
    int ans=0;
    for(int A=1;A<=N-1;A++){
        int B=(int)(N-1)/A;
        ans+=B;
    }
    printf("%lld\n",ans);
}