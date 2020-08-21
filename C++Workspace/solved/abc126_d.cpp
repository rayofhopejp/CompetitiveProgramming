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
vector<pair<int,int> > edges[100005];
int ans[100005];
signed main(){
    scanf("%lld",&N);
    rep(i,N-1){
        int u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);u--;v--;
        edges[u].pb(mp(v,w));
        edges[v].pb(mp(u,w));
    }
    rep(i,N)ans[i]=-1;
    queue<int> q;
    q.push(0);
    ans[0]=0;
    while(!q.empty()){
        int v=q.front();q.pop();
        rep(e,edges[v].size()){
            int nv=edges[v][e].first;
            int nc=edges[v][e].second;
            if(ans[nv]>(int)-1)continue;
            ans[nv]=(ans[v]+nc)%2;
            q.push(nv);
        }
    }
    rep(i,N){
        printf("%lld\n",ans[i]);
    }
    return 0;
}