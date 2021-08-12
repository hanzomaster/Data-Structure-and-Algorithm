#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
/* 
Cách 1 dùng đệ quy và memoized
@param a The ith Fibonacci number
@return The value of the ith Fibonacci number */
long long fib(int a) {
	static long long memo[100];
	if (memo[a] != 0) return memo[a];
	if (a <= 2) return 1;

	memo[a] = fib(a - 1) + fib(a - 2);
	return memo[a];
}

// Cách 2 dùng table
long long fib2(int a) {
	static long long table[100];
	table[1] = 1;
	for (int i = 0; i < a; ++i) {
		table[i + 1] += table[i];
		table[i + 2] += table[i];
	}

	return table[a];
}

int main() {
	cout << fib(50) << endl;
	cout << fib2(50) << endl;
	return 0;
}
