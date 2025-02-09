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

long long int L,R;
int keta(long long int num){
    long long int digit=0;
    while(num!=0){
        num/=10;
        digit++;
    }
    return digit;
}
int ketasu(long long int num,int keta){
    string s = to_string(num);
    if(s[keta]>='0'&&s[keta]<='9')return s[keta]-'0';
    return 0;
}
long long int pow_ll(long long int x,int n){
    long long int ans=1;
    rep(i,n)ans*=x;
    return ans;
}
long long int snake_number_num_ika(long long int num){
    int numketa=keta(num);
    long long int ans=0;
    if(num==9)return 9;
    for(int i=0;i<numketa;i++){
        // 1,2,3,4,5,6,7,8,9,10,20,21,...,90,91,92,93,94,95,96,97,98,
        //9+1+2+3+4+5+6+7+8+9=54 96以下は52個(1~9が9こ、10~96が43こ)
        //i桁の蛇数(i=3のとき 100,200,201,210,211,300,301,302,310,311,312,320,321,322...)
        if(i==numketa-1){//311のとき、___
            for(int k=0;k<10;k++){
                if(k>ketasu(num,0))continue;
                else if(k<ketasu(num,0))ans+=pow_ll(k,i);
                else{ //311 3__
                    //311 3__, 31_
                        for(int nowketa=0;nowketa<numketa;nowketa++){//nowketaまで一致してしまうとき
                        if(nowketa==numketa-1){
                            ans++;
                            break;
                        }
                        ans+=pow_ll(ketasu(num,0),numketa-nowketa-2)*min(ketasu(num,0),ketasu(num,nowketa+1));
                        if(ketasu(num,0)<=ketasu(num,nowketa+1))break;
                    }
                }
            }
        }else for(int k=1;k<10;k++)ans+=pow_ll(k,i);
        //printf("(%lld)%d %lld/",num,i,ans);
    }
    return ans;
}
signed main(){
    scanf("%lld %lld",&L,&R);
    //printf("%lld %lld\n",snake_number_num_ika(R),snake_number_num_ika(L-1));
    printf("%lld\n",snake_number_num_ika(R)-snake_number_num_ika(L-1));
}