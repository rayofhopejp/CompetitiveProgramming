#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
#include<map>
#include <climits>
 
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
double prob[2][100005];
signed main(){
    scanf("%lld",&N);
    
    //1/Nの確率で各頂点が選ばれる時、全ての頂点が選ばれるまでの回数の期待値
    double ans=0.0;
    for(int i=1;i<N;i++){
        ans+=(double)N/(N-i);
    }
    printf("%.11lf\n",ans);
}