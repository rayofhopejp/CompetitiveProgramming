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
const int MAX_N=100000;
void dfs(int x,int *C,vector<int> *edges,bool *visited,int *color_times,vector<int> *ans){
    color_times[C[x]]+=1;
    visited[x]=true;
    for(auto e:edges[x]){
        if(!visited[e])dfs(e,C,edges,visited,color_times,ans);
    }
   if(color_times[C[x]]==1)ans->push_back(x);
   color_times[C[x]]-=1;
   return;
}
int C[MAX_N];//color
vector<int> edges[MAX_N];//edges
bool visited[MAX_N];
int color_times[MAX_N];
signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&C[i]);
    rep(i,N-1){
        int a,b;
        scanf("%lld %lld",&a,&b);a--;b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    vector<int> ans;
    dfs(0,C,edges,visited,color_times,&ans);
    sort(ans.begin(),ans.end());
    for(auto a:ans){
        printf("%lld\n",a+1);
    }
}
