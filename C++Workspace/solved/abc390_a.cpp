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

int A[10];
signed main(){
    scanf("%d %d %d %d %d",&A[0],&A[1],&A[2],&A[3],&A[4]);
    rep(i,4){//A[i],A[i+1]を入れ替える
        rep(j,5){
            //printf("%d %d\n",i,j);
            if(j==i){
                if(A[j+1]!=j+1)break;
            }else if(j==i+1){
                if(A[j-1]!=j+1)break;
            }else{
                if(A[j]!=j+1)break;
            }
            if(j==4){printf("Yes\n");exit(0);}
        }
        
    }
    printf("No\n");
}