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

//解説
//ソートして上から取ることでパターンごとのNlogNにできる．
//当たり前だが重さが全部1であるようなナップサックはソートで解けるので二度手間しないように注意
//ちなみにソートした時に上からM番目をO(N)で探すこともできる
int N,M;
int xyz[3][1005];
signed main(){
    scanf("%lld %lld",&N,&M);
    rep(i,N){
        scanf("%lld %lld %lld",&xyz[0][i],&xyz[1][i],&xyz[2][i]);
    }
    int ans=-LLINF;
    rep(p,8){
        int plus[1005];
        rep(i,N){
            plus[i]=0;
            rep(t,3){
                if((p>>t)%2==1)plus[i]+=xyz[t][i];
                else plus[i]-=xyz[t][i];
            }
        }
        sort(plus,plus+N,greater<int>());
        int sans=0;
        rep(i,M)sans+=plus[i];
        ans=max(ans,sans);
    }
    printf("%lld\n",ans);
}