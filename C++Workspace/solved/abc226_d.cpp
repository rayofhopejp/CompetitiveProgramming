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
int x[505],y[505];
int gcd(int a,int b){
    if(a==0||b==0)return max(a,b);
    int mi=min(a,b);int ma=max(a,b);
    int c=ma%mi;
    return gcd(mi,c);
}
signed main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld %lld",&x[i],&y[i]);
    }
    //全ての相違なる街の組(~10^5)に対して座標差x',y'を取り出す
    vector<pair<int,int>> diff;
    rep(i,N){
        rep(j,N){
            if(i==j)continue;
            diff.pb( mp(x[i]-x[j],y[i]-y[j]) );
        }
    }
    //最初の組から順番にx',y'の最大公約数でそれぞれ割ったものを習得(もう習得していたら習得しない)
    set<pair<int,int>> magic;
    rep(i,diff.size()){
        int xs=diff[i].first;
        int ys=diff[i].second;
        int d=gcd(abs(xs),abs(ys));
        magic.insert(mp(xs/d,ys/d));
    }
    printf("%ld\n",magic.size());
    return 0;
}