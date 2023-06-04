#include <iostream>
using namespace std;
const int N = 1e3 + 10; // 1010
bool hashTable[N] = {false};
void dfs(int index, int n, int a[])
{
    if (index == n )
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (hashTable[i] == false)
        {   
            a[index]=i;
            hashTable[i] = true;
            dfs(index + 1, n, a);
            hashTable[i] = false;
        }
    }
}
int main()
{
    int a[3];
    dfs(0, 2, a);
}