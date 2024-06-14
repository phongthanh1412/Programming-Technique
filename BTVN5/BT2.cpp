#include"functionBT2.h"

int main() {
	int n, m;
	cin >> n >> m;
	DanhSachLienKet danhsach;
	
	int** arr2 = danhsach.createMarix(n, m);
	danhsach.convertToList(arr2, n, m, danhsach.ll);
	danhsach.printList(arr2, m, danhsach.ll);
	danhsach.sortList(danhsach.ll, m);
	danhsach.printList(arr2,m,danhsach.ll);
	danhsach.findSumList(danhsach.ll, m);
	danhsach.writeToFile(danhsach.ll, m);

	int* arr1 = new int[m * n];
	danhsach.readFileData(danhsach.ll, m, arr1);
	int cnt = danhsach.countFibonacci(arr1, m);
	cout << "So luong phan tu thuoc day Fibonacci la: " << cnt << endl;

	delete[]arr1;
	danhsach.deleteMemoryList();

	return 0;
}