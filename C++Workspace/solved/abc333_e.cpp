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

int N,Q;
int t[200005];
int x[200005];
signed main(){
    scanf("%d",&N);
    rep(i,N)scanf("%d %d",&t[i],&x[i]);
    int need[200005];rep(i,N)need[i]=0;
    int have[200005];rep(i,N)have[i]=0;
    for(int i=N-1;i>=0;i--){
        if(t[i]==2){
            need[x[i]]++;
            have[i]=have[i+1]+1;
        }
        if(t[i]==1){
            if(need[x[i]]>0){
                have[i]=have[i+1]-1;
                need[x[i]]=need[x[i]]-1;
            }else have[i]=have[i+1];
        }
    }
    for(int i=0;i<=N;i++){
        if(need[i]>0){printf("-1\n");return 0;}
        
    }
    printf("%d\n",*max_element(have,have+N));
    int need_[200005];rep(i,N)need_[i]=0;
    vector<int> answer;

    for(int i=N-1;i>=0;i--){
        if(t[i]==2){
            need_[x[i]]++;
        }
        if(t[i]==1){
            if(need_[x[i]]>0){
                answer.push_back(1);
                need_[x[i]]=need_[x[i]]-1;
            }
            else answer.push_back(0);
        }
    }
    for(int i=answer.size()-1;i>=0;i--){
        if(i==0) printf("%d\n",answer[i]);
        else printf("%d ",answer[i]);
    }
    
}