#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
unordered_set<string> hashTable;
string plusOne(string str, int i)
{
    if (str[i] == '9')
        str[i] = '0';
    else
        str[i] = (char)(str[i] + 1);
    return str;
}
string minusOne(string str, int i)
{
    if (str[i] == '0')
        str[i] = '9';
    else
        str[i] = (char)(str[i] - 1);
    return str;
}
int bfs(string start, string end)
{
    queue<string> Q;
    Q.push(start);
    hashTable.insert(start);
    int step = 0;
    while (!Q.empty())
    {
        cout << "step" << step << endl;
        int sz = Q.size();
        for (int i = 0; i < sz; i++)
        {
            string t = Q.front();
            cout << t << endl;
            Q.pop();
            if (t == end)
            {
                cout << t;
                cout << end;
                return step;
            }
            for (int i = 0; i < t.size(); i++)
            {
                string str = plusOne(t, i);
                if (hashTable.find(str) != hashTable.end())
                {
                    Q.push(str);
                    hashTable.insert(str);
                }
            }
            for (int i = 0; i < t.size(); i++)
            {
                string str = minusOne(t, i);
                if (hashTable.find(str) != hashTable.end())
                {
                    Q.push(str);
                    hashTable.insert(str);
                }
            }
        }
        step++;
    }
}
int main()
{
    string start = "932";
    string end = "934";
    cout << bfs(start, end);
}