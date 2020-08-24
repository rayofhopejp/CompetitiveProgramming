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

int N,A,B,C;
int l[10];
signed main(){
    scanf("%lld %lld %lld %lld",&N,&A,&B,&C);
    rep(i,N)scanf("%lld",&l[i]);
    int ans=INF;
    rep(i,1<<2*N){
        int matsu[10];//0の時使わない、1の時A、2の時B、3の時C
        int a=0,b=0,c=0;
        int i_=i;
        int sans=-30;
        rep(j,N){
            matsu[j]=i_%4;
            if(matsu[j]==1){a+=l[j];sans+=10;}
            if(matsu[j]==2){b+=l[j];sans+=10;}
            if(matsu[j]==3){c+=l[j];sans+=10;}
            i_/=4;
        }
        if(a==0||b==0||c==0)continue;
        sans+=abs(a-A);
        sans+=abs(b-B);
        sans+=abs(c-C);
        ans=min(ans,sans);
    }
    printf("%lld\n",ans);
}