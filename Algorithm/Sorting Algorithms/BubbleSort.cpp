#include <iostream>
using namespace std;

// Swap the value of two parameter
void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

void sort(int arr[], int n) {
	bool haveSwap;

	for (int i = 0; i < n; i++) {
		haveSwap = false;
		for (int j = 0; j < n - 1; j++)
			// If we want to sort in ascending order then replace ">" by "<"
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				haveSwap = true;
			}

		if (haveSwap == false)
			break;
	}
}

int main() {
	int n;
	cout << "Nhap do dai cua mang can sap xep: ";
	cin >> n;
	int arr[500];
	for (int i = 0; i < n; i++) {
		cout << "Nhap so thu " << i + 1 << " cua mang: ";
		cin >> arr[i];
	}
	sort(arr, n);
	cout << "Mang da sap xep la: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
