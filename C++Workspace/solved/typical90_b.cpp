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

int N;

signed main(){
    scanf("%lld",&N);
    char s[21];
    s[N]='\0';
    vector<string> ans;
    rep(i,1<<N){
        rep(j,N){
            if(i&(1<<j))s[j]='(';
            else s[j]=')';
        }
        int cnt = 0;
        bool flag = true;
        rep(j,N){
            if(s[j]=='(')cnt++;
            else cnt--;
            if(cnt<0){
                flag = false;
                break;
            }
        }
        string sans=s;
        if(cnt==0&&flag)ans.pb(sans);
    }
    sort(ans.begin(),ans.end());
    rep(i,ans.size()){
        printf("%s\n",ans[i].c_str());
    }
}