#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> hashTable;
    hashTable.insert(3);
    hashTable.insert(4);
    hashTable.erase(3);
    if(hashTable.find(3)==hashTable.end()){
        cout<<"mei zhao dao";
    }else{
        cout<<"zhao dao le ";
    }
    for(auto it=hashTable.begin();it!=hashTable.end();it++){
        cout<<*it;
    }
}