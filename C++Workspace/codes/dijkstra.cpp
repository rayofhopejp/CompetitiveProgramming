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


int N,u,v;
int A[100005],B[100005];

struct dijkstra_normal{
    int V;
    vector<pair<int,int> > *edges;
    dijkstra_normal(int N): V(N){
        edges=new vector<pair<int,int> > [N];
    }
    void push(int a,int b, int c){
        edges[a].pb( mp(b,c) );
    }
    int *solve(int start){
        int *d; 
        d=new int[V];
        priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > q;
        fill(d, d + V, LLINF);
        q.push(mp(0,start));
        d[start]=0;
        while(!q.empty()){
            pair<int,int> p=q.top();q.pop();
            int now=p.second;int cost=p.first;
            if(d[now]<cost)continue;
            rep(e,edges[now].size()){
                int to=edges[now][e].first;int cst=edges[now][e].second;
                if(d[to]>d[now]+cst){
                    d[to]=d[now]+cst;
                    q.push(mp(d[to],to));
                }
            }
        }
        return d;
    }
    void clear(){
        delete[] edges;
    }
};

signed main(){
    scanf("%lld %lld %lld",&N,&u,&v);u--;v--;
    dijkstra_normal dijk(N);
    rep(i,N-1){
        scanf("%lld %lld",&A[i],&B[i]);A[i]--;B[i]--;
        dijk.push(A[i],B[i],1);dijk.push(B[i],A[i],1);
    }
    int ans=0;
    int *d=dijk.solve(v);
    int *d2=dijk.solve(u);
    rep(i,N){
        if(d[i]>=d2[i])ans=max(ans,d[i]);
        //printf("%lld %lld %lld\n",i,d[i],d2[i]);
    }
    printf("%lld\n",ans-1);
    return 0;
}
