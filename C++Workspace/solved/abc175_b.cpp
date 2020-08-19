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
int L[105];
signed main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld",&L[i]);
    }
    int ans=0;
    rep(i,N-2){
        for(int j=i+1;j<N-1;j++){
            for(int k=j+1;k<N;k++){
                if(L[i]==L[j]||L[i]==L[k]||L[j]==L[k])continue;
                int maxL=max(max(L[i],L[j]),L[k]);
                int L1=min(min(L[i],L[j]),L[k]);
                int L2=L[i]+L[j]+L[k]-maxL-L1;
                if(maxL<L1+L2)ans+=1;
            }
        }
    }
    printf("%lld\n",ans);
}