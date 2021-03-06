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

int N;
int A[300005];
int sumA[300005];
int sqsumA[300005];
signed main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld",&A[i]);
        if(i==0)sumA[i]=A[i];
        else sumA[i]=A[i]+sumA[i-1];
        if(i==0)sqsumA[i]=A[i]*A[i];
        else sqsumA[i]=A[i]*A[i]+sqsumA[i-1];
    }
    int ans=0;
    for(int i=1;i<N;i++){
        ans+=i*A[i]*A[i]-2*A[i]*sumA[i-1]+sqsumA[i-1];
    }
    printf("%lld\n",ans);
}