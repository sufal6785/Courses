#include<iostream>
using namespace std;

//All pairs are ambigous. 
//In main funciton, when they are called, compiler will not able to choose differnce between them

float func1(float i);
double func1(double i);
// ambigous => func1(10);

void func2(unsigned char ch);
void func2(char ch);
// ambigous => func2('c');

void func3(int x);
void func3(int &x);
// ambigous => func3(10);

void func4(int i);
void func4(int i, int j = 0);
//ambigous => func4(3);