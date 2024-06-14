#include<iostream>
#include<fstream>
using namespace std;

bool isPrime(int n) {
	if (n < 2)
		return 0;
	else {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0)
				return 0;
		}
	}
	return 1;
}
void filterPrime(string fileName, int* arr, int size) {
	fstream ifile, ofile;
	ifile.open(fileName, ios::in);
	if (ifile.eof()) {
		cout << "File is not found!";
		return;
	}
	ofile.open("28tech_prime.txt", ios::out);
	if (ofile.eof()) {
		cout << "File is not found!";
		return;
	}
	arr = new int[size];
	int n = 0, idx = 0;
	while (ifile >> n) {
		if (isPrime(n))
			arr[idx++] = n;
	}
	for (int i = 0; i < size; i++)
		ofile<<arr
	ifile.close();
	ofile.close();
}
int main() {
	int n = 0;
	filterPrime("28tech_number.txt");
	return 0;
}