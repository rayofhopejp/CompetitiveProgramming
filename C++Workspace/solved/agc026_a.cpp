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
int a[105];
signed main(){
    scanf("%lld",&N);
    for(int i=0;i<N;i++){scanf("%lld",&a[i]);}
    int ans = 0;
    int num=1;
    for(int i=1;i<N;i++){
        if(a[i]==a[i-1])num++;
        else{
            ans += num/2;
            num=1;
        }
    }
    ans += num/2;
    printf("%lld\n",ans);
}