#include <iostream>
#include <vector>

using namespace std;
template <typename T>
void template_swap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T1>
class matrix {
private:
	int M_;
	int N_;
	vector<vector<T1>> elements;
public:
	matrix(int M, int N)
		:M_(M)
		, N_(N)
	{
		elements.resize(M);
	}
	void fill() {
		T1 a;
		for (int i = 0; i < N_; i++) {
			for (int j = 0; j < M_; j++) {
				cin >> a;
				elements[i].push_back(a);
			}
		}
	}
	void draw() {
		for (int i = 0; i < N_; i++) {
			for (int j = 0; j < M_; j++) {
				cout << elements[i][j] << " ";
			}
			cout << "\n";
		}
	}
	const T1 get_number(size_t n, size_t m) {
		if (n >= N_ || m >= M_) {
			throw exception("Out of range");
		}
		return elements[n][m];
	}
};


int main() {
	int a = 10;
	int b = 20;
	template_swap(a, b);
	cout << a << "\n";
	cout << b << "\n";
	double c = 78.99;
	double d = 45.4545;
	template_swap(c, d);
	cout << c << "\n";
	cout << d << "\n";

	matrix<int> graph(3, 3);
	graph.fill();
	graph.draw();
	try
	{
		cout << graph.get_number(2, 3);
	}
	catch (const std::exception & ex)
	{
		cout << ex.what() << "\n";
	}


	try
	{
		cout << graph.get_number(2, 2);
	}
	catch (const std::exception & ex)
	{
		cout << ex.what() << "\n";
	}

}
