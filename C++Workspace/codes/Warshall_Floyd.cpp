#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>

 
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define LLIandI pair<long long int , int>
#define ll long long

struct Warshall_Floyd{
    int V;
    long long int *d;//d[i_v1*V+i_v2]= v1tov2
    vector<  pair<int,int>  > *edges;
    long long total;
    bool *ifdelete;
    Warshall_Floyd(int N): V(N){
        d = new long long int[V*V];
        total=0;
        ifdelete=new bool[V*V];
        edges=new vector<  pair<int,int>  >[V];
        rep(i,V*V){
            d[i]=LLINF;
            ifdelete[i]=false;
        }
    }
    void push_edges(int a,int b, int c){
        edges[a].pb( mp(c,b));
        edges[b].pb( mp(c,a));
        if(ite(a,b)>c)d[a*V+b]=c;
        if(ite(b,a)>c)d[b*V+a]=c;
        total+=c;
    }
    long long int ite(int i,int j){
        return d[i*V+j];
    }
    void solve() { 
        for (int i = 0; i < V; i++)      // via
        for (int j = 0; j < V; j++)    // start
        for (int k = 0; k < V; k++)
        {// end
            if(i==j||j==k)continue;
            if(ifdelete[j*V+k]==false&&d[j*V+k]== ite(j,i) + ite(i,k) ){
                ifdelete[j*V+k]=true;ifdelete[k*V+j]=true;total-=d[j*V+k];
            }
            d[j*V+k] = min(ite(j,k), ite(j,i) + ite(i,k));
        }  
    }
    void free_wf(){
        delete[] d;
        delete[] edges;
    }
    
};

int main(void){
    int N;
    scanf("%d",&N);
    long long int A[300][300];
    Warshall_Floyd WF(N);
    rep(i,N){
        rep(j,N){
            scanf("%lld",&A[i][j]);
            if(i<j){WF.push_edges(i,j,A[i][j]);}
        }
    }
    WF.solve();
    rep(i,N){
        rep(j,N){
            if(WF.ite(i,j)<A[i][j]){printf("-1\n");return 0;}
        }
    }
    printf("%lld\n",WF.total);
}