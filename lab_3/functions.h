#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <ctime>

using namespace std;
struct complex_number {
private:
	int Im_z;
	int Re_z;
	char sign;
public:
	string number;
	complex_number();
	complex_number(string num);
	complex_number operator *(double x);
	complex_number operator + (const complex_number& other);
	complex_number operator * (const complex_number& other);
	double  operator &();
};
class _array {
	int size;
	int* data;
	_array();
public:
	_array(int n);
	void show();
	_array  operator +(const _array& other);
	bool operator ==(const _array& other);
	bool operator !=(const _array& other);
	bool operator >(const _array& other);
	bool operator <(const _array& other);
};
string inttoa(int x);