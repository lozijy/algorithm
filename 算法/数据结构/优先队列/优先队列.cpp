#include <iostream>
using namespace std;
const int N = 1e7 + 10;
int q[N], a[N], ans[N], hh = 0, tt = -1;
int n, k;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (hh <= tt && q[hh] < i - k + 1)
			hh++;
		while (hh <= tt && a[q[tt]] >= a[i])
			tt--;
		q[++tt] = i;
		if (i >= k - 1)
			cout << a[q[hh]] << " ";
	}
	puts(" ");
	hh=0,tt=-1;
	for (int i = 0; i < n; i++) {
		if (hh <= tt && q[hh] < i - k + 1)
			hh++;
		while (hh <= tt && a[q[tt]] <= a[i])
			tt--;
		q[++tt] = i;
		if (i >= k - 1)
			cout << a[q[hh]] << " ";
	}
	puts(" ");
	return 0;
}
