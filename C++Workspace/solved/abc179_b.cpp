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
    int cnt=0;
    rep(i,N){
        int d1,d2;
        scanf("%lld %lld",&d1,&d2);
        if(d1==d2){
            cnt+=1;
        }else cnt=0;
        if(cnt==3){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}