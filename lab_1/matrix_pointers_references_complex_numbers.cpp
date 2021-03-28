#include"functions.h"
#include<string>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int a = 5;
	int b =  10;

	cout << "a=" << a << "\t" << "b=" << b << "\n";

	inc_pointer(&a, &b);

	cout << "a+b=" <<  a << "\n";

	cout << "a=" << a << "\t" << "b=" << b << "\n";

	inc_reference(a, b);

	cout <<"a+b=" <<  a << "\n";

	cout << "������������� � � b" << "\n";

	sign_change_pr(&a);

	cout << a << "\n";

	sign_change_ref(b);	

	cout << b << "\n";

	complex comp(4, -2);
	complex comp2(8, 5);
	double matrix[3][3] = {
	{1, 3, 6},
	{2, 4, 5},
	{3, 8, 9}
	};
	double var1 = 19;
	cout << "����������� ���������� ";
	comp.print();
	cout << "\n";

	cout << "���������� �����������" << "\n";

	altr_complex_pr(&comp);
	comp.print();

	cout << "����������� ���������� ";
	comp2.print();
	cout << "\n";

	cout << "���������� �����������" << "\n";

	altr_complex_ref(comp2);
	comp2.print();

	cout << "����������� �������:\n";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix[i][j] <<  "\t";
		}
		cout << "\n";
	}

	cout << "������� ���������� �� " << var1 << "\n";

	matrix_multiply_ref(matrix, var1);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << "\n";
	}
	double var2 = 10;
	cout << "������� ���������� �� " << var2 << "\n";

	matrix_multiply_pr(*matrix, var2);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << "\n";
	}

	return 0;		
}