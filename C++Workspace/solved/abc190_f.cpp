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
int a[300005];
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
    scanf("%lld",&N);
    BITtree bit_tree(N);
    int ans=0;
    rep(i,N){
        scanf("%lld",&a[i]);
        //k=0の時について転倒数を数える
        bit_tree.add(a[i]+1,1);
        ans+=bit_tree.sum(N)-bit_tree.sum(a[i]+1);
    }
    rep(k,N){
        printf("%lld\n",ans);
        ans=ans-a[k]+(N-1-a[k]);
    }
}