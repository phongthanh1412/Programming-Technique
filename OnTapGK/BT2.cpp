#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

bool isValidScore(float score) {
	return score > 0;
}
bool isLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return 1;
	return 0;
}
bool isValidDate(int day, int month, int year) {
	if (day > 31 || day < 1 || month > 12 || month < 1 || year < 0)
		return 0;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		if (day >= 1 && day <= 31)
			return 1;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		if (day >= 1 && day <= 30)
			return 1;
	if (month == 2) {
		if (isLeapYear(year)) {
			if (day >= 1 && day <= 29)
				return 1;
		}
		else {
			if (day > 28)
				return 0;
		}
	}
	return 0;
}

float averageScore(float mathsScore, float literatureScore, float englishScore) {
	return (mathsScore + literatureScore + englishScore) / 3;
}
float findMaxScore(float mathsScore, float literatureScore, float englishScore) {
	float maxi = -1e9;
	float average = averageScore(mathsScore, literatureScore, englishScore);
	if (average > maxi)
		maxi = average;
	return maxi;
}
void readAndWriteData(fstream& ifile, fstream& ofile) {

	ifile.open("input.txt", ios::in);
	if (ifile.eof()) {
		cout << "Error! File is not found!";
		return;
	}
	ofile.open("result.txt", ios::out);
	if (ofile.eof()) {
		cout << "Error! File is not found!";
		return;
	}
	string student_name;
	float maxi = -1e9;
	string line;
	while (getline(ifile, line)) {
		char c;
		string name;
		int day, month, year;
		float mathsScore, literatureScore, englishScore;
		stringstream iss(line);
		iss >> name >> day >> c >> month >> c >> year >> mathsScore >> literatureScore >> englishScore;

		if (isValidDate(day, month, year) && isValidScore(mathsScore) && isValidScore(literatureScore) && isValidScore(englishScore)) {
			
			
			ofile << name << " " << day << "/" << month << "/" << year
				<< " " << mathsScore << " " << literatureScore << " " << englishScore << endl;
			float average = averageScore(mathsScore, literatureScore, englishScore);
			maxi = findMaxScore(mathsScore, literatureScore, englishScore);
			student_name = name;
		}
	}
	ofile << endl;
	ofile << "Sinh vien co diem trung binh cao nhat la " << student_name << " voi so diem la " << maxi;
	ifile.close();
	ofile.close();
}

int main() {
	fstream ifile, ofile;
	int day, month, year;
	readAndWriteData(ifile, ofile);

	return 0;
}