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

struct Edge{
    int from;
    int to;
    int cost;
};
template<class T> bool chmin(T& a,T b){
    if(a>b){
        a=b;
        return true;
    }else return false;
}
int N,M;
vector<Edge> edges;
int dist[1005];
signed main(){
    scanf("%lld %lld",&N,&M);
    rep(i,M){
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        a--;b--;
        Edge e;e.from=a;e.to=b;e.cost=-c;
        edges.pb(e);
    }
    //ベルマンフォード法
    rep(i,N)dist[i]=LLINF;
    dist[0]=0;
    bool exits_nagative_cycle=false;
    rep(v,N){
        int isupdate=false;
        for(auto e:edges){
            //辺に対して緩和
            if(dist[e.from]!=LLINF&&chmin(dist[e.to],dist[e.from]+e.cost)){
                isupdate=true;
            }
        }
        if(!isupdate)break;
        if(v==N-1&&isupdate)exits_nagative_cycle=true;
    }
    if(!exits_nagative_cycle){
        printf("%lld\n",-dist[N-1]);
        return 0;
    }
    //始点から終点に向かう経路の中にその負の閉路があるか？
    bool exits_negative_cycle_in_route=false;
    rep(v,N){
        for(auto e:edges){
            //辺に対して緩和
            if(dist[e.from]!=LLINF&&chmin(dist[e.to],dist[e.from]+e.cost)){
                if(e.to==N-1)exits_negative_cycle_in_route=true;
            }
        }
        if(exits_negative_cycle_in_route)break;
    }
    if(exits_negative_cycle_in_route)printf("inf\n");
    else printf("%lld\n",-dist[N-1]);
    return 0;
}