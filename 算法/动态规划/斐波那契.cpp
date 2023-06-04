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
    if (memo[n] != -1)
        return memo[n];
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    int sub = dp(n - 1) + dp(n - 2);
    memo[n] = sub;
    return memo[n];
}
int main()
{
    start();
    cout << dp(10);
}