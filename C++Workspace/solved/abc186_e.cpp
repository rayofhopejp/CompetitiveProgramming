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

//解説
//よくわかってない
int gcd(int a,int b){
    if(a==0||b==0)return max(a,b);
    int mi=min(a,b);int ma=max(a,b);
    int c=ma%mi;
    return gcd(mi,c);
}

int extgcd(int a, int b, int &x, int &y) { //ax+by=gcd(a,b)なるx,yを求める
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = extgcd(b, a % b, y, x); 
    y -= (int)(a / b) * x;
    return d;//gcd(a,b)を返す
}

int T;
signed main(){
    scanf("%lld",&T);
    rep(i,T){
        int N,S,K;
        scanf("%lld %lld %lld",&N,&S,&K);
        //S+Kx=Nyとなるxをもとめる
        int g=gcd(N,K);
        if ((N-S) % g){printf("-1\n");continue;}
        //p,q(p,qは互いに素),r,g=gcd(N,K)を用いて
        //-Kx+Ny=S
        //g(-px+qy)=gr
        //p(-x)+qy=r
        int x, y;
        int p = K / g;
        int q = N / g;
        int r = S / g;
        extgcd(p, q, x, y);//px+qy=1となるx,yをもとめる
        //x>0の時、xを負にする必要がある(qを引きまくる)
        if (x > 0) {
            x = x - ((x/q)+1) * q; //ここわからん
        }
        //xが負の時、-r倍すれば答え。
        x = -x * r;
        printf("%lld\n",x%q);
    }
}