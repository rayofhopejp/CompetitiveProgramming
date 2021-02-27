#include<cstdio>
#include<string>
#include<vector>

bool Palindrome_Permutation(std::string s){
    std::vector<int> countalphabet(26,0);
    for(int i=0;i<s.length();i++){
        if(islower(s[i])){
            countalphabet[s[i]-'a']++;
        }else if(isupper(s[i])){
            countalphabet[s[i]-'A']++;
        }
    }
    bool isthereodd=false;
    for(int i=0;i<26;i++){
        if(countalphabet[i]%2==0)continue;
        if(!isthereodd)isthereodd=true;
        else return false;
    }
    return true;
}

int main(){
    std::string str="Tact Coa";
    printf("%d",Palindrome_Permutation(str));
}