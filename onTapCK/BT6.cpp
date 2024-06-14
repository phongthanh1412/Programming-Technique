#include<iostream>
using namespace std;

bool accending(int a, int b) {
	return a <= b;
}
bool deccending(int a, int b) {
	return a >= b;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
int partition(int arr[], int low, int high, bool (*compare)(int, int)) {
	int pivot = arr[high];
	int left = low, right = high - 1;
	while (1) {
		while (left <= right && compare(arr[left], pivot))
			left++;
		while (left <= right && !compare(arr[right], pivot))
			right--;
		if (left > right)
			break;
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	swap(arr[left], arr[high]);
	return left;
}
void quickSort(int arr[], int low, int high, bool (*compare)(int, int)) {
	if (low >= high)
		return;
	int pos = partition(arr, low, high, compare);
	quickSort(arr, low, pos - 1, compare);
	quickSort(arr, pos + 1, high, compare);
}
void show(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main() {
	int arr[] = { 5,7,2,1,8,4,3 };
	quickSort(arr, 0, 6, accending);
	show(arr, 7);
	quickSort(arr, 0, 6, deccending);
	show(arr, 7);
}