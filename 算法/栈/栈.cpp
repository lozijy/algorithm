#include<iostream>
using namespace std;
const int N=1e7+10;
int stk[N],tt=0;
void push(int v){
    stk[++tt]=v;
}
void pop(){
    tt--;
}
bool empty(){
    return tt>0;
}
