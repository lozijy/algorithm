#include<iostream>
using namespace std;
const int N=1e5+10;
int p[N];
int n,m;
void init(int n){
    for(int i=0;i<n;i++){
        p[i]=i;
    }
}
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
void merge(int a,int b){
    p[find(b)]=find(a);//error
}
void isSame(int a,int b){
    if(find(a)==find(b))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main(){
    cin>>n>>m;
    init(n);
    char chr;
    int a,b;
    while(m--){
        cin>>chr>>a>>b;
        if(chr=='M'){
            merge(a,b);
        }else{
            isSame(a,b);
        }
    }
}