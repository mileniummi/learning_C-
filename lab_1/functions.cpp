#include"functions.h"
#include<string>
using namespace std;

void inc_pointer(int* a, int* b) {
	*a += *b;
	string h;
}
void inc_reference(int& a, int& b) {
	a += b;
}
void sign_change_pr(int* a) {
	*a *= -1;
}
void sign_change_ref(int& a) {
	a *= -1;
}

void matrix_multiply_pr(double* a, double var)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i * 3 + j] = a[i * 3 + j] * var;
		}
	}
}

void matrix_multiply_ref(double (&matrix)[3][3], double var)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] += var;
		}
	}
}

void altr_complex_pr(complex *var) {
	var->Im_z *= -1;
}
void altr_complex_ref(complex& var) {
	var.Im_z *= -1;
}

complex::complex(int re_z, int im_z)
{
	Re_z = re_z;
	Im_z = im_z;
}

void complex::print()
{
	cout << Re_z;
	if (Im_z != 0) {
		if (Im_z > 0) {
			cout << '+';
		}
		cout << Im_z << 'i' << "\n";
	}

}
