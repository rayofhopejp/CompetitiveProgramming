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
int N;
int A[200005];
int B[200005];
signed main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld %lld",&A[i],&B[i]);
        //中央値が1/2の場合があるので2倍しておく
        A[i]*=2;B[i]*=2;
    }
    //Aの中央値、Bの中央値を求める
    int AM,BM;
    int ans=0;
    sort(A,A+N);sort(B,B+N);
    if(N%2){//奇数
        AM=A[N/2];BM=B[N/2];
        //AMからBMの間の2の倍数が全て中央値になりうる
        ans=(BM-AM)/2+1;
    }else{
        AM=(A[N/2]+A[N/2-1])/2;
        BM=(B[N/2]+B[N/2-1])/2;
        //AMからBMの間の整数が全て中央値になりうる
        ans=BM-AM+1;
    }
    printf("%lld\n",ans);
    return 0;
}