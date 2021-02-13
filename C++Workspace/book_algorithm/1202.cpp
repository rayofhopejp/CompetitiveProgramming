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

int N,M;
vector<pair<int,int> > AB;
signed main(){
    scanf("%lld %lld",&N,&M);
    rep(i,N){
        int a,b;
        scanf("%lld %lld",&a,&b);
        AB.pb(mp(a,b));
    }
    sort(AB.begin(),AB.end());
    int ans=0;
    int cnt=0;
    int itr=0;
    while(cnt<M){
        int buy=AB[itr].second;
        if(buy>M-cnt)buy=M-cnt;
        ans+=AB[itr].first*buy;
        cnt+=buy;itr++;
    }
    printf("%lld\n",ans);
    return 0;
}