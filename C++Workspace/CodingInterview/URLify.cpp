#include <cstdio>
#include <string>

void URLify(std::string& a,int truelength){
    //count spaces
    int spacecount=0;
    for(int i=0;i<truelength;i++){
        if(a[i]==' ')spacecount++;
    }
    int beforeindex=truelength-1;
    int afterindex=truelength-1+spacecount*2;
    //!!!!!last space could exceed necessary space
    if(afterindex+1<a.length()){
        a[afterindex+1]='\0';
    }
    //!!!!!
    while(beforeindex>=0){
        if(a[beforeindex]==' '){
            a[afterindex]='0';
            a[afterindex-1]='2';
            a[afterindex-2]='%';
            afterindex-=3;
        }else{
            a[afterindex]=a[beforeindex];
            afterindex--;
        }
        beforeindex--;
    }
}

int main(){
    std::string str="Mr John Smith            ";
    int truelength=13;
    URLify(str,truelength);
    printf("%s",str.c_str());
}