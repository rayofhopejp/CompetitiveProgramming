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

//解説
int N,K;
int V[55];
signed main(){
    scanf("%lld %lld",&N,&K);
    rep(i,N)scanf("%lld",&V[i]);
    //最後に戻すことにすると、
    //K個まで取ることができる
    //プラスか0の宝石はとっといたほうがいい
    //左からi、右からj個取る
    int ans=0;
    for(int i=0;i<=min(N,K);i++){
        for(int j=0;j<=min(N,K)-i;j++){
            //捨てる動作はk回できる
            int k=K-i-j;
            vector<int> funokazu;
            int sans=0;
            rep(a,i){
                sans+=V[a];
                if(V[a]<0)funokazu.pb(V[a]);
            }
            rep(a,j){
                sans+=V[N-a-1];
                if(V[N-a-1]<0)funokazu.pb(V[N-a-1]);
            }
            sort(funokazu.begin(),funokazu.end());
            int trash=0;
            rep(a,min(k,(int)funokazu.size())){
                trash+=funokazu[a];
            }
            //printf("%lld %lld %lld %lld\n",i,j,sans-trash,trash);
            ans=max(ans,sans-trash);
        }
    }
    printf("%lld\n",ans);
    return 0;
}