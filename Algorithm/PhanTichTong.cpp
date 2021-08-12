#include <iostream>
using namespace std;


int solve(int n, int m) {
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;

	int ans = 0;
	for (int i = m + 1; i <= n; i++)
		ans += solve(n - i, i);
	return ans;
}

void print(int n, int d) {
	// phan tich so n thanh tong cac tu nhien
	// d: a[1], a[2] .. a[d]
	// tim gia tri cua a[d + 1]

	static int a[100];

	if (n == 0) {
		for (int i = 1; i <= d; ++i)
			cout << a[i] << " ";
		cout << endl;
		return;
	}

	for (int value = a[d] + 1; value <= n; ++value) {
		a[d + 1] = value;
		print(n - value, d + 1);
	}
}

int main() {
	int n;
	cin >> n;
	cout << solve(n, 0) << endl;
	print(n, 0);
}
