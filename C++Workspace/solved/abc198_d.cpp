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


char S1[15],S2[15],S3[15];
bool ifcharappear[30];
vector<char> charlist;
vector<int> charlist_num;
signed main(){
    scanf("%s %s %s",S1,S2,S3);
    rep(i,26)ifcharappear[i]=false;
    rep(i,strlen(S1)){
        if(!ifcharappear[S1[i]-'a'])charlist.pb(S1[i]);
        charlist_num.pb( find(charlist.begin(),charlist.end(),S1[i])-charlist.begin() );
        ifcharappear[S1[i]-'a']=true;
    }
    rep(i,strlen(S2)){
        if(!ifcharappear[S2[i]-'a'])charlist.pb(S2[i]);
        charlist_num.pb( find(charlist.begin(),charlist.end(),S2[i])-charlist.begin() );
        ifcharappear[S2[i]-'a']=true;
    }
    rep(i,strlen(S3)){
        if(!ifcharappear[S3[i]-'a'])charlist.pb(S3[i]);
        charlist_num.pb( find(charlist.begin(),charlist.end(),S3[i])-charlist.begin() );
        ifcharappear[S3[i]-'a']=true;
    }
    if(charlist.size()>10){
        printf("UNSOLVABLE");
        return 0;
    }
    //10!通りを全て試す
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    do {
        int N1=0,N2=0,N3=0;
        int cnt=0;
        int exp=pow(10,strlen(S1)-1);
        rep(i,strlen(S1)){
            N1+=v[charlist_num[cnt]]*exp;
            if(i==0&&N1==0)break;
            exp/=10;
            cnt++;
        }
        exp=pow(10,strlen(S2)-1);
        rep(i,strlen(S2)){
            N2+=v[charlist_num[cnt]]*exp;
            if(i==0&&N2==0)break;
            exp/=10;
            cnt++;
        }
        exp=pow(10,strlen(S3)-1);
        rep(i,strlen(S3)){
            N3+=v[charlist_num[cnt]]*exp;
            if(i==0&&N3==0)break;
            exp/=10;
            cnt++;
        }
        //printf("!!!%lld\n%lld\n%lld\n",N1,N2,N3);
        if(N1&&N2&&N3&&N1+N2==N3){
            printf("%lld\n%lld\n%lld\n",N1,N2,N3);
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));
    printf("UNSOLVABLE");
    return 0;
}