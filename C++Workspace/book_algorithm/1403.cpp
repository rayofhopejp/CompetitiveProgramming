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

//atcoder beginner contest 132 E
template<class T> bool chmin(T& a,T b){
    if(a>b){
        a=b;
        return true;
    }else return false;
}
int N,M;
vector<int> edges[100005];
int dist[100005][5];
int S,T;
signed main(){
    scanf("%lld %lld",&N,&M);
    rep(i,N)rep(j,3)dist[i][j]=LLINF;
    rep(i,M){
        int u,v;
        scanf("%lld %lld",&u,&v);
      	u--;v--;
        edges[u].pb(v);
    }
    scanf("%lld %lld",&S,&T);S--;T--;
    queue<pair<int,int> > que;
    dist[S][0]=0;
    que.push(mp(S,0));
    while(!que.empty()){
        pair<int,int> p=que.front();que.pop();
        int now=p.first;int cost=p.second;
        if(dist[now][cost%3]<cost)continue;
        for(auto to:edges[now]){
            if(chmin(dist[to][(cost+1)%3],cost+1)){
                que.push(mp(to,cost+1));
            }
        }
    }
    if(dist[T][0]==LLINF)printf("-1\n");
    else printf("%lld\n",dist[T][0]/3);
    return 0;
}