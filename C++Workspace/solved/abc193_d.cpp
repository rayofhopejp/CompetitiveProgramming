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

int K;
char S[10],T[10];
int pow(int x,int y){
    if(y==0)return 1;
    return x*pow(x,y-1);
}
signed main(){
    scanf("%lld",&K);scanf("%s",S);scanf("%s",T);
    //表の点数を計算
    int countS[10];int countT[10];int countAll[10];
    rep(i,10){
        countS[i]=0;
        countT[i]=0;
        countAll[i]=0;
    }
    rep(i,4){
        countS[S[i]-'0']++;
        countT[T[i]-'0']++;
        countAll[S[i]-'0']++;
        countAll[T[i]-'0']++;
    }
    //全ての出方について考える
    double ans=0.0;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            //残り枚数は9K-8まいなので
            if(countAll[i]+1>K||countAll[j]+1>K)continue;
            if(i==j&&countAll[i]+2>K)continue;
            double prob=0.0;
            if(i!=j)prob=(double)(K-countAll[i])*(K-countAll[j])/(double)((9*K-8)*(9*K-8-1));
            else prob=(double)(K-countAll[i])*(K-countAll[j]-1)/(double)((9*K-8)*(9*K-8-1));
           // printf("%.20lf/",prob);
            int pointS=0,pointT=0;
            rep(k,10){
                if(i==k)pointS+=k*pow(10,countS[k]+1);
                else pointS+=k*pow(10,countS[k]);
                if(j==k)pointT+=k*pow(10,countT[k]+1);
                else pointT+=k*pow(10,countT[k]);
            }
            if(pointS>pointT)ans+=prob;
        }
    }
    printf("%.20lf\n",ans);
    
}