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

int N,M,X,Y;
struct Edge{
    int to;
    int clock;
    int cost;
};
vector<Edge> edges[100005];
int dist[100005];
signed main(){
    scanf("%lld %lld %lld %lld",&N,&M,&X,&Y);
    X--;Y--;
    rep(i,N)dist[i]=LLINF;
    rep(i,M){
        int a,b,t,k;
        scanf("%lld %lld %lld %lld",&a,&b,&t,&k);
        a--;b--;
        Edge e;
        e.to=b;e.clock=k;e.cost=t;
        edges[a].pb(e);
        e.to=a;
        edges[b].pb(e);
    }
    //dijkstra
    priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > que;
    dist[X]=0;
    que.push(mp(0,X));
    while(!que.empty()){
        pair<int,int> p=que.top();que.pop();
        int cost=p.first;int now=p.second;
        if(cost>dist[now])continue;
        rep(e,edges[now].size()){
            int next=edges[now][e].to;
            int next_cost=cost+edges[now][e].cost;
            int clock=edges[now][e].clock;
            //%clock=0にならないと乗れない
            if(cost%clock)next_cost+=clock-(cost%clock);
            if(next_cost<dist[next]){
                dist[next]=next_cost;
                que.push(mp(next_cost,next));
            }
        }
    }
    if(dist[Y]>=LLINF)printf("-1\n");
    else printf("%lld",dist[Y]);
}