#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int LCS(string str1, string str2)
{
    int m, n;
    m = str1.size();
    n = str2.size();
    int dp[m+1][n+1];
    dp[0][0]=0;
    dp[0][1]=0;
    dp[1][0]=0;
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (str1[i] == str2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    cout << LCS("abcde", "aceb");
}