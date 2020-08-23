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
int A[100005];
int B[100005];
int ans[100005];
int parent[100005];
int linked[100005];

void init(int N){
    rep(i,N)parent[i]=i;
    rep(i,N)linked[i]=1;
}
int root(int x){
    if(parent[x]==x)return x;
    parent[x]=root(parent[x]);
    return parent[x];
}
int linked_town(int x){
    return linked[parent[x]];
}
int unite(int x,int y){//return "new couple"
    int rx=root(x);
    int ry=root(y);
    if(rx==ry)return 0;
    parent[ry]=rx;//結合
    int newcouple=linked[ry]*linked[rx];
    linked[rx]=linked[ry]+linked[rx];
    return newcouple;
}
signed main(){
    scanf("%lld %lld",&N,&M);
    init(N);
    rep(i,M){scanf("%lld %lld",&A[i],&B[i]);A[i]--;B[i]--;}
    ans[M-1]=N*(N-1)/2;
    for(int i=M-1;i>-1;i--){
        int newcouple=unite(A[i],B[i]);
        ans[i-1]=ans[i]-newcouple;
    }
    rep(i,M)printf("%lld\n",ans[i]);
}