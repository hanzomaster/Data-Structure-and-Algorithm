#include <iostream>
using namespace std;
void NhapMang(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> arr[i];
	}
}

void HoanDoi(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

void SapXep(int arr[], int left, int right) {
	int mid = left + (right - left) / 2;
	int pivot = arr[mid];
	int i = left, j = right;
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			HoanDoi(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		SapXep(arr, left, j);
	if (right > i)
		SapXep(arr, i, right);
}

void XuatMang(int arr[], int n) {
	cout << "Mang sau khi da sap xep la:" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main() {
	int n, arr[500];
	cout << "Nhap do dai mang can sap xep: ";
	cin >> n;
	NhapMang(arr, n);
	SapXep(arr, 0, n - 1);
	XuatMang(arr, n);
	return 0;
}
