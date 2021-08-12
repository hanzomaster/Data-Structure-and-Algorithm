/* Merge Sort
	Growth Rate: T(n) = 2T(n/2) + θ(n)
	Time Complexity: θ(nLogn) in all 3 cases
	Auxiliary Space: O(n)
	Algorithmic Paradigm: Divide and Conquer
	Sorting In Place: No in a typical implementation
	Stable: Yes
*/
#include <iostream>
using namespace std;

/* 	Merge all subarray in the correct order
	@param arr[]: original array
	@param low: lower bound
	@param high: upper bound
	@param mid: middle position to divine the array */
void merge(int arr[], int low, int high, int mid) {
	int i = low, k = low, j = mid + 1, temp[500];
	while (i <= mid && j <= high)
		if (arr[i] < arr[j]) {
			temp[k] = arr[i];
			k++;
			i++;
		} else {
			temp[k] = arr[j];
			k++;
			j++;
		}

	while (i <= mid) {
		temp[k] = arr[i];
		k++;
		i++;
	}

	while (j <= high) {
		temp[k] = arr[j];
		k++;
		j++;
	}

	for (i = low; i < k; i++)
		arr[i] = temp[i];
}

/*	Divine the array into multiples subarray
	@param arr[]: original array
	@param low: lower bound
	@param high: upper bound */
void mergeSort(int arr[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;

		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);

		merge(arr, low, high, mid);
	}
	return;
}

// Driver code
int main() {
	int n, arr[500];
	cout << "Nhap do dai cua mang: ";
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
}
