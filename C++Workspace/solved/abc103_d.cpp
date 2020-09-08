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
//bの順でソートする
//ちなみにbit木を使わなくても，前に切ったものだけを考えればいいので解ける
int N,M;
int a[100005],b[100005];

vector< pair<int,int>  > ab;
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
    scanf("%lld %lld",&N,&M);
    BITtree ftree(N-1);
    rep(i,M){
        scanf("%lld %lld",&a[i],&b[i]);
        ab.pb(mp(b[i],a[i]));
    }
    sort(ab.begin(),ab.end());
    int ans=0;
    rep(i,ab.size()){
        int b=ab[i].first;
        int a=ab[i].second;
        //すでに切られているかどうか調べる
        int ifcut=ftree.sum(b-1)-ftree.sum(a-1);
        if(ifcut>0){//すでに切られているので何もしない
            continue;
        }else{//切る
            ftree.add(b-1,1);
            ans+=1;
        }
    }
    ftree.free();
    printf("%lld\n",ans);
}