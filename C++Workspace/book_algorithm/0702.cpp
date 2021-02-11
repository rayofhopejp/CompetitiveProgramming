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
int a[105],b[105],c[105],d[105];
pair<int,int> red[105];
pair<int,int> blue[105];
bool redhaspair[105];
bool y_greater_cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.second==b.second)return a.first>b.first;
    return a.second>b.second;
}
signed main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld %lld",&a[i],&b[i]);
        red[i]=mp(a[i],b[i]);
    }
    rep(i,N){
        scanf("%lld %lld",&c[i],&d[i]);
        blue[i]=mp(c[i],d[i]);
    }
    sort(red,red+N,y_greater_cmp);//y座標が大きい順でソート
    sort(blue,blue+N);//x座標でソート
    int ans=0;
    rep(i,N){
        rep(j,N){
            if(!redhaspair[j]&&blue[i].first>red[j].first&&blue[i].second>red[j].second){
                ans++;
                redhaspair[j]=true;
                break;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}