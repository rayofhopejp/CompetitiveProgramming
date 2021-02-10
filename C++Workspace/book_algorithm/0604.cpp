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

int N,C;
int a[100005];
bool OK(int x){
    int bef=a[0];
    int cnt=1;
    rep(i,N){
        if(a[i]-bef>=x){
            bef=a[i];
            cnt++;
        }
        if(cnt>=C)return true;
    }
    return false;
}
signed main(){
    scanf("%lld %lld",&N,&C);
    rep(i,N)scanf("%lld",&a[i]);
    sort(a,a+N);
    int max_ans=a[N-1];
    int min_ans=0;
    while(max_ans-min_ans>1){
        int mid=(max_ans+min_ans)/2;
        if(OK(mid)){
            min_ans=mid;
        }else{
            max_ans=mid;
        }
    }
    int ans=min_ans;
    printf("%lld\n",ans);
    return 0;
}