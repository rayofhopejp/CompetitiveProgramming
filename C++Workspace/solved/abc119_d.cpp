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

int A,B,Q;
int s[100005];
int t[100005];
int x[100005];
signed main(){
    scanf("%lld %lld %lld",&A,&B,&Q);
    rep(i,A)scanf("%lld",&s[i]);
    rep(i,B)scanf("%lld",&t[i]);
    rep(i,Q){
        scanf("%lld",&x[i]);
        int si2=lower_bound(s,s+A,x[i])-s;//右にある神社のイテレータ
        int si1=si2-1;//左にある神社のイテレータ
        int s1,s2;
        if(si1<0)s1=-LLINF;//左に神社がない
        else s1=s[si1];
        if(si2>=A)s2=LLINF;//右に神社がない
        else s2=s[si2];

        int ti2=lower_bound(t,t+B,x[i])-t;//右にある寺のイテレータ
        int ti1=ti2-1;//左にある寺のイテレータ
        int t1,t2;
        if(ti1<0)t1=-LLINF;//左に寺がない
        else t1=t[ti1];
        if(ti2>=B)t2=LLINF;//右に寺がない
        else t2=t[ti2];

        //printf("[%lld %lld %lld %lld]\n",t1,t2,s1,s2);
        int ans=LLINF;
        ans=min(ans,x[i]-min(t1,s1));//ずっと左に行く
        ans=min(ans,max(t2,s2)-x[i]);//ずっと右に行く
        ans=min(ans,x[i]-t1+s2-t1);//寺は左、神社は右(1)
        ans=min(ans,s2-x[i]+s2-t1);//寺は左、神社は右(2)
        ans=min(ans,x[i]-s1+t2-s1);//寺は右、神社は左(1)
        ans=min(ans,t2-x[i]+t2-s1);//寺は右、神社は左(2)
        printf("%lld\n",ans);
    }
}