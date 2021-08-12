// Tìm tất cả hoán vị
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
// Permutations = Hoán vị

/* Function to print permutations of string
@param a The string
@param l Starting index of the string
@param r Ending index of the string */
void permute(string a, int l, int r) {
	// Base case
	if (l == r)
		cout << a << endl;
	else {
		// Permutations made
		for (int i = l; i <= r; i++) {
			// Swapping done
			swap(a[l], a[i]);

			// Recursion called
			permute(a, l + 1, r);

			// backtrack
			swap(a[l], a[i]);
		}
	}
}

// Driver Code
int main() {
	string str = "ABC";
	int n = str.size();
	permute(str, 0, n - 1);

	cout << endl;

	// 	Second approach (use algorithm library)
	// do {
	// 	cout << str << endl;
	// } while (next_permutation(str.begin(), str.end()));
	return 0;
}
