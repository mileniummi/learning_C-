#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template <typename T>
bool if_odd( int a){
	return a % 2 == 1;
}



template<class Container, typename T>
bool any_of_(const Container start_, const Container last_, bool (p)(T param)) {
	for (auto it = start_; it != last_; it++) {
		if (p(*it))
			return true;
	}
	return false;
}

template<class Container, typename T>
bool one_of_(const Container start_, const Container last_, bool (p)(T param)) {
	int count = 0;	
	for (auto it = start_; it != last_; it++) {
		if (p(*it)) {
			count++;
		}
		if (count > 1) {
			return false;
		}
	}
	if (count == 1) {
		return true;
	}
	return false;
}
template<class Container, typename T>
T  find_not_(const Container start_, const Container last_, T a) {
	for (auto it = start_; it != last_; it++) {
		if (*it != a) {
			return *it;
		}
	}
	return a;
}

template<typename T>
bool Find(T value, T num)
{
	return (num == value);
}
class point {
public:
	int x;
	int y;
	point(int x_,int y_)
		:x(x_)
		,y(y_)
	{
	}

	const bool operator >(int a) {
		if (this->x > a&& this->y > a) {
			return true;
		}
		return false;
	};
	const bool operator ==(int a)
	{
		return (this->x == a && this->y == a);
	}
	point operator %(int a)
	{
		return point(x % a, y % a);
	}
};
	template <typename T>
	bool if_positive(T a) {
		return a > 0;
	}


int main() {
	vector <int> Array = { 1,  351, 244, 24, 34, 6, 78, 90};

	any_of_(Array.begin(), Array.end(), if_odd<int>) == 1 ? cout << "true\n" : cout << "false\n";
	one_of_(Array.begin(), Array.end(), if_odd<int>) == 1 ? cout << "true\n" : cout << "false\n";

	vector<double> Array2 = { 1.22, 1.22, 1.22, 1.44, 787.55 };
	vector<double> Array3 = { 1.22, 1.22, 1.22};
	double k = 1.22;

	cout  << find_not_(Array2.begin(), Array2.end(), k) << "\n";
	cout  << find_not_(Array.begin(), Array.end(), 1) << "\n";

	vector<point> Points;
	point a(1,2);
	point b(-10, -17);
	point c(-13, -46);
	Points.push_back(a);
	Points.push_back(b);
	Points.push_back(c);

	one_of_(Points.begin(), Points.end(), if_positive<point>) == 1 ? cout << "true\n" : cout << "false\n";
	any_of_(Points.begin(), Points.end(), if_odd<point>) == 1 ? cout << "true\n" : cout << "false\n";
	
	return 0;
}