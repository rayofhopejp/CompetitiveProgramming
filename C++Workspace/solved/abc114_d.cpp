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
//素因数分解
map<int,int> primes;
//素因数分解
void PrimeF(int N){
    int M=N;
    for(int i=2;i<sqrt(N)+1;i++){
        int cnt=0;
        while(M%i==0){
            M/=i;
            cnt++;
        }
        if(cnt>0){
            if(primes.find(i)!=primes.end())primes[i]+=cnt;
            else primes[i]=1;
        }
    }
    if(M!=1){
        if(primes.find(M)!=primes.end())primes[M]+=1;
        else primes[M]=1;
    }
    return;
}
signed main(){
    scanf("%lld",&N);
    primes.clear();
    for(int i=1;i<=N;i++){
        PrimeF(i);
    }
    vector<int> nums;
    int up3=0;
    int up5=0;
    int up25=0;
    int up15=0;
    int up75=0;
    for(auto itr=primes.begin();itr!=primes.end();itr++){
        nums.pb(itr->second+1);
        //printf("%lld:%lld\n",itr->first,itr->second);
        if(itr->second+1>=3)up3++;
        if(itr->second+1>=5)up5++;
        if(itr->second+1>=15)up15++;
        if(itr->second+1>=25)up25++;
        if(itr->second+1>=75)up75++;
    }
    int ans=0;
    if(up5>=2&&up3>=3)ans+=up5*(up5-1)/2*(up3-2);//5,5,3
    if(up15>=1&&up5>=2)ans+=up15*(up5-1);//15,5
    if(up25>=1&&up3>=2)ans+=up25*(up3-1);//25,3
    if(up75>=1)ans+=up75;//75
    printf("%lld\n",ans);
}