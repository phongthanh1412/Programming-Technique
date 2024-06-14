#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int sumOneDigit(int n) {
	if (n >= 10) {
		int surplus = n % 10;
		return surplus + sumOneDigit(n / 10);
	}
	return n;	
}
int sumDigits(int n) {
	if (n >= 10) {
		return sumDigits(sumOneDigit(n));
	}
	return n;
}
int count(int arr[], int idx, int size, int k, int cnt) {
	if (idx >= size)
		return cnt;
	if (arr[idx] == k) {
		cnt++;
	}
	return count(arr, idx + 1, size, k, cnt);

}
int multiple(int a, int b) {
	if (b < 0)
		return -multiple(a, -b);
	if (b == 1)
		return a;
	return a + multiple(a, b - 1);
}
int countString(string s1, string s2) {
	int cnt = 0;
	int start = 0;
	while (start < s1.size()) {
		int pos = s1.find(s2, start);
		if (pos == string::npos)
			break;
		else {
			cnt++;
			start = s2.size() + pos;
		}		
	}
	return cnt;
}
string exchangeString(string s1, string s2, string s3) {
	string res;
	string temp;
	int start = 0;
	if (s2.empty())
		return s1;
	while (start < s1.size()) {
		int pos = s1.find(s2, start);
		if (pos == string::npos) {
			res += s1.substr(start);
			break;
		}
		temp = s1.substr(start, pos - start) + s3;
		res += temp;
		start = pos + s2.size();
	}
	return res;
}
void convertToArray(string s) {
	int size = 0, idx = 0;
	s += ' ';
	for (int i = 0; i < s.size() - 1; i++)
		if (s[i] != ' ' && s[i + 1] == ' ')
			size++;
	int* arr = new int[size];
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ')
			continue;
		int pos = s.find(' ', i);
		if (pos == string::npos)
			pos = s.size();
		if (idx < size)
			arr[idx++] = stoi(s.substr(i, pos - i));
		i = pos;
	}
	for (int i = 0; i < idx; i++)
		cout << arr[i] << " ";
}
int** createMatrix(string filename, int& row, int& col) {
	fstream ifile;
	ifile.open(filename, ios::in);
	if (ifile.eof()) {
		cout << "File is not found!";
		return 0;
	}
	ifile >> row >> col;
	int** matrix = new int* [row];
	for (int i = 0; i < row; i++)
		matrix[i] = new int[col];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			ifile >> matrix[i][j];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	return matrix;

}
void releaseMatrix(int** matrix, int row) {
	for (int i = 0; i < row; i++)
		delete[]matrix[i];
	delete[]matrix;
}

string reverse(string s1, string s2) {
	for (int i = s1.size() - 1; i >= 0; i--)
		s2 += s1[i];
	return s2;
}

int main() {
	/*int arr[] = { 6,7,7,8,2,3,7 };
	int k = 0, cnt = 0;
	cin >> k;
	cout << count(arr, 0, 7, k, cnt);*/
	/*int a = 0, b = 0;
	cin >> a >> b;
	cout << multiple(a, b);*/
	//string s1 = "abcdgebcgfsbc";
	//string s2 = "bcdge";
	//string s3 = "xy";
	////cout << countString(s1, s2);
	//cout << exchangeString(s1, s2, s3);
	/*string filename = "data.txt";
	int** matrix = NULL;
	int row = 0, col = 0;
	matrix = createMatrix(filename, row, col);
	releaseMatrix(matrix, row);*/
	/*string s2;
	string s1 = "aBc DeF";
	cout << reverse(s1, s2);*/
	int* arr = NULL;
	string s = " 67    -09 342  0005";
	convertToArray(s);
	delete[]arr;
	return 0;
}