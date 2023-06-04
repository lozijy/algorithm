#include <iostream>
using namespace std;

void merge_sort(int a[], int l, int r ) {
	if (l >= r)
		return;
	int mid = (l + r) >> 1;
	merge_sort(a, l, mid);
	merge_sort(a, mid + 1, r);
	int i = l;
	int j = mid + 1;
	int k = 0;
	int tmp[r - l + 1];
	while (i <= mid && j <= r) {
		if (a[i] <= a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	}
	while (i <= mid)
		tmp[k++] = a[i++];
	while (j <= r)
		tmp[k++] = a[j++];
	for (i = l, j = 0; i <= r; i++, j++)
		a[i] = tmp[j];
}

int main() {
	int n;
	cin >> n;
	int a[n];
	int t = n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	merge_sort(a, 0, t - 1);
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
}