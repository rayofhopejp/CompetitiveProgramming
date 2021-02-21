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

char S[200005];
signed main(){
    scanf("%s",S);
    int N=strlen(S);
    int alphabet[30];//出てきた文字を数える
    rep(i,30)alphabet[i]=0;
    alphabet[S[N-1]-'a']++;
    //右にある連続する二文字から右に広げていく
    int ans=0;
    for(int i=N-2;i>=0;i--){
        alphabet[S[i]-'a']++;
        if(S[i]==S[i+1]){
            ans+=N-i-2-(alphabet[S[i]-'a']-2);
            rep(i,30)alphabet[i]=0;//文字が全てS[i]になる…
            alphabet[S[i]-'a']=N-i;
        }
    }
    printf("%lld\n",ans);
}