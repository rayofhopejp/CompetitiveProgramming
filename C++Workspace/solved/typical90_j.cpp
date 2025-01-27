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

int N,Q;
int sum0[100005];
int sum1[100005];
signed main(){
    scanf("%lld",&N);
    rep(i,N+1)sum0[i]=sum1[i]=0;
    rep(i,N){
        int c,p;
        scanf("%lld %lld",&c,&p);
        if(c==1)sum0[i]=p;
        else sum1[i]=p;
    }
    for(int i=1;i<N+1;i++){
        sum0[i]+=sum0[i-1];
        sum1[i]+=sum1[i-1];
    }
    scanf("%lld",&Q);
    rep(i,Q){
        int L,R;
        scanf("%lld %lld",&L,&R);
        L--;R--;
        printf("%lld %lld\n",sum0[R]-((L<1)?0:sum0[L-1]),sum1[R]-((L<1)?0:sum1[L-1]));
    }
}