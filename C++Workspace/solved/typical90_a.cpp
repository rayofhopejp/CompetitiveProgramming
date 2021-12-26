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

int N;// <= 10^5
int K,L;
// O(NlogL)
int A[100100];
bool isScoreCan(int score){
    int cnt = 0;
    int bef = 0;
    rep(i,N){
        if(A[i]-bef>=score){
            bef=A[i];
            cnt++;
        }
    }
    if(L-bef>=score)cnt++;
    return cnt>=K+1;
}
signed main(){
    scanf("%lld %lld",&N,&L);
    scanf("%lld",&K);
    rep(i,N)scanf("%lld",&A[i]);
    //二分探索  [l,r)
    int l=0,r=L;
    while(l+1<r){
        int mid=(l+r)/2;
        if(isScoreCan(mid))l=mid;
        else r=mid;
    }
    printf("%lld\n",l);
}