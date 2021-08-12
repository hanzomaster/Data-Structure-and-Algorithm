/* C++ program to find next consecutive
number with all distinct digits */
#include <iostream>
#include <string>
using namespace std;

int countDistinctDigits(int n) {
	/* To count the occurrence of digits
	in number from 0 to 9 */
	int arr[10] = {0};
	int count = 0;

	/* Iterate over the digits of the number
	Flag those digits as found in the array */
	while (n) {
		int r = n % 10;
		arr[r] = 1;
		n /= 10;
	}

	/* Traverse the array arr and count the
	distinct digits in the array */
	for (int i = 0; i < 10; i++) {
		if (arr[i])
			count++;
	}
	return count;
}

/* @return the total number of digits in the number */
int countDigit(int n) {
	int c = 0;

	/* Iterate over the digits of the number */
	while (n) {
		int r = n % 10;
		c++;
		n /= 10;
	}
	return c;
}

/* @return the next number with distinct digits */
int nextNumberDistinctDigit(int n) {
	while (n < INT_MAX) {
		// Count the distinct digits in N + 1
		int distinct_digits = countDistinctDigits(n + 1);

		// Count the total number of digits in N + 1
		int total_digits = countDigit(n + 1);

		if (distinct_digits == total_digits) {
			return n + 1;
		}

		else
			n++;
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	cout << nextNumberDistinctDigit(n);
	return 0;
}
