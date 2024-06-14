#include"functionBT3.h"

int main() {

	StudentList mystudent;
	fstream ifile;
	mystudent.readFileData();
	mystudent.findAgeAndGrade(mystudent);
	cout << "Danh sach sau khi sap xep tang dan theo ten (name) la: \n";
	mystudent.insertSortedByName();
	mystudent.printList();
	cout << "Danh sach sau khi sap xep tang dan theo diem trung binh (averageScore) la: \n";
	mystudent.insertSortedByAverage();
	mystudent.printList();
	cout << "Danh sach sau khi loc sinh vien la: \n";
	mystudent.findStudent(mystudent);
	mystudent.printList();

	mystudent.deleteMemory();
	return 0;
}