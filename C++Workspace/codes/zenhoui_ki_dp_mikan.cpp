#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
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

//https://atcoder.jp/contests/abc160/tasks/abc160_f

int calc_pow(int x, int pow,int m) {
    if (pow == 0) return 1;
    int a = calc_pow(x, pow / 2,m);
    a = a * a % m;
    if (pow % 2 == 1) a *= x;
    return a % m;
}//最小二乗法


int calc_div(int a,int b,int m) {
    return a * calc_pow(b, m - 2,m) % m;
}//フェルマーの小定理


int N;
int a[200010];
int b[200010];
vector<int> edges[200010]; //隣接している頂点の配列


//0をrootとした時の部分木sizeを求めるDFS
int siz[200010];
void DFS1(int n,int p){
    for(int to:edges[n]){
        if(to==p)continue;
        DFS1(to,n);
        siz[n]+=siz[to];
    }
    siz[n]++;
}
//答えを求めるDFS
int ans[200010];
void DFS2(int n,int p){
    ans[n]=sum;
    for(int to:edges[n]){
        if(to==p)continue;
        int a=siz[n],b=siz[to],c=sum;

        sum*=siz[to];
        sum%=mod;

        siz[n]-=siz[to];
        sum*=calc_pow(siz[n],mod-2,mod);
        sum%=mod;
        siz[to]=a;

        DFS2(to,n);

    }
}
signed main(){
    scanf("%lld",&N);
    rep(i,N-1){
        scanf("%lld %lld",&a[i],&b[i]);
        a[i]--;b[i]--;
        edges[a[i]].pb(b[i]);
        edges[b[i]].pb(a[i]);
        //隣接している頂点にとって、自分が何番目の隣接点なのかを求める
        indexForAdjacents[a[i]].pb(edges[b[i]].size()-1);
        indexForAdjacents[b[i]].pb(edges[a[i]].size()-1);
    }
    DFS1(0,-1);//sizeを求めるdfs
    DFS2(0,-1);//答えを求めるdfs
    return 0;
}
