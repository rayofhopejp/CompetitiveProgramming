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

int N,X,M;
int memo[100005];
int cnt[100005];
signed main(){
    scanf("%lld %lld %lld",&N,&X,&M);
    int A=X;
    rep(i,M)memo[i]=-1;
    rep(i,M)cnt[i]=-1;
    memo[A]=A;
    cnt[A]=0;
    int circ=0;
    int laps=0;
    rep(i,M){
        int A_=(A*A)%M;
        if(memo[A_]==-1){
            memo[A_]=memo[A]+A_;
            cnt[A_]=i+1;
            A=A_;
        }else{//戻ってきた 必ずMのうちに戻ってくる
            circ=memo[A]+A_-memo[A_];
            laps=i+1-cnt[A_];
            A=A_;
            break;
        }
        //printf("%lld/",memo[A]);
        if(i==N-2){printf("%lld\n",memo[A]);return 0;}//周回する必要もない
    }
    int ans=memo[A];//ループに入る前のスコア
    int loop=(int)( (N-1-cnt[A])/laps ); //何周かする
    ans+=loop*circ;
    //何周かした後
    int left=N-1-cnt[A]-loop*laps;
    int B=A;
    rep(i,left){
        int B_=(B*B)%M;
        ans+=B_;
        //printf("%lld!\n",B_);
        B=B_;
    }
    //printf("%lld-%lld-%lld\n",laps,loop,circ);
    printf("%lld\n",ans);
    
}