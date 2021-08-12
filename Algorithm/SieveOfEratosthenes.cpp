#include <iostream>
#include <vector>
using namespace std;
/* Sàng Eratosthenes để tìm số nguyên tố
@param n Upper bound of prime array
@return All the prime number that smaller than or equal n */
void SieveOfEratosthenes(int n) {
	vector<bool> prime(n + 1, true);

	for (int p = 2; p * p <= n; p++)
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true)
			/* Update all multiples of p greater than or
			equal to the square of it numbers which are multiple
			of p and are less than p^2 are already been marked. */
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;

	// Print all prime numbers
	for (int p = 2; p <= n; p++)
		if (prime[p])
			cout << p << ' ';
}

int main() {
	int n;
	cout << "Pick a number: ";
	cin >> n;
	cout << "Following are the prime numbers smaller than or equal to " << n << '\n';
	SieveOfEratosthenes(n);
	return 0;
}
