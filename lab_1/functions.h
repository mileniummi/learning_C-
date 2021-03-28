#pragma once
#include<string>
#include<iostream>

using namespace std;
class complex {
public:
	int Re_z;
	int Im_z;
	complex(int re_z, int im_z);
	void print();
};

void inc_pointer(int*, int*);
void inc_reference(int&, int& );
void sign_change_pr(int*);
void sign_change_ref(int& );
void matrix_multiply_pr(double *matrix, double var);
void matrix_multiply_ref(double(&matrix)[3][3], double var);
void altr_complex_pr(complex* );
void altr_complex_ref(complex& );