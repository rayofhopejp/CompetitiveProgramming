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

int N;
int A[200005];
int sum[200005];//a_1,a_2,...,a_kまでの和
int maxnum[200005];//a_1,a_2,...,a_kでの最大値
signed main(){
    scanf("%d",&N);
    rep(i,N){
        scanf("%d",&A[i]);
        if(i>0)maxnum[i]=max(maxnum[i-1],A[i]);
        else maxnum[i]=A[i];
    }
    rep(i,N){// 1 2 3 / i=1 -> 2 / i=2 -> 3 5 / i=3 -> 4 6 9
        maxnum[i]=max(maxnum[i-1],A[i]);
        sum[i]=max(0,A[i]-maxnum[i-1])*(i+1)+A[i]
        
    }
}