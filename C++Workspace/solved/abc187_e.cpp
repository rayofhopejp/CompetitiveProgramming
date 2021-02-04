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

int N,Q;
int a[200005],b[200005];
vector<int> edges[200005];
int parent[200005];
int cost[200005];
signed main(){
    scanf("%lld",&N);
    rep(i,N)cost[i]=0;
    rep(i,N-1){
        scanf("%lld %lld",&a[i],&b[i]);a[i]--;b[i]--;
        edges[a[i]].push_back(b[i]);
        edges[b[i]].push_back(a[i]);
    }
    //祖先と子孫の方向を決める
    queue<int> que;
    que.push(0);
    rep(i,N)parent[i]=-1;
    parent[0]=0;
    while(!que.empty()){
        int n=que.front();que.pop();
        rep(i,edges[n].size()){
            if(parent[edges[n][i]]!=-1)continue;
            parent[edges[n][i]]=n;
            que.push(edges[n][i]);
        }
    }
    scanf("%lld",&Q);
    rep(i,Q){
        int t,e,x;
        int p,q;
        scanf("%lld %lld %lld",&t,&e,&x);
        e--;
        if(t==1){//a[e]から辺を辿ってb[e]を通らずに到達できる頂点はc=c+xにする
            p=a[e];q=b[e];
        }else{
            p=b[e];q=a[e];
        }
        if(parent[p]==q){//子孫にp,祖先にqがある時
            cost[p]+=x;
        }else{//子孫にq,祖先にpがある時
            cost[0]+=x;
            cost[q]-=x;
        }
    }
    //rep(i,N)printf("%lld:%lld\n",i+1,cost[i]);
    //祖先からたどる
    que.push(0);
    while(!que.empty()){
        int n=que.front();que.pop();
        rep(i,edges[n].size()){
            if(parent[n]==edges[n][i])continue;//親方向には行かない
            cost[edges[n][i]]+=cost[n];
            que.push(edges[n][i]);
        }
    }
    rep(i,N)printf("%lld\n",cost[i]);
}