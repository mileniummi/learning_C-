#include <iostream>
#include "functions.h"
#include<complex>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	complex_number a("15-2i");
	double dd= -10;
	cout << "Умножение комплексной переменной: " << a.number << " на вешественную: " << dd<< "\n";
	 complex_number f = a * dd;
	 cout << "Результат: "<< f.number << "\n";
	 complex_number c("2-10i");
	 complex_number b("15+20i");
	 cout << "Сложение комплексной переменной: " << c.number << " и комплексной : " << b.number << "\n";
	 complex_number d = c + b;
	 cout << "Результат: " << d.number << "\n";
	 complex_number e("1-2i");
	 complex_number g("3-4i");
	 cout << "Умножение комплексной переменной: " << e.number << " и комплексной : " << g.number << "\n";
	 complex_number j = e * g;
	 cout << "Результат: " << j.number << "\n";
	 complex_number m("4+3i");
	 cout << "Длина комплексного числа " << m.number << "\n";
	 double h = &m;
	 cout <<"Результат"<< h << "\n";
	 cout << "Первый массив:"<< "\n";
	 _array array1(10);
	 _array array2(20);
	 array1.show();
	 cout << "Второй массив:" << "\n";
	 array2.show();
	 _array array3 = array1 + array2;
	 cout <<"Обьединение двух массивов в 1: " << "\n";
	 array3.show();
	 cout << "Сравнение длинн массивов" << "\n";
	 if (array1 == array2) {
		 cout << "Массивы 1 и 2 равной длинны"  << "\n";
	 }
	 if (array1 != array2) {
		 cout << "Массивы 1 и 2 разной длинны" << "\n";
	 }
	 if (array1 > array2) {
		 cout << "Длинна массива  1 больше чем массива 2" << "\n";
	 }
	 if (array2 > array1) {
		 cout << "Длинна массива  2 больше чем массива 1" << "\n";
	 }
	 if (array1 < array2) {
		 cout << "Длинна массива  1 меньше чем массива 2" << "\n";
	 }
	 if (array2 < array1) {
		 cout << "Длинна массива  2 меньше чем массива 1" << "\n";
	 }

	return 0;
}