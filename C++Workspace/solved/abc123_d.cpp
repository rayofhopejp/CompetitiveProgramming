#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
#include<map>
 
//解説
using namespace std;
#define int long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007
//#define mod 998244353

int X,Y,Z,K;
int A[1005];
int B[1005];
int C[1005];
vector<int> AB;
vector<int> ABC;
signed main(){
    scanf("%lld %lld %lld %lld",&X,&Y,&Z,&K);
    rep(i,X)scanf("%lld",&A[i]);
    rep(i,Y)scanf("%lld",&B[i]);
    rep(i,Z)scanf("%lld",&C[i]);
    sort(A,A+X);
    sort(B,B+Y);
    sort(C,C+Z);
    rep(i,X){
        rep(j,Y){
            AB.pb(A[i]+B[j]);
        }
    }
    sort(AB.begin(),AB.end(),greater<int>());
    rep(i,min(K,(int)AB.size())){
        rep(j,Z){
            ABC.pb(AB[i]+C[j]);
        }
    }
    sort(ABC.begin(),ABC.end(),greater<int>());
    rep(i,K){
        printf("%lld\n",ABC[i]);
    }
    return 0;
}