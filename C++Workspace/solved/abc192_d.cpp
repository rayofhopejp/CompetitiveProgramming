#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
#include<map>
#include <climits>
 
 
using namespace std;
#define int long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007
//#define mod 998244353

char N[100];
int M;
signed main(){
    scanf("%s",N);
    scanf("%lld",&M);
    int Nlen=strlen(N);
    int d=0;
    rep(i,Nlen)d=max(d,(int)(N[i]-'0'));
    int left=d;//1以上
    int right=LLINF;
  	if(Nlen==1){
      if(N[0]-'0'<=M){
        printf("1\n");
        return 0;
      }else{
        printf("0\n");
        return 0;
      }
    }
    while(right>left+1){//[left,right)
        int mid=(right+left)/2;//2以上
        int X=0;
        int expmid=1;
        for(int i=Nlen-1;i>=0;i--){
            X+=expmid*(int)(N[i]-'0');
            if(X>M){break;}
          	if(i>0&&expmid>(M-X)/mid+1){X=M+1;break;}
            expmid*=mid;	
        }
        if(X>M){
            right=mid;
        }else{
            left=mid;
        }
    }
    printf("%lld\n",left-d);
}