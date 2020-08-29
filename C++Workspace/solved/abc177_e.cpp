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

int gcd(int a,int b){
    if(a==0||b==0)return max(a,b);
    int mi=min(a,b);int ma=max(a,b);
    int c=ma%mi;
    return gcd(mi,c);
}


int N;
int A[1000005];
bool soinsu[1000005];
bool ispairwise=true;
void PrimeF(int N){
    int M=N;
    for(int i=2;i<sqrt(N)+1&&M!=1;i++){
        int cnt=0;
        while(M%i==0){
            M/=i;
            cnt++;
        }
        if(cnt>0){
            if(soinsu[i]){ispairwise=false;return;}
            soinsu[i]=true;
        }
    }
    if(M!=1){
        if(soinsu[M]){ispairwise=false;return;}
        soinsu[M]=true;
    }
    return;
}

signed main(){
    scanf("%lld",&N);
    int a=1,b=1;
    int maxA=0;
    rep(i,N){
        scanf("%lld\n",&A[i]);
        maxA=max(A[i],maxA);
        b=A[i];
        if(i==0)a=A[i];
        a=gcd(a,b);
    }
    rep(i,maxA+3)soinsu[i]=false;
    rep(i,N){
        PrimeF(A[i]);
    }
    if(ispairwise)printf("pairwise coprime\n");
    else{
        if(a==1)printf("setwise coprime\n");
        else printf("not coprime\n");
    }
}