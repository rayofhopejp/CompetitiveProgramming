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
vector<int> edges[100100];
pair<int,int> dfs(int n,int p){
    int longest=0;
    int seclongest=0;
    int ans=0;
    for(auto e:edges[n]){
        if(e==p)continue;
        auto ret = dfs(e,n);
        if(ret.first>=longest){
            seclongest=longest;
            longest = ret.first;
        }else if(ret.first>=seclongest){
            seclongest = ret.first;
        }
        ans=max(ans,ret.second);
    }
    return mp(longest+1,max(ans,longest+seclongest+1));
}
signed main(){
    scanf("%lld",&N);
    rep(i,N-1){
        int a,b;
        scanf("%lld %lld",&a,&b);
        a--;b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    auto ret = dfs(0,-1);
    printf("%lld\n",ret.second);
}