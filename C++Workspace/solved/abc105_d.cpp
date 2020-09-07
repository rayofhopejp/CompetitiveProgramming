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
int A[100005];
int R[100005];
signed main(){
    scanf("%lld %lld",&N,&M);
    map<int,int> Rmap;
    int ans=0;
    rep(i,N){
        scanf("%lld",&A[i]);
        if(i==0)R[i]=A[i];
        else R[i]=R[i-1]+A[i];
        R[i]%=M;
        if(R[i]==0)ans++;
        if(Rmap[R[i]]>0){
            ans+=Rmap[R[i]];
            Rmap[R[i]]+=1;
        }else{
            Rmap[R[i]]=1;
        }
    }
    printf("%lld\n",ans);
    
}