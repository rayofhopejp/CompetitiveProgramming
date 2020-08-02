#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
 
 
using namespace std;
#define int long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back

struct Napsack_multiok{
    int C;
    int N;
    pair<int,int> *prods;
    int *dp;
    int prod_count; 
    Napsack_multiok(int c,int n){
      	C=c;N=n;
        prods = new pair<int,int>[N];
        prod_count=0;
        dp = new int[(C+2)*(N+2)];
      	initdp();
    }
    int mkitr(int x,int y){
        return x*(C+1)+y;
    }
    void initdp(){
        rep(i,N+1){
            rep(j,C+1){
                dp[mkitr(i,j)]=0;
            }
        }
    }
    void push_prods(int c,int p){
        prods[prod_count++]=mp(c,p);
    }
    int solve(){
        initdp();
        rep(i,N+1){
            if(i>0)rep(j,C+1){
                dp[mkitr(i,j)]=dp[mkitr(i-1,j)];
                if(j>0)dp[mkitr(i,j)]=max(dp[mkitr(i,j)],dp[mkitr(i,j-1)]);
                int p=prods[i-1].second;int c=prods[i-1].first;
                if(j-c>=0)dp[mkitr(i,j)]=max(dp[mkitr(i,j)],dp[mkitr(i,j-c)]+p);
            }
        }
        return dp[mkitr(N,C)];
    }
    void debug_printdp(){
        rep(i,N+1){
            rep(j,C+1){printf("%lld ",dp[mkitr(i,j)]);}
            printf("\n");
        }
    }
    void free_(){
        delete[] prods;
        delete[] dp;
    }
    
};

int N_input;
int ga,sa,ba,gb,sb,bb;
int ans=0;
signed main(){
    scanf("%lld",&N_input);
    scanf("%lld %lld %lld",&ga,&sa,&ba);
    scanf("%lld %lld %lld",&gb,&sb,&bb);
    Napsack_multiok AC(N_input,3);
    AC.push_prods(ga,gb-ga);AC.push_prods(sa,sb-sa);AC.push_prods(ba,bb-ba);
    int M=AC.solve()+N_input;
    AC.free_();
    Napsack_multiok BD(M,3);
    BD.push_prods(gb,ga-gb);BD.push_prods(sb,sa-sb);BD.push_prods(bb,ba-bb);
  	ans=BD.solve()+M;
    printf("%lld\n",ans);
    BD.free_();
}