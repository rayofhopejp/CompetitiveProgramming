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
int H,W;
char a[2005][2005];
int cost[2005][2005];
vector<pair<int,int>> teleporter[30];
int retch(char a){return a-'a';}
signed main(){
    scanf("%lld %lld",&H,&W);
    rep(y,H)rep(x,W){
        a[y][x]=0;
        cost[y][x]=LLINF;
    }
    int sx,sy,gx,gy;
    rep(y,H){
        rep(x,W){
            while(a[y][x]=='\n' || a[y][x]==0){
                scanf("%c",&a[y][x]);
                if(a[y][x]=='S'){
                    sx=x;sy=y;
                }else if(a[y][x]=='G'){
                    gx=x;gy=y;
                }else if(islower(a[y][x])){
                    teleporter[retch(a[y][x])].push_back(mp(x,y));
                }
            }
        }
    }
    //すでにテレポータを使ったかどうかの確認
    bool ifusedteleport[30];
    for(int i=0;i<30;i++)ifusedteleport[i]=false;
    //幅優先探索
    queue<pair<int,int> > que;
    que.push(mp(sx,sy));
    cost[sy][sx]=0;
    int dx[4]={0,0,-1,1};int dy[4]={-1,1,0,0};
    while(!que.empty()){
        pair<int,int> p=que.front();
        que.pop();
        int x=p.first,y=p.second;int c=cost[y][x];
        //周辺4マスに進む
        rep(i,4){
            int nx=x+dx[i];int ny=y+dy[i];
            if(nx<0||nx>=W||ny<0||ny>=H||a[ny][nx]=='#')continue;
            if(cost[ny][nx]>c+1){
                cost[ny][nx]=c+1;
                que.push(mp(nx,ny));
            }
        }
        //テレポートする
        if(!islower(a[y][x]))continue;
        if(!ifusedteleport[retch(a[y][x])]){
            ifusedteleport[retch(a[y][x])]=true;
            rep(i,teleporter[retch(a[y][x])].size()){
                int nx=teleporter[retch(a[y][x])][i].first;
                int ny=teleporter[retch(a[y][x])][i].second;
                if(cost[ny][nx]>c+1){
                    cost[ny][nx]=c+1;
                    que.push(mp(nx,ny));
                }
            }
        }
    }
    if(cost[gy][gx]==LLINF)printf("-1\n");
    else printf("%lld\n",cost[gy][gx]);
    
    
}