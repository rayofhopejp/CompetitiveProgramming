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
//https://naoyat.hatenablog.jp/entry/k-dimension-manhattan-distance
int N;
int x[200005],y[200005];
int fx[200005],fy[200005];
signed main(){
    scanf("%lld",&N);
    int fxmax=-LLINF,fxmin=+LLINF;
    int fymax=-LLINF,fymin=+LLINF;
    rep(i,N){
        scanf("%lld %lld",&x[i],&y[i]);
        fx[i]=x[i]-y[i];
        fy[i]=x[i]+y[i];
        fxmax=max(fxmax,fx[i]);
        fxmin=min(fxmin,fx[i]);
        fymax=max(fymax,fy[i]);
        fymin=min(fymin,fy[i]);
    }
    int ans=0;
    ans=max(ans,fxmax-fxmin);//d=0
    ans=max(ans,fymax-fymin);//d=1
    //printf("%lld %lld %lld %lld\n",fxmax,fxmin,fymax,fymin);
    printf("%lld\n",ans);
}