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


int N,Q;
char S[500010];
set<int> alphabets_appear[100];


signed main(){
    scanf("%lld %s %lld",&N,S,&Q);
    rep(i,N){
        alphabets_appear[S[i]-'a'].insert(i);
    }
    rep(i,Q){
        int type;
        scanf("%lld",&type);
        if(type==1){
            int t1;char t2;
            scanf("%lld %c\n",&t1,&t2);t1--;
            if(S[t1]==t2)continue;
            alphabets_appear[S[t1]-'a'].erase(t1);
            S[t1]=t2;
            alphabets_appear[t2-'a'].insert(t1);
        }else{
            int ans=0;
            int t1;int t2;
            scanf("%lld %lld\n",&t1,&t2);t1--;t2--;
            for(char i='a';i<='z';i++){
                auto itr=alphabets_appear[i-'a'].lower_bound(t1);
                if(itr==alphabets_appear[i-'a'].end())continue;
                //printf("%c:%lld-",i,*itr);
                if(*itr<=t2)ans++;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
