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

int A,B,C;
double f(double x){
    return A*x+B*sin(C*x*M_PI);
}
signed main(){
    scanf("%lld %lld %lld",&A,&B,&C);
    double low=0,high=1000;
    while(abs(f(high)-100)>0.0000001){//(low,high]
        double mid=(high+low)/2;
        if(f(mid)<100)low=mid;
        else high=mid;
    }
    printf("%.15lf",high);
    return 0;
}