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

int H,W;
char S[1005][1005];
int left_black=INF;
int right_black=-1;
int top_black=INF;
int bottom_black=-1;
signed main(){
    scanf("%d %d",&H,&W);
    rep(i,H)scanf("%s",S[i]);//#,.,?
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='#'){
                top_black=min(i,top_black);
                bottom_black=max(bottom_black,i);
                left_black=min(left_black,j);
                right_black=max(right_black,j);
            }
        }
    }
    for(int i=top_black;i<bottom_black+1;i++){
        for(int j=left_black;j<right_black+1;j++){
            if(S[i][j]=='.'){
                printf("No\n");
                exit(0);
            }
        }
    }
    printf("Yes\n");
}