#include <iostream>
using namespace std;
void input(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> arr[i];
	}
}

void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; ++i) {
		int key = arr[i];
		int j = i - 1;
		// If we want to sort in ascending order then replace by arr[j] < key
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void output(int arr[], int n) {
	cout << "Mang sau khi da sap xep la:" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
int main() {

	int n, arr[500];
	cout << "Nhap do dai mang can sap xep: ";
	cin >> n;
	input(arr, n);
	insertionSort(arr, n);
	output(arr, n);
	return 0;
}
