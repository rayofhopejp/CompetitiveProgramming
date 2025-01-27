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

int N,K;
int a[200005];
signed main(){
    scanf("%lld %lld",&N,&K);
    rep(i,K){scanf("%lld",&a[i]);}
    int ans=INF;
    if(K%2==0){
        ans=0;
        for(int i=0;i<K-1;i+=2){
            ans+=a[i+1]-a[i];
        }
    }else{
        // we can ignore one of odd-th socks
        vector<int> leftsum(K+5);
        leftsum[0]=0;
        for(int i=0;i<K-2;i+=2){
            leftsum[i+2]=leftsum[i]+a[i+1]-a[i];
        }
        vector<int> rightsum(K+5);
        rightsum[K-1]=0;
        for(int i=K-1;i>=2;i-=2){
            rightsum[i-2]=rightsum[i]+a[i]-a[i-1];
        }
        for(int i=0;i<K;i+=2){
            ans=min(ans,leftsum[i]+rightsum[i]);
        }
    }
    printf("%lld\n",ans);
}