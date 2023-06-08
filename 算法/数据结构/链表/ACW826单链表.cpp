#include<iostream>
#include<string.h>
using namespace std;
const int N=1e5+10;
int ne[N],e[N];
int head,idx;
void init(){
    head=-1;
    idx=0;
}
void he(int val){
    e[idx]=val;
    ne[idx]=head;
    head=idx++;
}
void insert(int position,int val){
    e[idx]=val;
    ne[idx]=ne[position];
    ne[position]=idx++;
}
void del(int k){
    if(k==0){
        head=ne[head];
    }
    else{
        if(ne[k]!=-1){
        ne[k]=ne[ne[k]];
        }
    }
}
void print(){
    for(int i=head;i!=-1;i=ne[i]){
        cout<<e[i]<<" ";
    }
}
int main(){
    int N;
    cin>>N;
    init();
    while(N--){
        char c;
        int a,b;
        cin>>c;
        if(c=='I'){
            cin>>a>>b;
            insert(a-1,b);
        }else{
            cin>>a;
            if(c=='H')he(a);
            else del(a-1);
        }
    }
    print();
    
}