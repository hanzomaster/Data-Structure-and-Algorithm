// Tìm dãy con không giảm dài nhất (được phép xoá các phần tử)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lis(string s) {
	int i, j, max = 0;
	vector<int> lis(s.length());

	for (i = 0; i < s.length(); i++)
		lis[i] = 1;

	for (i = 1; i < s.length(); i++)
		for (j = 0; j < i; j++)
			if (s[i] >= s[j] && lis[i] < lis[j] + 1)
				lis[i]++;

	for (i = 0; i < s.length(); i++)
		if (max < lis[i])
			max = lis[i];

	return max;
}

int main() {
	string s;
	cin >> s;
	cout << lis(s);
	return 0;
}
