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

char S[1005];
signed main(){
    scanf("%s",S);
    int N=strlen(S);
    rep(i,N){
       //printf("%lld %c\n",i,S[i]);
        if(i%2==1 && !isupper(S[i])){printf("No\n");return 0;}
        if(i%2==0 && !islower(S[i])){printf("No\n");return 0;}
      
    }
    printf("Yes\n");return 0;
}