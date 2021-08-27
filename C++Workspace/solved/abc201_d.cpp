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
//ゲームは後ろから！

int H,W;//number of row and column
const int MAX_H=2000,MAX_W=2000;
int A[MAX_H][MAX_W];// +1 is blue, -1 is red
int DP[MAX_H][MAX_W];
signed main(){
    scanf("%lld %lld",&H,&W);
    rep(i,H)rep(j,W){
        char c='\n';
        while(c!='+' && c!= '-')scanf("%c",&c);
        A[i][j]=(c=='+')?1:-1;
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if((i+j)%2)DP[i][j]=INF;
            else DP[i][j]=-INF;
        }
    }
    DP[H-1][W-1]=0;
    for(int turn=H+W-1;turn>=0;turn--){
        for(int row=0;row<=min(H-1,turn);row++){
            int column=turn-row;
            if(column>=W)continue;
            if(turn%2==0){// turn of takahashi
                if(row+1<H)DP[row][column]=max(DP[row][column],DP[row+1][column]+A[row+1][column]);//deliver down
                if(column+1<W)DP[row][column]=max(DP[row][column],DP[row][column+1]+A[row][column+1]);//deliver right
            }else{//turn of aoki
                if(row+1<H)DP[row][column]=min(DP[row][column],DP[row+1][column]-A[row+1][column]);//deliver down
                if(column+1<W)DP[row][column]=min(DP[row][column],DP[row][column+1]-A[row][column+1]);//deliver right
            }
        }
    }
    /*
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            printf("%lld ",DP[i][j]);
        }
        printf("\n");
    }
    */
    if(DP[0][0]>0)printf("Takahashi\n");
    else if(DP[0][0]<0)printf("Aoki\n");
    else printf("Draw\n");
}