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

//atcoder beginner contest 132 E
template<class T> bool chmin(T& a,T b){
    if(a>b){
        a=b;
        return true;
    }else return false;
}
int H,W;
char atlas[505][505];
int dist[505][505][3];
signed main(){
    scanf("%lld %lld",&H,&W);
    int sx,sy,gx,gy;
    rep(y,H){
        rep(x,W){
            char c='\n';
            while(c!='s'&&c!='g'&&c!='.'&&c!='#'){
                scanf("%c",&c);
                if(c=='s')sx=x,sy=y;
                if(c=='g')gx=x,gy=y;
            }
            atlas[y][x]=c;
        }
    }
    rep(y,H)rep(x,W)rep(i,3)dist[y][x][i]=LLINF;
    queue<pair<pair<int,int>,int> > que;
    dist[sy][sx][0]=0;
    que.push(mp(mp(sx,sy),0));
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    while(!que.empty()){
        pair<pair<int,int>,int> p=que.front();que.pop();
        int x=p.first.first;int y=p.first.second;int destruction=p.second;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];int ny=y+dy[i];
            if(nx>=W||nx<0||ny>=H||ny<0)continue;
            if(atlas[ny][nx]=='#'){
                if(destruction>=2)continue;
                if(chmin(dist[ny][nx][destruction+1],dist[y][x][destruction]+1))que.push(mp(mp(nx,ny),destruction+1));
            }else{
                if(chmin(dist[ny][nx][destruction],dist[y][x][destruction]+1))que.push(mp(mp(nx,ny),destruction));
            }
        }
    }
    int ans=LLINF;
    rep(i,3)chmin(ans,dist[gy][gx][i]);
    if(ans==LLINF)printf("NO\n");
    else printf("YES\n");
    return 0;
}