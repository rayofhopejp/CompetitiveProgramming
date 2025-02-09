#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
#include<map>
#include<unordered_set>
 
 
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007
//#define mod 998244353

int N,Q;
int pigeon[1000005];//鳩 i がいる巣の番号
int num[1000005];//巣 i  にいる鳩の数
int ans=0;
signed main(){
    scanf("%d %d",&N,&Q);
    rep(i,N)num[i]=1;
    rep(i,N)pigeon[i]=i;
    rep(q,Q){
        int t=0;
        scanf("%d",&t);
        if(t==1){
            int P,H;
            scanf("%d %d",&P,&H);P--;H--;
            int previous_H=pigeon[P];
            pigeon[P]=H;
            num[previous_H]--;
            num[H]++;
            if(num[previous_H]==1)ans--;
            if(num[H]==2)ans++;
        }else{
            //rep(i,N)printf("%d,",pigeon[i]);
            printf("%d\n",ans);
        }
    }
}