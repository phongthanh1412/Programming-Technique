#include"linkedlist1.h"

int main() {
	StudentList myStudent;
	myStudent.readData();
	myStudent.sortByName();
	myStudent.printList();
	myStudent.writeDataToFile(myStudent);
	myStudent.deleteMemory();
	return 0;
}