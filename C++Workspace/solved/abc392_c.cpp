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
int P[300004];
int Q[300004];
int num_to_man[300004];
signed main(){
    scanf("%d",&N);
    rep(i,N){
        scanf("%d",&P[i]);
    }
    rep(i,N){
        scanf("%d",&Q[i]);
        num_to_man[Q[i]]=i+1;
    }
    rep(i,N){
            printf("%d",Q[P[num_to_man[i+1]-1]-1]);
        if(i<N-1)printf(" ");
    }
    printf("\n");
}