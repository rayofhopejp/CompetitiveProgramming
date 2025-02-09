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

int N,W;
vector<pair<int,int>> block[200005];
int kieru[200005];
signed main(){
    scanf("%d %d",&N,&W);
    rep(i,N){
        int X,Y;
        scanf("%d %d",&X,&Y);X--;Y--;
        block[X].push_back(make_pair(Y,i));
        kieru[i]=INF;
    }
    rep(i,W)sort(block[i].begin(),block[i].end());
    //消えるのは常にそろったとき
    //0,1,2,...,i,...,Wにおいて、全部下にたまってるとき
    //はじめてそうなるのは、block[i]の最低値の最高値の時
    int prev_del_time=-1;
    rep(j,N){
        bool allYes=false;
        int del_time=-1;
        rep(i,W){
            if(block[i].size()<j+1){allYes=true;break;}
            del_time=max(max(prev_del_time+1,block[i][j].first),del_time);
        }
        if(allYes)break;
        //del_timeに消えるやつ
        rep(i,W)kieru[block[i][j].second]=del_time+1;
        prev_del_time=del_time;
        //printf("%d,",del_time);
    }
    //rep(i,N)printf("[%d]",kieru[i]);
    int Q;
    scanf("%d",&Q);
    rep(i,Q){
        int T,A;
        scanf("%d %d",&T,&A);A--;
        if(kieru[A]>T)printf("Yes\n");
        else printf("No\n");
    }
}