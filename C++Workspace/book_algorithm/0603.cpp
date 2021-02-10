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

int N;//1000まで
int M;
int a[1005];
vector<int> aa;
signed main(){
    scanf("%lld %lld",&N,&M);
    rep(i,N)scanf("%lld",&a[i]);
    a[N]=0;//投げない
    rep(i,N+1){
        for(int j=i;j<=N;j++){
            aa.pb(a[i]+a[j]);
        }
    }
    sort(aa.begin(),aa.end());
    int ans=0;
    rep(i,aa.size()){
        int a1=aa[i];
        int itr=upper_bound(aa.begin(),aa.end(),M-a1)-aa.begin()-1;
        if(itr<0)continue;
        ans=max(ans,a1+aa[itr]);
    }
    printf("%lld\n",ans);
    return 0;
}