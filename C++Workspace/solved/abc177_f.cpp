//未解決
//TLE
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


int H,W;
int A[200005],B[200005];
int ans[200005];
signed main(){
    scanf("%lld %lld ",&H,&W);
    rep(i,H){
        scanf("%lld %lld",&A[i],&B[i]);A[i]--;B[i]--;
        ans[i]=LLINF;
    }
    rep(j,W){
        int now_w=j;
        int cnt=0;
        rep(i,H){
            if(now_w>=A[i]&&now_w<=B[i]){
                cnt+=B[i]+1-now_w;
                now_w=B[i]+1;
            }
            cnt+=1;
            if(now_w<W){
                ans[i]=min(ans[i],cnt);
            }else{
                break;
            }
            
        }
    }
    rep(i,H){
        if(ans[i]>=LLINF)printf("-1\n");
        else printf("%lld\n",ans[i]);
    }
}