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
int A[200005];
int MaxA[200005];
int X[200005],Y[200005];
vector<int> reverse_edges[200005];
signed main(){
    scanf("%lld %lld",&N,&M);
    rep(i,N){
        scanf("%lld",&A[i]);
        MaxA[i]=-1001001001;
    }
    rep(i,M){
        scanf("%lld %lld",&X[i],&Y[i]);
        X[i]--;Y[i]--;
        //逆に道をつなぐ
        reverse_edges[Y[i]].push_back(X[i]);
    }
    //街Nから
    int ans=-1001001001;
    for(int i=N-1;i>=0;i--){
        ans=max(MaxA[i]-A[i],ans);
        rep(j,reverse_edges[i].size()){
            int ni=reverse_edges[i][j];
            MaxA[ni]=max(MaxA[ni],max(A[i],MaxA[i]));
        }
    }
    printf("%lld\n",ans);
}