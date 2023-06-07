#include<iostream>
using namespace std;
const int N=1e7+10;
int stk[N],tt=0;
int main(){
    int n;
    int a[N];
    int ans[N];
    cin>>n;
    int t=n;
    while(n--){
        cin>>a[t-n];
    }
    for(int i=1;i<t+1;i++){
        while(tt>0&&stk[tt]>=a[i]){
            tt--;
        }
        if(tt>0)ans[i]=stk[tt];
        else ans[i]=-1;
        stk[++tt]=a[i];
    }
    for(int i=1;i<t+1;i++)cout<<ans[i]<<" ";
}