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
int R[200005];
signed main(){
    scanf("%lld %lld",&N,&Q);
    rep(i,N)scanf("%lld",&R[i]);
    sort(R,R+N);
    vector<int> required_raindeer(N+1);
    required_raindeer[0]=0;
    for(int i=1;i<=N;i++){
        required_raindeer[i]=required_raindeer[i-1]+R[i-1];
    }
    rep(i,Q){
        int X;
        scanf("%lld",&X);
        auto position=upper_bound(required_raindeer.begin(),required_raindeer.end(),X);
        int idx=distance(required_raindeer.begin(),position);
        printf("%lld\n",idx-1);
    }
    
}