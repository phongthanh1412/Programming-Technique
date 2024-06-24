#include<iostream>
#include<fstream>
using namespace std;

long long fileSizeToDecimal(char fileSizeField[12]) {
	long long decimal = 0;
	long long factor = 1;
	for (int i = 10; i >= 0; i--) {
		if (fileSizeField[i] == '\0')
			break;
		int digit = fileSizeField[i] - '0';
		decimal += digit * factor;
		factor *= 8;
	}
	return decimal;
}

void printFiles(const char* tarFile) {
	fstream ifile;
	ifile.open(tarFile, ios::in | ios::binary);
	if (ifile.eof()) {
		cout << "File is not found!";
		return;
	}
	char buffer[512];
	while (1) {
		ifile.read(buffer, 512);
		if (buffer[0] == '\0')
			break;

		char names[100];
		memcpy(names, buffer, 100);
		names[99] = '\0';

		char fileSizeField[12];
		memcpy(fileSizeField, buffer + 124, 12);
		int size = fileSizeToDecimal(fileSizeField);

		long long padding = (512 - size % 512) % 512;
		long long skippedPadding = size + padding;
		ifile.seekg(skippedPadding, ios::cur);

		cout << "Name: " << names << "| Size: " << size << endl;
	}

	ifile.close();
}

int main() {

	/*char fileSize[] = { '\0','\0','\0','\0','\0','\0','\0','\0','6','5','2','\0' };
	cout << fileSizeToDecimal(fileSize);*/

	char tarFile[] = "data2.tar";
	printFiles(tarFile);

	return 0;
}