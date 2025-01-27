///// TODO: TLE 

#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
#include<map>
#include <unordered_set>
 
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007
//#define mod 998244353

int N;
long long int A[100];
unordered_set<long long int> memo[10000];
long long int sum_syugou[10000];
long long int func(long long int syugou){//合計が出てくる魔法の関数
    long long int ret=0;
     for(int i=0;i<N;i++){
        if(syugou& (1LL<< i))ret+=A[i];
    }
    return ret;
}
unordered_set<long long int> dp[1<<20];
unordered_set<long long int> calculate(){
    dp[0].insert(0);
    
    for(int subset=1;subset < (1LL<<N);subset++){
        int bit =__builtin_ctz(subset);
        for(long long int prev_subset=subset;;prev_subset=(prev_subset-(1LL<<bit))&subset){
            if(prev_subset==0)break;
            for(auto sum: dp[prev_subset]){
                dp[subset].insert(sum^sum_syugou[subset^prev_subset]);
            }
        }
        dp[subset].insert(sum_syugou[subset]);
    }
    return dp[(1LL<<N)-1];
}

signed main(){
    scanf("%d",&N);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,1LL<<N)sum_syugou[i]=func(i);
    printf("%ld\n",calculate().size());
    //rep(i,1LL<<N){printf("----%lld-----\n",i);for(auto u:dp[0][i])printf("%lld\n",u);for(auto u:dp[1][i])printf("%lld\n",u);}
    exit(0);
}