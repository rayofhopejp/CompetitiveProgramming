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

char D[10];
signed main(){
    scanf("%s",D);
    if(D[0]=='N'&&D[1]=='\0')printf("S\n");
    if(D[0]=='E'&&D[1]=='\0')printf("W\n");
    if(D[0]=='W'&&D[1]=='\0')printf("E\n");
    if(D[0]=='S'&&D[1]=='\0')printf("N\n");
    if(D[0]=='N'&&D[1]=='E')printf("SW\n");
    if(D[0]=='N'&&D[1]=='W')printf("SE\n");
    if(D[0]=='S'&&D[1]=='E')printf("NW\n");
    if(D[0]=='S'&&D[1]=='W')printf("NE\n");
    
}