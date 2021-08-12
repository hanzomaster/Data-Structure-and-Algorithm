// Thuật toán tìm kiếm nhị phân trong một dãy đã sắp xếp
#include <iostream>
using namespace std;
/* 
@param arr[] Dãy mẫu
@param l Cận trái
@param r Cận phải
@param find Số cần tìm */
int binarySearch(int arr[], int l, int r, int find) {
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == find)
			return mid;

		// Nếu số cần tìm nhỏ hơn phần tử chính giữa tức sô cần tìm chỉ có thể nằm bên trái dãy
		// Nếu dãy là dãy giảm dần thì đổi '>' thành '<' và ngược lại
		if (arr[mid] < find)
			return binarySearch(arr, l, mid - 1, find);

		// Nếu không thì số cần tìm chỉ có thể nằm bên phải
		return binarySearch(arr, mid + 1, r, find);
	}
	return -1;
}

int main() {
	int arrlength;
	cout << "Nhap do dai cua mang mau: ";
	cin >> arrlength;
	int arr[500];
	cout << "Nhap mang: ";
	for (int i = 0; i < arrlength; i++)
		cin >> arr[i];
	int find;
	cout << "Nhap so can tim: ";
	cin >> find;
	int vitri = binarySearch(arr, 0, arrlength, find);
	if (vitri == -1)
		cout << "Khong tim thay so can tim trong day da cho.";
	else
		cout << "So can tim o vi tri thu " << vitri + 1;
	return 0;
}
