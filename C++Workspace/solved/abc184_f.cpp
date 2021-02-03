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
int N,T;
int A[50];
vector<int>  first_half;
vector<int>  last_half;
signed main(){
    scanf("%lld %lld",&N,&T);
    rep(i,N)scanf("%lld",&A[i]);
    //半分全列挙を行う
    //N/2個目までを列挙
    rep(i,1<<(N/2)){
        int firsthalf_sumtime=0;
        rep(j,N/2){
            int ifin=(i>>j)%2;
            if(ifin)firsthalf_sumtime+=A[j];
        }
        first_half.push_back(firsthalf_sumtime);
    }
    //N/2個目より後を列挙
    rep(i,1<<(N-N/2)){
        int lasthalf_sumtime=0;
        rep(j,N-N/2){
            int ifin=(i>>j)%2;
            if(ifin)lasthalf_sumtime+=A[N/2+j];
        }
        last_half.push_back(lasthalf_sumtime);
    }
    sort(last_half.begin(),last_half.end());
    //探索
    int ans=0;
    rep(i,first_half.size()){
        int fh=first_half[i];
        if(fh>T)continue;
        int lh_itr=upper_bound(last_half.begin(),last_half.end(),T-fh)-last_half.begin()-1;
        if(lh_itr<0)ans=max(fh,ans);
        else ans=max(fh+last_half[lh_itr],ans);
    }
    printf("%lld\n",ans);
    return 0;
}