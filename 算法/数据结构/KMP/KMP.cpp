#include <iostream>
using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10;
int n, m;
char p[N], q[M];
int ne[N];

int main() {
	cin >> n >> p + 1 >> m >> q + 1;
	//Çónext
	ne[1] = 0;
	for (int i = 2, j = 0; i <= n; i++) {
		while (j && p[i] != p[j + 1])
			j = ne[j];
		cout << ne[j];
		if (p[i] == p[j + 1])
			j++;
		ne[i] = j;
	}
	
	//Æ¥Åä¹ý³Ì
	for (int i = 1, j = 0; i <= m; i++) {
		while (j && q[i] != p[j + 1])
			j = ne[j];
		if (q[i] == p[j + 1])
			j++;
		if (j == n) {
			cout << i - n << " ";
			j = ne[j];
		}
	}
}