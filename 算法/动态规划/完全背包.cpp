#include<iostream>
using namespace std;
int main(){
    int N,V;
    cin>>N>>V;
    int V1[N],W[N];
    for(int i=0;i<N;i++){
        cin>>V1[i]>>W[i];
    }
    int dp[N+1][V+1];
    for(int i=0;i<N+1;i++){
        for(int j=0;j<V+1;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<N+1;i++){
        for(int j=1;j<V+1;j++){
            for(int k=0;k*V1[i-1]<=j;k++)dp[i][j]=max(dp[i][j],dp[i-1][j-k*V1[i-1]]+k*W[i-1]);
        }

    }
    cout<<dp[N][V];
}