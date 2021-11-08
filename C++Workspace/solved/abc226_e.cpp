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
//#define mod 1000000007
#define mod 998244353

int N,M;
bool visited[200005];
vector<int> edge[200005];
int calc_pow(int x, int pow,int m) {
    if (pow == 0) return 1;
    int a = calc_pow(x, pow / 2,m);
    a = a * a % m;
    if (pow % 2 == 1) a *= x;
    return a % m;
}//最小二乗法
pair<int,int> dfs(int now){
    visited[now]=true;
    pair<int,int> p;
    p.first=1;//vertex
    p.second=0;//edge
    for(auto to:edge[now]){
        p.second++;
        if(visited[to])continue;
        pair<int,int> ps;
        ps=dfs(to);
        p.first+=ps.first;
        p.second+=ps.second;
    }
    return p;
}
signed main(){
    scanf("%lld %lld",&N,&M);
    rep(i,M){
        int u,v;
        scanf("%lld %lld",&u,&v);u--;v--;
        edge[u].pb(v);
        edge[v].pb(u);
    }
    //dfsで辺数と頂点数を数えながら連結成分を探す
    int ans=1;
    rep(i,N){
        if(visited[i])continue;
        pair<int,int> p;
        p=dfs(i);
        //printf("%lld %lld/",p.first,p.second);
        if(p.first*2==p.second){
            ans*=2;
            ans%=mod;
        }else{
            ans=0;
            break;
        }
    }
    printf("%lld\n",ans);
    return 0;
}