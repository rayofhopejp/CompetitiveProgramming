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
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007
//#define mod 998244353

int N,M;
char S[55][55];
char T[55][55];
signed main(){
    scanf("%d %d",&N,&M);
    rep(i,N)scanf("%s",&S[i]);
    rep(i,M)scanf("%s",&T[i]);
    for(int a=0;a<N-M+1;a++){
        for(int b=0;b<N-M+1;b++){
            bool ok=true;
            rep(i,M)rep(j,M){
                if(S[a+i][b+j]==T[i][j])continue;
                else{ok=false;}
            }
            if(ok){
                printf("%d %d\n",a+1,b+1);
                exit(0);
            }
        }
    }
}