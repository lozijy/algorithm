#include<iostream>
using namespace std;
const int N=1e7+10;
int n;
int l[N],r[N],e[N],idx;
void init(){
    r[0]=1,r[1]=0;
    idx=2;
}
//cha ru zuo bian huo zhe youbian
void insertr(int k,int v){
    e[idx]=v;
    r[idx]=r[k];
    l[idx]=k;
    l[r[k]]=idx;
    r[k]=idx;
    idx++;
}
void insertl(int k,int v){
    e[idx]=v;
    r[idx]=k;
    l[idx]=l[k];
    r[l[k]]=idx;
    l[k]=idx;
    idx++;
}
void remove(int k){
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}
int main(){
    init();
    insertr(0,1);
}