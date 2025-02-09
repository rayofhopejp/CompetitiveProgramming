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
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007
//#define mod 998244353

int N;
int K[105];
vector<int> A[105];
signed main(){
    scanf("%d",&N);
    rep(i,N){
        scanf("%d",&K[i]);
        rep(j,K[i]){
            int a;
            scanf("%d",&a);
            A[i].push_back(a);
        }
    }
    long double ans=0.0;
    rep(i,N)sort(A[i].begin(),A[i].end());
    rep(i,N){
        for(int j=i+1;j<N;j++){
            long double ans_ij=0.0;
            int prev_num=0;
            for(auto num:A[i]){
                if(num==prev_num)continue;
                prev_num=num;
                int num_in_i=upper_bound(A[i].begin(),A[i].end(),num)-lower_bound(A[i].begin(),A[i].end(),num);
                int num_in_j=upper_bound(A[j].begin(),A[j].end(),num)-lower_bound(A[j].begin(),A[j].end(),num);
                ans_ij+=(long double)num_in_i/(long double)K[i]*(long double)num_in_j/(long double)K[j];
                //printf("[%d %d] %d %d %d %.15LF\n",i,j,num,num_in_i,num_in_j,ans_ij);
            }
            ans=max(ans,ans_ij);
        }
    }
    printf("%.15Lf\n",ans);
}