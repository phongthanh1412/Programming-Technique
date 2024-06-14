#pragma once

#include<iostream>
using namespace std;

int** createArray(int& n, int& m);

void isEqualAndFindSum(int** arr, int n, int m);

int** findMatrixSum(int** arr, int n, int m);

bool isPrime(int n);

bool isPerfectNum(int n);

void particlesOfMatrix(int** arr, int n, int m);

int** deleteMatrix(int** arr, int n, int m);

void deleletMemory(int** arr, int n, int m);