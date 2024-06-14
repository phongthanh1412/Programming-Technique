#include"functionBT1.h"

int main() {
	int n, m;
	cin >> n >> m;
	int** arr = createArray(n, m);
	isEqualAndFindSum(arr, n, m);
	int** matrixSum = findMatrixSum(arr, n, m);
	particlesOfMatrix(arr, n, m);
	int** deleted_matrix = deleteMatrix(arr, n, m);

	deleletMemory(deleted_matrix, n - 1, m - 1);
	deleletMemory(matrixSum, n, m);
	deleletMemory(arr, n, m);
	return 0;
}