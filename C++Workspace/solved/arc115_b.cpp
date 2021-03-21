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
int C[505][505];
int diff[505];//i,i+1列めの差
signed main(){
    scanf("%lld",&N);
    bool ifans=true;
    int minC=LLINF,mini=-1,minj=-1;
    rep(i,N){
        rep(j,N){
            scanf("%lld",&C[i][j]);
            if(minC>C[i][j]){
                minC=C[i][j];
                mini=i;minj=j;
            }
            if(i==0){
                if(j>0)diff[j-1]=C[i][j]-C[i][j-1];
            }else{
                if(j>0&&diff[j-1]!=C[i][j]-C[i][j-1])ifans=false;//失格
            }
        }
    }
    if(!ifans){printf("No\n");return 0;}
    printf("Yes\n");
    int ans1[505];
    int ans2[505];
    rep(i,N){
        ans1[i]=C[i][minj];
    }
    rep(j,N){
        ans2[j]=C[mini][j]-C[mini][minj];
    }
    rep(i,N){
        printf("%lld",ans1[i]);
        if(i!=N-1)printf(" ");
        else printf("\n");
    }
    rep(i,N){
        printf("%lld",ans2[i]);
        if(i!=N-1)printf(" ");
        else printf("\n");
    }
}