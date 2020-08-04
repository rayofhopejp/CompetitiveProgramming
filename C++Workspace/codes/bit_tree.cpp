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

int N,Q;
int c[500005];
int mr[500005];//一番右にある色iの玉の添字
int ans[500005];
vector< pair<pair<int,int>,int> > query;
// 自作のソート関数
bool sort_by_right(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    return a.first.second < b.first.second;
}
bool sort_by_number(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    return a.second < b.second;
}
//BIT(Fenwick) TREE(1-indexed)
struct BITtree{
    int N;
    int *bit;
    BITtree(int n){
        N=n;
        bit=new int[N+1];
        rep(i,N+1){
            bit[i]=0;
        }
    }
    int sum(int i){//a_0,a_1,...a_iを計算する
        int s=0;
        while(i>0){
            s+=bit[i];
            i-=i & -i;
        }
        return s;
    }
    void add(int i,int x){//a_i+=xとする
        while(i<=N){
            bit[i]+=x;
            i+=i& -i;
        }
    }
    void free(){
        delete[] bit;
    }
};
signed main(){
    scanf("%lld %lld",&N,&Q);
    rep(i,N){
        scanf("%lld",&c[i]);c[i]--;
    }
    rep(i,Q){
        int l,r;
        scanf("%lld %lld",&l,&r);l--;r--;
        query.pb(mp(mp(l,r),i));
    }
    rep(i,N){
        mr[i]=-1;//まだ色[i]の玉が出現してない
    }
    sort(query.begin(),query.end(),sort_by_right);
    BITtree bit_tree(N);//同じ色の中で一番右にある玉が何個あるかを保存する
    int itr=-1;//どこまで「同じ色の中で一番右にある玉」を調べたか
    rep(i,Q){//クエリを全部調べる
        int l=query[i].first.first;
        int r=query[i].first.second;
        int q=query[i].second;
        //printf("%lld %lld/",r,itr);
        while(itr<r){//クエリのrまで調べる
            itr+=1;
            if(mr[c[itr]]==-1){//まだ色がない
                bit_tree.add(itr+1,1);
            }else{
                bit_tree.add(mr[c[itr]]+1,-1);
                bit_tree.add(itr+1,1);
            }
            mr[c[itr]]=itr;//色の位置更新
        }
        ans[q]=bit_tree.sum(r+1)-bit_tree.sum(l-1+1);
    }
    rep(i,Q){
        printf("%lld\n",ans[i]);
    }
    return 0;
}