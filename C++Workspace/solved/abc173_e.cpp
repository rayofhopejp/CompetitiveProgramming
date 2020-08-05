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
int A[200005];
signed main(){
    scanf("%lld %lld",&N,&K);
    rep(i,N)scanf("%lld",&A[i]);
    sort(A,A+N);
    if(K==1){
        printf("%lld\n",A[N-1]);
        return 0;
    }
    if(A[N-1]<0&&K%2==1){//全て負かつKが奇数の時
        int prod=1;
        rep(i,K){
            prod*=A[N-i-1];
            prod%=mod;
        }
        printf("%lld\n",(prod%mod+mod)%mod);
        return 0;
    }
    //非負にできるので、負にならない追加方法を繰り返す
    int cnt=0;
    int left=-1;
    int right=N;
    int prod=1;
    while(cnt<K){
        if(K-cnt==1){//あと一つしか入れられない時は非負の要素を入れる
            prod*=A[right-1];
            prod%=mod;
            break;//終わり
        }
        if(A[left+2]>=0){//負の数が足りない時は必ず非負の数を入れる
            prod*=A[right-1];
            prod%=mod;
            right-=1;
            cnt+=1;
            continue;
        }
        if(A[right-2]<0){//非負の数が足りない時は必ず負の数2つを入れる
            prod*=(A[left+1]*A[left+2])%mod;
            prod%=mod;
            left+=2;
            cnt+=2;
            continue;
        }
        //非負の数2つまたは正の数1つを入れる
        int p1=A[left+1]*A[left+2];
        int p2=A[right-1]*A[right-2];
        if(p1>p2){
            prod*=(A[left+1]*A[left+2])%mod;
            left+=2;cnt+=2;
        }else{

            prod*=A[right-1];
            right-=1;cnt+=1;
        }
        prod%=mod;
    }
    printf("%lld\n",(prod%mod+mod)%mod);
    return 0;
}