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

int N;//number of balls
const int MAX_N=200000;
int X[MAX_N];//place
int C[MAX_N];//color
int MINMAX_X[MAX_N+2][2];//the most left/right ball of color i, initialized by inf/-inf

signed main(){
    scanf("%lld",&N);
    rep(i,N+1){
        MINMAX_X[i][0]=LLINF;
        MINMAX_X[i][1]=-LLINF;
    }
    rep(i,N){
        scanf("%lld %lld",&X[i],&C[i]);
        MINMAX_X[C[i]][0]=min(MINMAX_X[C[i]][0],X[i]);
        MINMAX_X[C[i]][1]=max(MINMAX_X[C[i]][1],X[i]);
    }
    int score[2]={0,0};
    for(int i=0;i<2;i++){
        MINMAX_X[0][i]=0;
        MINMAX_X[N+1][i]=0;
    }
    int prev_i=0;
    for(int i=1;i<N+2;i++){
        if(MINMAX_X[i][0]==LLINF||MINMAX_X[i][1]==-LLINF)continue;
        int next_score[2]={+LLINF,+LLINF};
        for(int now=0;now<2;now++){
            for(int prev=0;prev<2;prev++){
                int s=score[prev]+abs(MINMAX_X[i][now]-MINMAX_X[prev_i][(prev+1)%2])+abs(MINMAX_X[i][1]-MINMAX_X[i][0]);
                next_score[now]=min(next_score[now],s);
                //printf("%lld,%lld/",s,+abs(MINMAX_X[i][now]-MINMAX_X[prev_i][prev])+abs(MINMAX_X[i][1]-MINMAX_X[i][0]));
            }
        }
        prev_i=i;
        score[0]=next_score[0];
        score[1]=next_score[1];
        //printf("%lld,%lld,%lld\n",i,score[0],score[1]);
    }
    printf("%lld\n",min(score[0],score[1]));
}