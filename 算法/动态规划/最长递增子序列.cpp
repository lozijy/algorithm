#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;
int LIS(int array[], int n)
{
    int dp[n];
    // fill(dp, dp + n + 2, 1);
    for(int i=0;i<n+1;i++)dp[i]=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[i] > array[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int ret = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ret = max(ret, dp[i]);
    }
    return ret;
}
int main()
{
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << LIS(nums, 8);
}