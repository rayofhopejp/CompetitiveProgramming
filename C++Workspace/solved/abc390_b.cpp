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
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007
//#define mod 998244353

int N;
long long int A[105];
signed main(){
    scanf("%d",&N);
    rep(i,N){
        scanf("%lld",&A[i]);
        if(i>1&&A[i]*A[i-2]!=A[i-1]*A[i-1]){
            printf("No\n");exit(0);
        }
    }
    printf("Yes\n");
}