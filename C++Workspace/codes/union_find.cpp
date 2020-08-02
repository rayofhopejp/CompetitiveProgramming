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

//union find
struct union_find{
    int *parent; //parent[i]=parent of i
    int N;
    union_find(int N):N(N){
        parent=new int[N];
        rep(i,N)parent[i]=i; //init
    }
    int root(int x){ // take the root of x 
        if(parent[x]==x) return x;
        parent[x]=root(parent[x]); // recursion
        return parent[x];
    }
    void unite(int x,int y){// unite tree y to tree x
        int rx=root(x);
        int ry=root(y);
        if(rx==ry) return;
        parent[ry]=rx;
    }
    bool same(int x,int y){
        int rx=root(x);
        int ry=root(y);
        return rx==ry;
    }
    bool IsAllSameTree(){
        int rt=parent[0];
        rep(i,N){
            if(rt!=parent[i])return false;
        }
        return true;
    }
};

int main(){
    int N;char s[100004];
    scanf("%d",&N);
    scanf("%s",&s);
    union_find uf((N+1)*4);
    //iとi+1番目のペア…i*4+a (a:羊羊=0 羊狼=1 狼羊=2 狼狼=3)
    rep(i,N-1){
        if(s[i+1]=='o'){
            uf.unite(i*4+0,(i+1)*4+0);
            uf.unite(i*4+1,(i+1)*4+3);
            uf.unite(i*4+2,(i+1)*4+1);
            uf.unite(i*4+3,(i+1)*4+2);
        }else{
            uf.unite(i*4+0,(i+1)*4+1);
            uf.unite(i*4+1,(i+1)*4+2);
            uf.unite(i*4+2,(i+1)*4+0);
            uf.unite(i*4+3,(i+1)*4+3);
        }
    }
    int parent=-1;int end=-1;char ans[100004];
    if(s[0]=='o'){
        if(uf.root((N-1)*4+0)==0){parent=uf.root(0);end=0;}
        if(uf.root((N-1)*4+1)==3){parent=uf.root(3);end=1;}
        if(uf.root((N-1)*4+2)==1){parent=uf.root(1);end=2;}
        if(uf.root((N-1)*4+3)==2){parent=uf.root(2);end=3;}
    }else{
        if(uf.root((N-1)*4+0)==1){parent=uf.root(1);end=0;}
        if(uf.root((N-1)*4+1)==2){parent=uf.root(2);end=1;}
        if(uf.root((N-1)*4+2)==0){parent=uf.root(0);end=2;}
        if(uf.root((N-1)*4+3)==3){parent=uf.root(3);end=3;}
    }
    if(parent==-1){printf("-1\n");return 0;}
    if(end<2)ans[N-1]='S';
    else ans[N-1]='W';
    for(int i=N-2;i>-1;i--){
       if(s[i+1]=='o'){
           if(ans[i+1]=='S'&&uf.root(i*4+0)==parent){ans[i]='S';continue;}
           if(ans[i+1]=='S'&&uf.root(i*4+2)==parent){ans[i]='W';continue;}
           if(ans[i+1]=='W'&&uf.root(i*4+3)==parent){ans[i]='W';continue;}
           if(ans[i+1]=='W'&&uf.root(i*4+1)==parent){ans[i]='S';continue;}
        }else{
            if(ans[i+1]=='S'&&uf.root(i*4+0)==parent){ans[i]='S';continue;}
            if(ans[i+1]=='S'&&uf.root(i*4+2)==parent){ans[i]='W';continue;}
            if(ans[i+1]=='W'&&uf.root(i*4+1)==parent){ans[i]='S';continue;}
            if(ans[i+1]=='W'&&uf.root(i*4+3)==parent){ans[i]='W';continue;}
        }
    }
    ans[N]='\0';
    printf("%s\n",ans);
}