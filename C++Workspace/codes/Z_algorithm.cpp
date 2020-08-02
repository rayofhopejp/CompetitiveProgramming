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

int N,M;
char S[5009];
vector<int> ans;

void Z_algorithm(char *S,const int S_len,int *ret){
    //Sを0番目からとt番目から同時に見ていった時に、接頭辞が何文字一致しているか
    ret[0]=S_len;
    int i=1,j=0;
    while(i<S_len){
        while(i+j<S_len && S[j]==S[i+j])j++;
        ret[i]=j;
        if(j==0){++i;continue;}
        int k=1;
        while(i+k<S_len&&k+ret[k]<j){
            ret[i+k] = ret[k];
            k++;
        }
        i+=k;j-=k;
    }
}
signed main(){
    scanf("%lld",&N);
    scanf("%s",S);
    int ans=0;
    for(int i=0;i<N;i++){
        int Z_ret[N];
        Z_algorithm(S+i,N-i,Z_ret);
        for(int j=1;j<N-i;j++){
            //printf(Z_ret[j])
            ans=max(ans,min(j,Z_ret[j]));
        }
    }
    printf("%lld\n",ans);
    return 0;
}
