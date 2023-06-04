#include<iostream>
using namespace std;
int change(int amount,int coins[],int size){
    int dp[size+1][amount+1];
    for(int i=0;i<size+1;i++)dp[i][0]=1;
    for(int i=0;i<amount+1;i++)dp[0][i]=0;
    for(int i=1;i<size+1;i++){
        for(int j=1;j<amount+1;j++){
            if(j>=coins[i-1]){
                dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
            }else{
                dp[i][j]=dp[i-1][j];
            }

        }
    }
    
    return dp[size][amount];
}
int main(){
    int amount=5;
    int coins[]={1,2,5};
    cout<<change(5,coins,3);
}