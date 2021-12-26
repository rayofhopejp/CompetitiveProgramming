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
int A[2005][2005];
int accumH[2005][2005];
int accumW[2005][2005];
int ans[2005][2005];
signed main(){
    scanf("%lld %lld",&H,&W);
    rep(i,H){
        rep(j,W){
            scanf("%lld",&A[i][j]);
        }
    }
    rep(i,H){
        rep(j,W){
            if(i==0){
                accumH[i][j] = A[i][j];
            }else{
                accumH[i][j] = accumH[i-1][j] + A[i][j];
            }
        }
    }
    rep(i,H){
        rep(j,W){
            if(j==0){
                accumW[i][j] = A[i][j];
            }else{
                accumW[i][j] = accumW[i][j-1] + A[i][j];
            }
        }
    }
    rep(i,H){
        rep(j,W){
            ans[i][j] = accumH[H-1][j] + accumW[i][W-1] -A[i][j];
            printf("%lld",ans[i][j]);
            if(j==W-1)printf("\n");
            else printf(" ");
        }
    }
}