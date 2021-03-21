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

int N,M;
char S[100005][25];
int count0=0;
int count1=0;
signed main(){
    scanf("%lld %lld",&N,&M);
    int all=N*(N-1)/2;
    rep(i,N){
        scanf("%s",S[i]);
        int cnt=0;
        rep(j,M){
            if(S[i][j]=='1')cnt++;
        }
        if(cnt%2==0)count0++;
        else count1++;
    }
    int revans=0;
    if(count0>0)revans+=count0*(count0-1)/2;
    if(count1>0)revans+=count1*(count1-1)/2;
    int ans=all-revans;
    printf("%lld\n",ans);
}