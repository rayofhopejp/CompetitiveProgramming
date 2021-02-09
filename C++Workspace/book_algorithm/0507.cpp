#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
#include<map>
 
//https://atcoder.jp/contests/dp/tasks/dp_f
using namespace std;
#define int long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007
//#define mod 998244353

char S[3005],T[3005];
int dp[3005][3005];
char ans[3005];
signed main(){
    scanf("%s",S);
    scanf("%s",T);
    int NS=strlen(S);
    int NT=strlen(T);
    rep(i,NS+1){
        rep(j,NT+1){
            if(i>0)dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(j>0)dp[i][j]=max(dp[i][j],dp[i][j-1]);
            if(i>0&&j>0&&S[i-1]==T[j-1])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    //逆にたどる
    int anslen=dp[NS][NT];
    ans[anslen]='\0';
    int len=anslen;
    int i=NS;
    int j=NT;
    while(len>0&&i>0&&j>0){
        if(S[i-1]==T[j-1]){
            ans[len-1]=S[i-1];
            i--;j--;len--;
        }else if(dp[i][j]==dp[i-1][j]){
            i--;
        }else{
            j--;
        }
    }
    printf("%s\n",ans);
    return 0;
}