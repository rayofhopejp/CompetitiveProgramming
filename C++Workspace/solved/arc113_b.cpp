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
int calc_pow(int x, int pow,int m) {
    if (pow == 0) return 1;
    int a = calc_pow(x, pow / 2,m);
    a = a * a % m;
    if (pow % 2 == 1) a *= x;
    return a % m;
}//最小二乗法
signed main(){
    scanf("%lld %lld %lld",&A,&B,&C);
    //A^Xの一の位のサイクルを求める(10回いないにサイクルがあるはず)
    //必ず0から始まる周期になる…！
    vector<int> results;
    bool ifuse[10];
    int result=A%10;
    rep(i,10)ifuse[i]=false;
    int cnt=0;
    ifuse[result]=true;
    results.pb(result);
    while(true){
        cnt++;
        result=(result*A)%10;
        if(ifuse[result]){
            break;
        }else{
            ifuse[result]=true;
            results.pb(result);
        }
    }
    //x=B^C(mod cycle)を求める
    int x=calc_pow(B,C,(int)results.size());
    x=(x+results.size()-1)%results.size();//0の時1なので
    //A^xを求める
    int ans=results[x]%10;
    printf("%lld\n",ans);
}