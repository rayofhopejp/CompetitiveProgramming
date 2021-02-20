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
struct Edge{
    int to;
    int cost;
};
vector<Edge>  edges[2005];
int self_edge[2005];//自分同士を繋ぐedgeが存在するかどうか
int dist[2005][2005];
signed main(){
    scanf("%lld %lld",&N,&M);
    rep(i,N)self_edge[i]=LLINF;
    rep(i,M){
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        a--;b--;
        if(a!=b){
            Edge e;e.to=b;e.cost=c;
            edges[a].pb(e);
        }else{
            self_edge[a]=min(self_edge[a],c);//2本以上あるかもしれない（草）
        }
    }
    //ワーシャルフロイド法N^3を使うのは無理
    //dijkstraで行き・帰りの所要時間を求め、街ごとに合計して返す
    //reverse_edgesを使ってもいいけど2回dijkstraすることになるのでこっちでいいかな
    //ただし街iからiへの道がある時はそれについて別に考える
    rep(i,N)rep(j,N)dist[i][j]=LLINF;
    rep(i,N){
        //dijkstra
        priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > que;
        dist[i][i]=0;
        que.push(mp(0,i));
        while(!que.empty()){
            pair<int,int> p=que.top();que.pop();
            int cost=p.first;int now=p.second;
            if(cost>dist[i][now])continue;
            rep(e,edges[now].size()){
                int next=edges[now][e].to;
                int next_cost=cost+edges[now][e].cost;
                if(next_cost<dist[i][next]){
                    dist[i][next]=next_cost;
                    que.push(mp(next_cost,next));
                }
            }
        }
    }
    rep(i,N){
        int ans=self_edge[i];
        rep(j,N){
            if(i==j)continue;
            ans=min(ans,dist[i][j]+dist[j][i]);
        }
        if(ans>=LLINF)printf("-1\n");
        else printf("%lld\n",ans);
    }
}