#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3 + 10;
int prime_number = 0;
vector<int>primes(100, 0);

bool p[N] = {0};

void find_prime() {
	for (int i = 2; i < N; i++) {
		if (!p[i]) {
			if (prime_number <= 100) {
				primes[prime_number++] = i;
			} else {
				primes.push_back(i);
			}
			for (int j = 2 * i; j < N; j += i) {
				p[j] = true;
			}
		}
	}
}

int main() {
	find_prime();
	for (int i = 0; i < prime_number; i++) {
		cout << primes[i] << endl;
	}
}
