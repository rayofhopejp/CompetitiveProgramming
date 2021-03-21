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

int N;
int ans[100005];
signed main(){
    scanf("%lld",&N);
    ans[1]=1;
    for(int i=2;i<=N;i++){
        vector<bool> checkifok(N,true);
        //約数にアクセス
        for(int j=1;j*j<=i;j++){
            if(i%j!=0)continue;
            checkifok[ans[j]]=false;
            if(j!=1)checkifok[ans[i/j]]=false;
        }
        int minok=1;
        while(!checkifok[minok])minok++;
        ans[i]=minok;
    }
    for(int i=1;i<=N;i++){
        printf("%lld",ans[i]);
        if(i==N)printf("\n");
        else printf(" ");
    }
}