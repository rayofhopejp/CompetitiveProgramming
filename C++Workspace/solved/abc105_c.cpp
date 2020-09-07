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
//2^iで割ったあまりは上の桁により変えられない
int N;
signed main(){
    scanf("%lld",&N);
    int M=N;
    int anscnt=0;
    char ans[50];
    while(M){
        if(M%2!=0){ans[anscnt]='1';M-=1;}
        else ans[anscnt]='0';
        anscnt+=1;
        M=M/-2;
    }
    rep(i,anscnt)printf("%c",ans[anscnt-1-i]);
    if(anscnt==0)printf("0");
    printf("\n");
}