#include<iostream>
using namespace std;
const int N=1e3+10;
bool hashTable[N]={false};//y
void print(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]!=j){
                cout<<"* ";
            }else{
                cout<<"1 ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
bool check(int x1,int y1,int x2,int y2){
    if(abs(x2-x1)==abs(y2-y1)){
        return false;
    }
    return true;
}
int count=0;
void dfs(int x,int n,int a[]){
    if(x==n){//cong 0 kai shi
        count++;
        print(a,n);//da yin,huo zhe cuo xiang ying dong zuo
        return;
    }
    for(int y=0;y<n;y++){ // xuan xiang
        if(hashTable[y]==false){ // jian cha chong fu
            bool flag=true;
            for(int i=0;i<x;i++){
                if(!check(i,a[i],x,y)){
                    flag=false;
                    break;
                }
            } // pan duan tiao jian
            if(flag){ // man zu de hua,jiu  di tui
                hashTable[y]=true;
                a[x]=y;
                dfs(x+1,n,a);
                hashTable[y]=false;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    dfs(0,n,a);
    cout<<"count"<<count<<endl;

}