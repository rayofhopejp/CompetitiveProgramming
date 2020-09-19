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

//まだ途中(TLE解法)
int N,Q;
int jtop[200005];
int ileft[200005];
signed main(){
    scanf("%lld %lld",&N,&Q);
    int ans=(N-2)*(N-2);
    rep(i,N)jtop[i]=N;
    rep(i,N)ileft[i]=N;
    rep(i,Q){
        int a,x;
        scanf("%lld %lld",&a,&x);
        if(a==1){//(1,x)において下方向
            ans-=jtop[x]-2;
            for(int t=2;t<jtop[x];t++)ileft[t]=min(ileft[t],x);
        }else{
            ans-=ileft[x]-2;
            for(int t=2;t<ileft[x];t++)jtop[t]=min(jtop[t],x);
        }
    }
    printf("%lld\n",ans);
}