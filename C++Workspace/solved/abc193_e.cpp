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

//WA
//https://scrapbox.io/pocala-kyopro/%E6%8B%A1%E5%BC%B5%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95

int T;
int gcd(int a,int b){
    if(a==0||b==0)return max(a,b);
    int mi=min(a,b);int ma=max(a,b);
    int c=ma%mi;
    return gcd(mi,c);
}
int extgcd(int a, int b, int &x, int &y) { //ax+by=gcd(a,b)なるx,yを求める
    if(b>a)return extgcd(b,a,y,x);
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = extgcd(b, a % b, y, x); 
    y -= (int)(a / b) * x;
    return d;//gcd(a,b)を返す
}
signed main(){
    scanf("%lld",&T);
    rep(i,T){
        int X,Y,P,Q;
        scanf("%lld %lld %lld %lld",&X,&Y,&P,&Q);
        //int g=gcd(2*X+2*Y,P+Q);
        int ans=LLINF;
        for(int C=X-P;C<X+Y-P;C++){
            int n,m;
            int g=extgcd(2*(X+Y),(P+Q),n,m);
            int R=2*(X+Y)/g;
            int Z=(P+Q)/g;
            if(C%g!=0)continue;
            while(n<0||m>0){
                n+=R;
                m-=Z;
            }
            int bairitu=C/g;
            //printf("%lld,%lld,%lld,%lld,%lld/",C,n,m,g,(P+Q)*m*bairitu+P);
            ans=min(ans,(P+Q)*(-m)*bairitu+P);
        }
        if(ans==LLINF)printf("infinity\n");
        else printf("%lld\n",ans);
        
    }
    
}