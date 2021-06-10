#include<cstdio>
#include<vector>
typedef struct Node{
    int value;
    struct Node* nextnode;
}node;
struct HashTable{
    int SIZE_TABLE;
    std::vector<node *> ht;
    int count;
    HashTable(int size_table){ //make table
        SIZE_TABLE=size_table;
        count=0;
        for(int i=0;i<SIZE_TABLE;i++){
            ht.push_back(NULL);
        }
    }
    int hash(int key){
        return key%SIZE_TABLE;
    }
    bool insert(int key){
        node *p=ht[hash(key)];
        while(p!=NULL&&p->nextnode!=NULL){
            if(p->value==key)return false;//既に存在する
            p=p->nextnode;
        }
        if(p!=NULL&&p->value==key)return false;//既に存在する
        node *n=new node;
        n->value=key;
        n->nextnode=NULL;
        if(p==NULL)ht[hash(key)]=n;
        else p->nextnode=n;
        return true;
    }
    bool  erase(int key){
        node *p=ht[hash(key)];
        node *previous=p;
        if(p==NULL)return false;
        while(p!=NULL&&p->nextnode!=NULL){
            if(p->value==key)break;
            previous=p;
            p=p->nextnode;
        }
        if(p==previous)ht[hash(key)]=NULL;
        if(p->value==key){
            previous->nextnode=p->nextnode;
            delete p;
            return true;
        }
        return false;
    }
    bool search(int key){
        node *p=ht[hash(key)];
        while(p!=NULL&&p->nextnode!=NULL){
            if(p->value==key)return true;
            p=p->nextnode;
        }
        if(p!=NULL&&p->value==key)return true;
        return false;
    }
};
int main(){
    HashTable ht(1000);
    printf("%d",ht.insert(1));//1
    printf("%d",ht.insert(1));//0
    printf("%d",ht.insert(2));//1
    printf("%d",ht.insert(1001));//1
    printf("%d",ht.search(2));//1
    printf("%d",ht.search(3));//0
    printf("%d",ht.search(1001));//1
    printf("%d",ht.erase(1001));//1
    printf("%d",ht.erase(3));//0
    printf("%d",ht.search(1001));//0
    printf("%d",ht.erase(2));//1
    printf("%d",ht.search(2));//0
}