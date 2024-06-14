#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//Bài 1

void reverseString(string& s1, string s2) {
	for (int i = s1.length() - 1; i >= 0; i--) {
		s2 += s1[i];
	}
	cout << s2;
}
//Bài 2

void createMatrix(string filename, int** matrix, int matrixRow, int matrixCol) {
	fstream ifile;
	ifile.open(filename, ios::in);
	if (ifile.eof()) {
		cout << "File is not found!";
		return;
	}
	ifile >> matrixRow >> matrixCol;

	matrix = new int* [matrixRow];
	for (int i = 0; i < matrixRow; i++)
		matrix[i] = new int[matrixCol];

	for (int i = 0; i < matrixRow; i++)
		for (int j = 0; j < matrixCol; j++)
			ifile >> matrix[i][j];

	for (int i = 0; i < matrixRow; i++) {
		for (int j = 0; j < matrixCol; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	
}

void release(int** matrix, int matrixRow) {
	for (int i = 0; i < matrixRow; i++)
		delete[]matrix[i];
	delete matrix;
}
std::string replaceSubstring(string& s1, string& s2, string& s3) {
	if (s2.empty()) {
		return s1; // Nếu s2 rỗng, trả về s1 vì không có gì để thay thế
	}

	string result;
	size_t i = 0;

	while (i < s1.length()) {
		size_t pos = s1.find(s2, i);
		if (pos == string::npos) {
			// Không tìm thấy s2, thêm phần còn lại của s1 vào kết quả
			result += s1.substr(i);
			break;
		}

		// Thêm phần trước s2 vào kết quả
		result += s1.substr(i, pos - i);
		// Thêm s3 vào kết quả
		result += s3;
		// Cập nhật vị trí để tiếp tục tìm kiếm sau s2
		i = pos + s2.length();
	}

	return result;
}

void convertToArray(string s, int& size) {

	s += " ";
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] != ' ' && s[i + 1] == ' ')
			size++;
	}
	int* arr = new int[size];
	int i = 0, idx = 0;
	while (i < s.length()) {
		if (s[i] == ' ') {
			i++;
			continue;
		}
		int pos = s.find(' ', i);
		if (pos == string::npos)
			pos = s.length();
		arr[idx++] = stoi(s.substr(i, pos - i));
		i = pos;

		if (idx >= size)
			break;
	}
	for (int i = 0; i < idx; i++)
		cout << arr[i] << " ";
	cout << endl;
	delete[]arr;
}
int main() {
	//Bài 1
	cout << "Bai 1\n";
	string s2;
	string s1 = "aBc DeF";
	reverseString(s1, s2);
	cout << endl;

	//Bài 2
	cout << "Bai 2\n";
	int** matrix = NULL;
	int n = 0, m = 0;
	string s = "data.txt";
	createMatrix(s, matrix, n, m);
	release(matrix, n);
	cout << endl;

	//Bai 3
	cout << "Bai 3\n";
	string a = "abcdfhscdfg";
	string b = "cdf";
	string c = "okl";
	cout << replaceSubstring(a, b, c);
	cout << endl;

	//Bai 4
	cout << "Bai 4\n";
	int size = 0;
	string str = " 009   -18  1000  03    212   4";
	convertToArray(str, size);

	return 0;
}