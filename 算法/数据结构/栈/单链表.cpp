#include <iostream>
using namespace std;
int head = -1;
int now = 0;
const int N = 1e7 + 10;
int val[N];
int nxt[N];
void init()
{
    now = 0;
    head = -1;
}
void hel(int v)
{
    val[now] = v;
    nxt[now] = head;
    head = now++;
}
// zai di a ge jiedian hou cha ru b
void insert(int k, int v)
{
    val[now] = v;
    nxt[now] = nxt[k];
    nxt[k] = now++;
}
void print()
{
    for (int i = head; i != -1; i = nxt[i])
        cout << val[i] << " ";
}
int main()
{
    init();
    hel(1);
    hel(2);
    insert(1, 2);
    print();
}