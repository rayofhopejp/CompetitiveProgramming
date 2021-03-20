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
int a[200005],t[200005];
int Q;
int x[200005];
signed main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld %lld",&a[i],&t[i]);
    }
    //min,maxの関数をひたすら前に出す
    int max_max=-LLINF;
    int min_min=LLINF;
    int later=0;//min_minの方が後なら0,max_maxなら1
    int change=0;
    rep(i,N){
        if(t[i]==1){
            change+=a[i];
        }
        if(t[i]==2){
            if(a[i]-change>=max_max){
                max_max=a[i]-change;
            }
            /*
            if(a[i]-change>min_min){
                max_max=a[i]-change;
                later=1;
            }
            */
        }
        if(t[i]==3){
             if(a[i]-change<=min_min){
                min_min=a[i]-change;
            }
            /*
            if(a[i]-change<max_max){
                min_min=a[i]-change;
                later=0;
            }
            */
        }
        if(min_min<max_max){//異常
            if(t[i]==2){
                min_min=max_max;
                later=1;
            }
            if(t[i]==3){//minが出た
                max_max=min_min;
                later=0;
            }
        }
    }
    scanf("%lld",&Q);
    rep(i,Q){
        scanf("%lld",&x[i]);
        int ans;
        ans=min(min_min,max(max_max,x[i]))+change;
        //else ans=max(max_max,min(min_min,x[i]))+change;//これで通る
        printf("%lld\n",ans);
    }
}