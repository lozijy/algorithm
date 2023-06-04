#include<iostream>
#include<string>
#include<algorithm>
#include<limits.h>
using namespace std;
int maxSubArray(int array[],int n){
    int dp[n];//bu lian xu,yi i jie wei
    for(int i=0;i<n;i++)dp[i]=array[i];
    for(int i=1;i<n;i++){
        dp[i]=max(dp[i],dp[i-1]+array[i]);
    }
    int ret=INT_MIN;
    for(int i=0;i<n;i++){
        ret=max(ret,dp[i]);
    }
    return ret;
}
int main(){
    int nums[]={-3,1,3,-1,2,-4,2};
    cout<<maxSubArray(nums,7);
}