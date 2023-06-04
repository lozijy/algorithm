#include<iostream>
using namespace std;
int main(){
    int n,m,q;
    int x1,y1,x2,y2;
    cin>>n>>m>>q;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    //前缀和
    int b[n][m+1];
    for(int i=0;i<n;i++){
        for(int j=1;j<m+1;j++){
            b[i][j]=b[i][j-1]+a[i][j-1];
        }
    }
    while(q--){
        cin>>x1>>y1>>x2>>y2;
        int ans;
        for(int i=x1-1;i<x2;i++){
            ans+=b[i][y2]-b[i][y1-1];
        }
        cout<<ans<<endl;
        ans=0;
    }
}