#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
int partition(int arr[], int n, int low, int high) {
	int pivot = arr[high];
	int left = low;
	int right = high - 1;
	while (1) {
		while (left <= right && arr[left] <= pivot)
			left++;
		while (left <= right && arr[right] >= pivot)
			right--;
		if (left >= right)
			break;
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	swap(arr[left], arr[high]);
	return left;
}

void quickSort(int arr[], int n, int left, int right) {
	if (left < right) {
		int pos = partition(arr, n, left, right);
		quickSort(arr, n, pos + 1, right);
		quickSort(arr, n, left, pos - 1);
	}		
}
void show(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
int main() {
	int arr[] = { 5,9,8,1,3,2,4 };
	quickSort(arr, 7, 0, 6);
	show(arr, 7);
	return 0;
}