#include<iostream>
using namespace std;

long long factorial(int n) {
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

int fibonacci(int n) {
	if (n <= 1)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int sumDigit(int n) {
	if (n < 10)
		return n;
	int surplus = n % 10;
	return surplus + sumDigit(n / 10);
}

int findSumDigit(int n) {
	if (n >= 10)
		return findSumDigit(sumDigit(n));
	return n;
}

void scanArray(int*& arr, int sizeOfArr) {
	arr = new int[sizeOfArr];
	for (int i = 0; i < sizeOfArr; i++)
		cin >> arr[i];
}

void printArray(int* arr, int idx, int sizeOfArr) {
	if (idx >= sizeOfArr)
		return;
	int ans = findSumDigit(sumDigit(arr[idx]));
	cout << ans << " ";
	return printArray(arr, idx + 1, sizeOfArr);
}

int combination(int n, int k) {
	if (n == k)
		return 1;
	return factorial(n) / (factorial(k) * factorial(n - k));
}

int findEvenSum(int* arr, int idx, int sizeOfArr) {
	if (idx >= sizeOfArr)
		return 0;
	if (arr[idx] % 2 == 0)
		return arr[idx] + findEvenSum(arr, idx + 1, sizeOfArr);
	else return findEvenSum(arr, idx + 1, sizeOfArr);
}

bool isSymmetric(int* arr, int idx, int sizeOfArr) {
	if (idx >= sizeOfArr)
		return 1;
	if (arr[idx] != arr[sizeOfArr - 1])
		return 0;
	return isSymmetric(arr, idx + 1, sizeOfArr - 1);
}
void convertToBinary(int n) {
	if (n < 2) {
		cout << n << " ";
		return;
	}
	int surplus = n % 2;
	convertToBinary(n / 2);
	cout << surplus << " ";
}

int main() {
	int* arr = NULL;
	int sizeOfArr = 0;
	cin >> sizeOfArr;
	scanArray(arr, sizeOfArr);
	//printArray(arr, 0, sizeOfArr);
	//cout << findEvenSum(arr, 0, sizeOfArr);
	cout << isSymmetric(arr, 0, sizeOfArr);
	/*cout << factorial(n);
	cout << endl;
	cout << fibonacci(n);
	cout << endl;
	cout << findSumDigit(n);*/
	delete[]arr;
	/*int n = 0, k = 0;
	cin >> n;*/
	//cin >> k;
	//convertToBinary(n);
	//cout << combination(n, k);
	return 0;
}