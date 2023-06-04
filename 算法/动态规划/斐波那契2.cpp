#include <iostream>
#include <string.h>
using namespace std;
const int N = 1e7 + 10;
int memo[N];
void start()
{
    memset(memo, -1, sizeof(memo));
    // memo[1] = memo[2] = 1;
}
int dp(int n)
{
    int dp[n+1];
    dp[1]=dp[2]=1;
    for(int i=3;i<n+1;i++) dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}
int main()
{
    cout << dp(10);
}