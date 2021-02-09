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
//abc189_e
int N,M,Q;
int X[200005],Y[200005];
//行列
int G[200005][3][3];
//累乗積
int GA[200005][3][3];
signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld %lld",&X[i],&Y[i]);
    scanf("%lld",&M);
    rep(i,M){
        rep(j,3)rep(k,3)G[i][j][k]=0;
        int op;
        scanf("%lld",&op);
        if(op==1){
            G[i][0][1]=1;
            G[i][1][0]=-1;
            G[i][2][2]=1;
        }else if(op==2){
            G[i][0][1]=-1;
            G[i][1][0]=1;
            G[i][2][2]=1;
        }else if(op==3){
            int p;
            scanf("%lld",&p);
            G[i][0][0]=-1;
            G[i][0][2]=2*p;
            G[i][1][1]=1;
            G[i][2][2]=1;
        }else{
            int p;
            scanf("%lld",&p);
            G[i][0][0]=1;
            G[i][1][1]=-1;
            G[i][1][2]=2*p;
            G[i][2][2]=1;
        }
    }
    //行列の累乗積を計算
    rep(i,M){
        rep(j,3){
            rep(k,3){
                //GA[i][j][k]を求める
                if(i==0)GA[i][j][k]=G[i][j][k];
                else{
                    int sum=0;
                    rep(m,3)sum+=G[i][j][m]*GA[i-1][m][k];
                    GA[i][j][k]=sum;
                }
            }
        }
    }
    scanf("%lld",&Q);
    rep(i,Q){
        int a,b;
        scanf("%lld %lld",&a,&b);a--;b--;
        if(a==-1){//そのまま
            printf("%lld %lld\n",X[b],Y[b]);
            continue;
        }
        int x=GA[a][0][0]*X[b]+GA[a][0][1]*Y[b]+GA[a][0][2];
        int y=GA[a][1][0]*X[b]+GA[a][1][1]*Y[b]+GA[a][1][2];
        printf("%lld %lld\n",x,y);
    }
}