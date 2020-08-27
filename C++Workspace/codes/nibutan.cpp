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

//abc174_e
int N,K;
int A[200005];
signed main(){
    scanf("%lld %lld",&N,&K);
    int left=0;
    int right=0;
    rep(i,N){
        scanf("%lld",&A[i]);
        right=max(A[i],right);
    }
    while(left+1<right){
        int cut=0;
        int middle=(left+right)/2;
        rep(i,N){
            cut+=max((int)0,(A[i]+middle-1)/middle-1);
        }
        if(cut<=K){
            right=middle;
        }else{
            left=middle;
        }
    }
    printf("%lld\n",right);
    return 0;
}