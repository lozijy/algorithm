#include<iostream>
using namespace std;
const int N=1e5+10;
int p[N],sz[N];
int n,m;
void init(int n){
    for(int i=0;i<n;i++){
        p[i]=i;
        sz[i]=1;
    }
}
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
void merge(int a,int b){
    if(find(a)==find(b))return;
    sz[find(a)]+=sz[find(b)];
    p[find(b)]=find(a);
}
void isSame(int a,int b){
    if(find(a)==find(b))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main(){
    cin>>n>>m;
    init(n);
    char chr[5];
    int a,b;
    while(m--){
        cin>>chr;
        if(chr[0]=='C'){
            cin>>a>>b;
            merge(a,b);
        }else{
            if(chr[1]=='2'){
                cin>>a;
                cout<<sz[find(a)]<<endl;
            }else{
                cin>>a>>b;
                isSame(a,b);
            }

        }
    }
}