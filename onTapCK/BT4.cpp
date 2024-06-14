#include<iostream>
using namespace std;

bool isExistNum(int arr[], int size, int k) {
	int left = 0, right = size - 1, mid = 0;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (arr[mid] == k)
			return 1;
		else if (arr[mid] < k) {
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return 0;
}
bool isExistNumRecursion(int arr[], int k, int size, int left, int right) {
	if (left > right)
		return 0;
	int mid = left + (right - left) / 2;
	if (arr[mid] == k)
		return 1;
	if (arr[mid] < k) {
		return isExistNumRecursion(arr, k, size, mid + 1, right);
	}
	else return isExistNumRecursion(arr, k, size, left, mid - 1);
	return 1;
}
bool isPerfectSquare(int n) {
	int surplus = n % 10;
	if (surplus == 2 || surplus == 3 || surplus == 7 || surplus == 8)
		return 0;
	int left = 0, right = n, mid = 0;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (mid * mid == n)
			return 1;
		else if (mid * mid < n)
			left = mid + 1;
		else right = mid - 1;
	}
	return 0;
}

int main() {
	int arr[] = { 1,3,7,8,14,56,78 };
	cout << isPerfectSquare(17);
	//cout << isExistNumRecursion(arr, 78, 7, 0, 6);
	//cout << isExistNum(arr, 7, 4);
	return 0;
}