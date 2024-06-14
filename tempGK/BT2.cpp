#include<iostream>
#include<fstream>

using namespace std;

void readData(int**& arr1, int**& arr2, int& n, int& m) {
    fstream ifile;
    ifile.open("data2.txt", ios::in);
    if (!ifile.is_open()) {
        cout << "Error! File is not found!";
        return;
    }
    ifile >> n >> m;
    arr1 = new int* [n];
    for (int i = 0; i < n; i++)
        arr1[i] = new int[m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ifile >> arr1[i][j];
        }
    }
    cout << "Matrix 1:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    ifile >> m >> n;
    arr2 = new int* [m];
    for (int i = 0; i < m; i++)
        arr2[i] = new int[n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ifile >> arr2[i][j];
        }
    }
    cout << "Matrix 2:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    ifile.close();
}
int** findTranposedMatrix(int** arr, int n, int m) {
    int** TranposedMatrix = new int* [m];
    for (int i = 0; i < m; i++)
        TranposedMatrix[i] = new int[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            TranposedMatrix[i][j] = arr[j][i];
    
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << TranposedMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return TranposedMatrix;
}
void deleteMemory(int** arr, int n) {
    for (int i = 0; i < n; i++)
        delete arr[i];
    delete[]arr;
}
int** findproductedMatrix(int** arr1, int** arr2, int n, int m) {
    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = 0;
            for (int k = 0; k < n; k++) {
                arr[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return arr;
}
int main() {
    int n, m;
    int** arr1 = nullptr;
    int** arr2 = nullptr;
    readData(arr1, arr2, n, m);
    cout << "Ma tran 1 sau khi chuyen vi:\n";
    int** tranposedMatrix1 = findTranposedMatrix(arr1, n, m);
    cout << "Ma tran 2 sau khi chuyen vi:\n";
    int** tranposedMatrix2 = findTranposedMatrix(arr2, m, n);
    int** productMatrix = findproductedMatrix(arr1, arr2, n, m);
    deleteMemory(productMatrix, n);
    deleteMemory(tranposedMatrix2, m);
    deleteMemory(tranposedMatrix1, n);
    deleteMemory(arr2, m);
    deleteMemory(arr1, n);

    return 0;
}