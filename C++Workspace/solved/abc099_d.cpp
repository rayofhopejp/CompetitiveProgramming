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

int N,C;
int D[35][35];
int c[505][505];
int memo[3][30];
signed main(){
    scanf("%lld %lld",&N,&C);
    rep(i,C)rep(j,C)scanf("%lld",&D[i][j]);
    rep(k,3)rep(i,C)memo[k][i]=0;
    rep(i,N)rep(j,N){
        scanf("%lld",&c[i][j]);c[i][j]--;
        int k=(i+j)%3;
        rep(color,C){
            memo[k][color]+=D[c[i][j]][color];
        }
    }
    vector<int> anss;
    int ans=LLINF;
    rep(i,C){
        rep(j,C){
            if(i==j)continue;
            rep(k,C){
                if(k==i||k==j)continue;
                anss.pb(memo[0][i]+memo[1][j]+memo[2][k]);
            }
        }
    }
    rep(i,anss.size()){
        ans=min(ans,anss[i]);
    }
    printf("%lld\n",ans);
}