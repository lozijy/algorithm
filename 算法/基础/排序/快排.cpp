#include <iostream>
#include <algorithm>
using namespace std;

void quick_sort(int a[], int l, int r) {
	if (l >= r)
		return;
	int mid = (l + r) >> 1;
	int i = l - 1;
	int j = r + 1;
	int k = a[mid];
	while (i < j) {
		do
			i++;
		while (a[i] < k);
		do
			j--;
		while (a[j] > k);
		if (i < j)
			swap(a[i], a[j]);
	}
	quick_sort(a, l, j);
	quick_sort(a, j + 1, r);
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	quick_sort(a, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << a[i];
	}

}
