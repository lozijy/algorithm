#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	int N, V;
	scanf("%d %d", &N, &V);
	int dp[N + 1][V + 1];
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < V + 1; j++) {
			dp[i][j] = 0;
		}
	}
	int values[N], weights[N];
	for (int i = 0; i < N; i++) {
		int vi, wi;
		scanf("%d %d", &vi, &wi);
		values[i] = vi;
		weights[i] = wi;
	}
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < V + 1; j++) {
			if (j >= weights[i - 1])
				dp[i][j] = max(dp[i - 1][j], dp[i][j - weights[i - 1]] + values[i - 1]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	printf("%d", dp[N][V]);
}