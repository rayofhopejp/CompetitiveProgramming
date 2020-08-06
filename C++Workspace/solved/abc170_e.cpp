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
int A[200005];//それぞれの児童のレート
int B[200005];//それぞれの児童の入っている保育園
multiset<pair<int,int>> children[200005];
//それぞれの園にいる児童のレート/番号　レートの低い順にソートされる
multiset<pair<int,int>> topchildren;
//それぞれの幼稚園での最強児童のレート/番号　レートの低い順にソートされる
signed main(){
    scanf("%lld %lld",&N,&Q);
    int M=200000;//幼稚園の数
    rep(i,N){
        scanf("%lld %lld",&A[i],&B[i]);B[i]--;
        children[B[i]].insert(mp(A[i],i));
        //もし最初のメンバーだったら最強児童に登録
        if(children[B[i]].size()==1){
            topchildren.insert(mp(A[i],i));
        }else{
            //もしトップだったら最強児童を交代
            auto topitr=children[B[i]].rbegin();
            if((*topitr).second==i){
                topitr++;
                topchildren.erase(mp((*topitr).first,(*topitr).second));//前の人のを削除
                topchildren.insert(mp(A[i],i));
            }
        }
    }
    auto itr=topchildren.begin();
    rep(i,Q){
        int c,d;
        scanf("%lld %lld",&c,&d);c--;d--;
        //もし移動する前で1人だったら最強児童削除
        if(children[B[c]].size()==1){
            topchildren.erase(mp(A[c],c));
        }else{
            //もし移動する前にトップだったら最強児童交代
            auto topitr=children[B[c]].rbegin();
            if((*topitr).second==c){
                topitr++;
                topchildren.insert(mp((*topitr).first,(*topitr).second));//前の人のを削除
                topchildren.erase(mp(A[c],c));
            }
        }
        children[B[c]].erase(mp(A[c],c));
        children[d].insert(mp(A[c],c));
        //もし移動する先で1人だったら最強児童追加
        if(children[d].size()==1){
            topchildren.insert(mp(A[c],c));
        }else{
            //もし移動した先でトップだったら最強児童交代
            auto topitr2=children[d].rbegin();
            if((*topitr2).second==c){
                topitr2++;
                topchildren.erase(mp((*topitr2).first,(*topitr2).second));//前の人のを削除
                topchildren.insert(mp(A[c],c));
            }
        }
        auto topitr3=topchildren.begin();
        printf("%lld\n",(*topitr3).first);
        //幼稚園を交代
        B[c]=d;
    }

    return 0;
}