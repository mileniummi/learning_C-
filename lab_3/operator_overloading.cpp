#include <iostream>
#include "functions.h"
#include<complex>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	complex_number a("15-2i");
	double dd= -10;
	cout << "��������� ����������� ����������: " << a.number << " �� ������������: " << dd<< "\n";
	 complex_number f = a * dd;
	 cout << "���������: "<< f.number << "\n";
	 complex_number c("2-10i");
	 complex_number b("15+20i");
	 cout << "�������� ����������� ����������: " << c.number << " � ����������� : " << b.number << "\n";
	 complex_number d = c + b;
	 cout << "���������: " << d.number << "\n";
	 complex_number e("1-2i");
	 complex_number g("3-4i");
	 cout << "��������� ����������� ����������: " << e.number << " � ����������� : " << g.number << "\n";
	 complex_number j = e * g;
	 cout << "���������: " << j.number << "\n";
	 complex_number m("4+3i");
	 cout << "����� ������������ ����� " << m.number << "\n";
	 double h = &m;
	 cout <<"���������"<< h << "\n";
	 cout << "������ ������:"<< "\n";
	 _array array1(10);
	 _array array2(20);
	 array1.show();
	 cout << "������ ������:" << "\n";
	 array2.show();
	 _array array3 = array1 + array2;
	 cout <<"����������� ���� �������� � 1: " << "\n";
	 array3.show();
	 cout << "��������� ����� ��������" << "\n";
	 if (array1 == array2) {
		 cout << "������� 1 � 2 ������ ������"  << "\n";
	 }
	 if (array1 != array2) {
		 cout << "������� 1 � 2 ������ ������" << "\n";
	 }
	 if (array1 > array2) {
		 cout << "������ �������  1 ������ ��� ������� 2" << "\n";
	 }
	 if (array2 > array1) {
		 cout << "������ �������  2 ������ ��� ������� 1" << "\n";
	 }
	 if (array1 < array2) {
		 cout << "������ �������  1 ������ ��� ������� 2" << "\n";
	 }
	 if (array2 < array1) {
		 cout << "������ �������  2 ������ ��� ������� 1" << "\n";
	 }

	return 0;
}