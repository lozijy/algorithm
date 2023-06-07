#include<iostream>
using namespace std;
const int N=1e7+10;
int q[N],hh=0,tt=-1;
//charu 
void push(int v){
    q[++tt]=v;
}
void pop(){
    hh++;
} 
bool empty(){
    return hh>tt;
}    
int front(){
    return q[hh];
}
int back(){
    return q[tt];
}
int main(){
    int n;
    cin>>n;
    cout<<"hello"<<endl;
}