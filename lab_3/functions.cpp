#include <iostream>
#include "functions.h"

using namespace std;
string inttoa(int x) {
	string temp;
	stringstream ss;
	ss << x;
	ss >> temp;
	return temp;
}

complex_number::complex_number()
{
	Im_z = 0;
	Re_z = 0;
	sign = 0;
}

complex_number::complex_number(string num)
{
	number = num;
	string temp;
	if (num[num.size() - 1] != 'i') {
		const char* str = &num[0];
		Re_z = atoi(str);
		Im_z = 0;
	}
	else {
		string temp2;
		temp.push_back(num[0]);
		const char* str = &temp[0];
		int i = 1;
		for (i = 1; i < num.size(); i++) {
			if (num[i] == '-') {
				sign = '-';
				break;
			}
			if (num[i] == '+') {
				sign = '+';
				break;
			}
			if (num[i] == 'i') {
				temp.push_back('\0');
				Re_z = 0;
				Im_z = atoi(str);
				sign = '0';
				break;
			}
			temp.push_back(num[i]);
		}
		if (Re_z != 0) {
			temp.push_back('\0');
			Re_z = atoi(str);
			for (i; num[i] != 'i'; i++) {
				temp2.push_back(num[i]);
			}
			temp2.push_back('\0');
			const char* str = &temp2[0];
			Im_z = atoi(str);
		}
	}
}

complex_number complex_number::operator*(double x)
{
	if ((Im_z < 0) && (x < 0)) {
		sign = '+';
	}
	complex_number num;
	num.Im_z = this->Im_z * x;
	num.Re_z = this->Re_z * x;
	string temp;
	if (num.Re_z != 0) {
		temp = inttoa(num.Re_z);
		int i = 0;
		if (num.Im_z > 0) {
			temp.push_back('+');
		}
	}
	if (num.Im_z != 0) {
		string temp2;
		temp2 = inttoa(num.Im_z);
		for (int i = 0; i < temp2.size(); i++) {
			temp.push_back(temp2[i]);
		}
		temp.push_back('i');
	}
	num.number = temp;
	return num;
}

complex_number complex_number::operator+(const complex_number& other)
{
	complex_number num;
	num.Im_z = this->Im_z + other.Im_z;
	num.Re_z = this->Re_z + other.Re_z;
	if (num.Im_z >= 0) {
		num.sign = '+';
	}
	else {
		num.sign = '-';
	}
	string temp;
	if (num.Re_z != 0) {
		temp = inttoa(num.Re_z);
		int i = 0;
		if (num.Im_z > 0 && num.sign == '+') {
			temp.push_back(num.sign);
		}
		if (num.Im_z > 0 && num.sign == '-') {
			temp.push_back(num.sign);
		}
	}
	if (num.Im_z != 0) {
		string temp2;
		temp2 = inttoa(num.Im_z);
		for (int i = 0; i < temp2.size(); i++) {
			temp.push_back(temp2[i]);
		}
		temp.push_back('i');
	}
	num.number = temp;
	return num;
}

complex_number complex_number::operator*(const complex_number& other)
{
	complex_number num;
	num.Im_z = (this->Im_z * other.Re_z + this->Re_z * other.Im_z);
	num.Re_z = (this->Re_z * other.Re_z - this->Im_z * other.Im_z);
	if (num.Im_z >= 0) {
		num.sign = '+';
	}
	else {
		num.sign = '-';
	}
	string temp;
	if (num.Re_z != 0) {
		temp = inttoa(num.Re_z);
		int i = 0;
		if (num.Im_z > 0 && num.sign == '+') {
			temp.push_back(num.sign);
		}
		if (num.Im_z > 0 && num.sign == '-') {
			temp.push_back(num.sign);
		}
	}
	if (num.Im_z != 0) {
		string temp2;
		temp2 = inttoa(num.Im_z);
		for (int i = 0; i < temp2.size(); i++) {
			temp.push_back(temp2[i]);
		}
		temp.push_back('i');
	}
	num.number = temp;
	return num;
}

double complex_number::operator&()
{
	return (sqrt(this->Im_z * this->Im_z + this->Re_z * this->Re_z));
}

_array::_array()
{
	size = 0;
	data = nullptr;
}

_array::_array(int n)
{
	if (n > 100) {
		cout << "Недопустимый размер массива";
	}
	else
	{
		size = n;
		this->data = new int[size];
		srand(time(NULL));
		for (int i = 0; i < size; i++) {
			data[i] = rand() % 20;
		}
	}
}

void _array::show()
{
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << "\n";
}

_array _array::operator+(const _array& other)
{
	int size = this->size + other.size;
	_array temp;
	temp.size = size;
	if (temp.data != nullptr) {
		delete[] data;
	}
	temp.data = new int[size];
	for (int i=0; i < this->size; i++) {
		temp.data[i] = this->data[i];
	}
	int k = 0;
	for (int i=this->size; i < temp.size; i++) {
		temp.data[i] = other.data[k];
		k++;
	}
	return temp;
}

bool _array::operator==(const _array& other)
{
	if (this->size == other.size)
		return true;
	else
	return false;
}

bool _array::operator!=(const _array& other)
{
	if (this->size != other.size)
		return true;
	else
		return false;
}

bool _array::operator>(const _array& other)
{
	if (this->size > other.size)
		return true;
	else
		return false;
}

bool _array::operator<(const _array& other)
{
	if (this->size < other.size)
		return true;
	else
		return false;
}
