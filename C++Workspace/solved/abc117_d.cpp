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
//abc117_d
int N,K;
int A[100005];
int keta[100005][50];
int K_keta[50];
signed main(){
    scanf("%lld %lld",&N,&K);
    int now=K;int K_cnt=0;
    while(now>0){
        K_keta[K_cnt]=now%2;
        now/=2;K_cnt++;
    }
    int A_cnt=0;
    rep(i,N){
        scanf("%lld",&A[i]);
        int now=A[i];
        int cnt=0;
        while(now>0){
            keta[i][cnt]=now%2;
            now/=2;cnt++;
        }
        A_cnt=max(cnt,A_cnt);
    }
    int pow2[50];
    pow2[0]=1;
    rep(i,45)if(i>0)pow2[i]=pow2[i-1]*2;
    int ans=0;
    for(int i=max(K_cnt,A_cnt);i>-1;i--){
        int cnt1=0;
        rep(j,N)if(keta[j][i])cnt1++;
        if(pow2[i]<=K&&cnt1*2<N){
            K-=pow2[i];
            ans+=pow2[i]*(N-cnt1);
        }else{
            ans+=pow2[i]*cnt1;
        }
    }
    printf("%lld\n",ans);
}