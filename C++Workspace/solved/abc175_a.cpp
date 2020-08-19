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

char S[10];
signed main(){
    scanf("%s",S);
    if(strcmp("RRR",S)==0){
        printf("3\n");return 0;
    }else if(strcmp("RRS",S)==0||strcmp("SRR",S)==0){
        printf("2\n");return 0;
    }else if(strcmp("SSS",S)==0){
        printf("0\n");return 0;
    }else{
        printf("1\n");return 0;
    }
    return 0;
}