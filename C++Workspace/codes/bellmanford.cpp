#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
 
 
using namespace std;
#define int long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back


struct Bellman_Ford{ //たどり着けないときはLLINF、負の閉路を持つときは-LLINFを返す。
    int N;
    int *d;
    int *pre;
    bool *negative;
    vector< pair< pair<int,int> , int> > edges;
    Bellman_Ford(int N) : N(N){
        d=new int[N];
        pre=new int[N];
        negative=new bool[N];
        rep(i,N){
            d[i]=LLINF;
            pre[i]=-1;
            negative[i]=false;
        }
    }
    void push_nondir(int a,int b, int c){
        edges.pb( mp( mp(a,b),c) );
        edges.pb( mp( mp(b,a),c) );
    }
    void push_dir(int a,int b, int c){
        edges.pb( mp( mp(a,b) ,c) );
    }
    int solve(int start, int end){
        d[start]=0;
        rep(i,N-1){
            rep(j,edges.size()){
                int from=edges[j].first.first;int to=edges[j].first.second;int cost=edges[j].second;
                if(d[from]!=LLINF&d[to]>d[from]+cost){
                    d[to]=d[from]+cost;
                    pre[to]=from;
                }
            }
        }
        //startからendにいく回路の中に負の重みの閉路がある？
        rep(i,N){
            rep(j,edges.size()){
                int from=edges[j].first.first;int to=edges[j].first.second;int cost=edges[j].second;
                if(d[from]!=LLINF&&d[to]>d[from]+cost){
                    d[to]=d[from]+cost;
                    negative[to]=true;
                }
                if(negative[from])negative[to]=true;
            }
        }
        if(negative[end]){return -LLINF;}
        else return d[end];
    }
    bool anywhere_negativeC(){//do after solve()
        rep(i,edges.size()){
            int from=edges[i].first.first;int to=edges[i].first.second;int cost=edges[i].second;
            if(d[to]>d[from]+cost)return true;
        }
        return false;
    }
    void free_BF(){
        delete[] d;
        delete[] pre;
        delete[] negative;
    }
    
};

