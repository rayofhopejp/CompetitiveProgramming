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

int N,K;
int P[5005];
int C[5005];
signed main(){
    scanf("%lld %lld",&N,&K);
    rep(i,N){
        scanf("%lld",&P[i]);P[i]--;
    }
    rep(i,N){
        scanf("%lld",&C[i]);
    }
    int ans=-INF;
    rep(start,N){
        int now=start;
        int cycle_point=0;
        int cycle_len=0;
        while(true){//一周を求める
            now=P[now];
            cycle_point+=C[now];
            cycle_len+=1;
            if(now==start)break;
        }
        int score=0;
        now=start;
        rep(move,cycle_len){//move回動いたあと周回するとどうなるか
            if(move>=K)break;
            now=P[now];
            score+=C[now];
            int sans=score;
            if(cycle_point>0){//周回する
                int laps=(int)(K-move-1)/cycle_len;
                sans+=laps*cycle_point;
            }
            ans=max(sans,ans);
        }
    }
    printf("%lld\n",ans);
    return 0;
}