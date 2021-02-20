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
signed main(){
    scanf("%lld %lld",&N,&K);
    int ans=N;
    rep(i,K){
        vector<int> num;
        int n=ans;
        while(n>0){
            num.pb(n%10);
            n/=10;
        }
        sort(num.begin(),num.end());
        int bigger=0;
        int smaller=0;
        int exp10=1;
        rep(j,num.size()){
            bigger+=exp10*num[j];
            smaller+=exp10*num[num.size()-1-j];
            exp10=exp10*10;
        }
        ans=bigger-smaller;
        //printf("%lld %lld %lld\n",bigger,smaller,ans);
    }
    printf("%lld\n",ans);
}