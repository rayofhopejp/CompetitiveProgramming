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

int H,W,A,B;
int rec(int x,int y,int a,int b,vector<vector<bool>> isfull){
    if(x==W)x=0,y+=1;//改行
    if(y==H)return 1;//最後まで敷き詰められた
    if(isfull[y][x])return rec(x+1,y,a,b,isfull);//もう埋まってる
    int ans=0;
    if(b>0){//Bを敷き詰める
        isfull[y][x]=true;
        ans+=rec(x+1,y,a,b-1,isfull);
        isfull[y][x]=false;
    }
    if(a>0&&x+1<W&&!isfull[y][x+1]){//横にAを敷き詰める
        isfull[y][x]=true;isfull[y][x+1]=true;
        ans+=rec(x+1,y,a-1,b,isfull);
        isfull[y][x]=false;isfull[y][x+1]=false;
    }
    if(a>0&&y+1<H&&!isfull[y+1][x]){//たてにAを敷き詰める
        isfull[y][x]=true;isfull[y+1][x]=true;
        ans+=rec(x+1,y,a-1,b,isfull);
        isfull[y][x]=false;isfull[y+1][x]=false;
    }
    //printf("%lld %lld %lld %lld %lld\n",x,y,a,b,ans);
    return ans;
}
signed main(){
    scanf("%lld %lld %lld %lld",&H,&W,&A,&B);
    vector<vector<bool>> isfull(H,vector<bool>(W,false));
    int ans=rec(0,0,A,B,isfull);
    printf("%lld\n",ans);
}