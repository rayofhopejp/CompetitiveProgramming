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
int A[205];
signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    vector<int> store_ans[200];
    rep(i,1<<min((int)8,N)){
        vector<int> ans;
        int sum=0;
        rep(j,min((int)8,N)){
            if(i&(1<<j)){
                ans.pb(j+1);
                sum+=A[j]%200;
                sum%=200;
            }
        }
        if(store_ans[sum].size()>0){
            printf("Yes\n");
            printf("%lu",store_ans[sum].size());
            rep(j,store_ans[sum].size())printf(" %lld",store_ans[sum][j]);
            printf("\n%lu",ans.size());
            rep(j,ans.size())printf(" %lld",ans[j]);
            printf("\n");
            return 0;
        }else{
            store_ans[sum]=ans;
        }
    }
    printf("No\n");
    return 0;
}