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

int N,M;
int A[1005];
signed main(){
    scanf("%d %d",&N,&M);
    rep(i,M)scanf("%d",&A[i]);
    sort(A,A+M);
    int next=0;
    int cnt=0;
    printf("%d\n",N-M);
    for(int i=1;i<N+1;i++){
        if(A[next]==i){next++;}
        else{printf("%d",i);cnt++;if(cnt<N-M)printf(" ");}
    }
    printf("\n");
}