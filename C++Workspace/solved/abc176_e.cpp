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

int M,W,H;
vector<int> h_bombs[300005];
vector<int> w_bombs[300005];
set<pair<int,int> > atlas;
signed main(){
    scanf("%lld %lld %lld",&H,&W,&M);
    rep(i,M){
        int h,w;
        scanf("%lld %lld",&h,&w);h--;w--;
        h_bombs[h].pb(w);
        w_bombs[w].pb(h);
        atlas.insert(mp(h,w));
    }
    int h_max=0;
    vector<int> h_max_i;
    int w_max=0;
    vector<int> w_max_i;
    rep(i,H){
        if(h_bombs[i].size()>=h_max){
            if(h_bombs[i].size()>h_max)h_max_i.clear();
            h_max=h_bombs[i].size();
            h_max_i.pb(i);
        }
    }
    rep(i,W){
        if(w_bombs[i].size()>=w_max){
            if(w_bombs[i].size()>w_max)w_max_i.clear();
            w_max=w_bombs[i].size();
            w_max_i.pb(i);
        }
    }
    bool overrap=true;
    rep(i,h_max_i.size()){
        rep(j,w_max_i.size()){
            if(atlas.find(mp(h_max_i[i],w_max_i[j]))==atlas.end()){
                overrap=false;
                break;
            }
        }
    }
    if(overrap){
        int ans=h_max+w_max-1;
        printf("%lld\n",ans);
    }else{
        int ans=h_max+w_max;
        printf("%lld\n",ans);
    }
}