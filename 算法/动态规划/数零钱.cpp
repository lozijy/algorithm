#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
using namespace std;
int dp(int target, vector<int> lingqian)
{
    int nums[target + 1];
    // memset(nums, 1000, sizeof(nums));
    for (int i = 1; i < target+1; ++i) {
        nums[i] = INT_MAX;
}
    nums[0] = 0;
    for (int i = 1; i < target + 1; i++)
    {
        for (int ling : lingqian)
        {
            if (i - ling < 0)continue;
            nums[i] = min(nums[i], nums[i-ling]==INT_MAX?nums[i-ling]:nums[i - ling] + 1);
        }
    }
    return nums[target];
}

int main()
{
    vector<int> lingqian{1, 2, 5};
    cout << dp(11, lingqian);
}