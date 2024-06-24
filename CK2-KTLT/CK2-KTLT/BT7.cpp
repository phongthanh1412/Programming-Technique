#include<iostream>
#include<fstream>
using namespace std;

void readZip(const char* zipPath, char**& names, int& N) {
	fstream ifile;
	ifile.open(zipPath, ios::in | ios::binary);
	if (ifile.eof()) {
		cout << "File is not found!";
		return;
	}
	ifile.seekg(-22, ios::end);
	int endOffset = ifile.tellg();

	int total = 0;
	ifile.seekg(endOffset + 10);
	ifile.read((char*)&total, 2);

	int offsetOfCentral;
	ifile.seekg(endOffset + 16);
	ifile.read((char*)&offsetOfCentral, 4);

	N = total;
	names = new char* [N];
	ifile.seekg(offsetOfCentral);
	for (int i = 0; i < N; i++) {
		int entryOffset = ifile.tellg();

		short nameLen;
		ifile.seekg(entryOffset + 28);
		ifile.read((char*)&nameLen, 2);

		short extraFieldLen;
		ifile.seekg(entryOffset + 30);
		ifile.read((char*)&extraFieldLen, 2);

		short commentLen;
		ifile.seekg(entryOffset + 32);
		ifile.read((char*)&commentLen, 2);

		names[i] = new char[nameLen + 1];
		names[i][nameLen] = '\0';
		ifile.seekg(entryOffset + 46);
		ifile.read(names[i], nameLen);

		ifile.seekg(entryOffset + 46 + nameLen + extraFieldLen + commentLen);

	}

	ifile.close();
}
int main() {
	char zipPath[] = "data.zip";
	int N = 0;
	char** names = NULL;
	readZip(zipPath, names, N);
	for (int i = 0; i < N; i++) {
		cout << names[i] << endl;
		delete names[i];
	}
	delete names;
	return 0;
}