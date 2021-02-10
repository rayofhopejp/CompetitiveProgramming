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
int a[300005];
int b[300005];
int count_lower_x(int x){
    //x以下の数を数える
    int cnt=0;
    rep(i,N){
        cnt+=upper_bound(b,b+N,x/a[i])-b;
    }
    return cnt;
}
signed main(){
    scanf("%lld %lld",&N,&K);
    rep(i,N)scanf("%lld",&a[i]);
    rep(i,N)scanf("%lld",&b[i]);
    sort(a,a+N);sort(b,b+N);
    int left=0;
    int right=a[N-1]*b[N-1];
    while(right-left>1){//(left,right]
        int mid=(left+right)/2;
        if(count_lower_x(mid)<K){
            left=mid;
        }else{
            right=mid;
        }
    }
    printf("%lld\n",right);
    return 0;
}