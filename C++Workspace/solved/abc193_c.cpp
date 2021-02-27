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
bool ifuse[200005];
signed main(){
    scanf("%lld",&N);
    int revans=0;
    for(int a=2;a*a<=N;a++)ifuse[a]=false;
    for(int a=2;a*a<=N;a++){
        if(ifuse[a])continue;
        int rem=a;
         for(int b=2;true;b++){
             if(rem>N/a+1)break;
             if(rem*a>N)break;
             rem*=a;
             if(rem<=100000)ifuse[rem]=true;
             revans++;
        }
    }
    printf("%lld\n",N-revans);
}