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

int A1,A2,A3;
signed main(){
    scanf("%d %d %d",&A1,&A2,&A3);
    if(A1*A2==A3){printf("Yes\n");return 0;}
    if(A1*A3==A2){printf("Yes\n");return 0;}
    if(A2*A1==A3){printf("Yes\n");return 0;}
    if(A2*A3==A1){printf("Yes\n");return 0;}
    if(A3*A1==A2){printf("Yes\n");return 0;}
    if(A3*A2==A1){printf("Yes\n");return 0;}
    printf("No\n");
}