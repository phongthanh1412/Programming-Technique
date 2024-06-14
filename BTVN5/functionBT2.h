#pragma once

#include<iostream>
#include<fstream>
using namespace std;

struct Node {
	int* row;
	Node* next;
	Node(int* row);
};

struct DanhSachLienKet {
	int size = 0;
	Node* ll = NULL;

	int** createMarix(int& n, int& m); ;

	void convertToList(int** arr2, int n, int m, Node*& ll); 

	void sortMatrix(int* row, int m); 

	void sortList(Node*& ll, int m); 

	void findSumList(Node*& ll, int m); 

	void writeToFile(Node*& ll, int m); 

	void readFileData(Node*& ll, int m, int* arr); 

	bool isFibonacci(int n); 

	int countFibonacci(int* arr, int m); 

	void printList(int** arr2, int m, Node*& ll); 

	void deleteMemoryList(); 
};