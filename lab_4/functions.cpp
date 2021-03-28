#include "functions.h"

Trapezium::Trapezium() = default;

double Trapezium::square()
{
	return (top_base_ + base_) / 2 * height_;
}

double Trapezium::perimeter()
{
	return side_ + side_ + top_base_ + base_;
}

double Trapezium::mass()
{
	return mass_;
}

CVector2D Trapezium::position()
{
	return center_;
}

bool Trapezium::operator==(const IPhysObject& ob) const
{
	if (this->mass_ == ob.mass_) {
		return true;
	}
	else {
		return false;
	}
}

bool Trapezium::operator<(const IPhysObject& ob) const
{
	if (this->mass_ < ob.mass_) {
		return true;
	}
	else {
		return false;
	}
}

void Trapezium::draw()
{
	cout << "Трапеция: \n";
	cout << "С боковыми стронами " << side_ << "\n";
	cout << "С верхним  основанием " << top_base_ << "\n";
	cout << "С нижним  основанием  " << base_ << "\n";
	cout << "С массой :" << mass_ << "\n";
}

void Trapezium::initFromDialog()
{
	int a, b, c, d, e, f, g, h;
	cout << "Ведите коорднинаты точки 1\n";
	cin >> a >> b;
	cout << "Ведите коорднинаты точки 2\n";
	cin >> c >> d;
	cout << "Ведите коорднинаты точки 3\n";
	cin >> e >> f;
	cout << "Ведите коорднинаты точки 4\n";
	cin >> g >> h;
	cout << "Введите массу\n";
	cin >> mass_;
	point_1.assign(a, b);
	point_2.assign(c, d);
	point_3.assign(e, f);
	point_3.assign(g, h);
	center_.assign((a + c + e + g) / 2, (b + d + f + h) / 2);
	side_ = get_dist(point_1, point_2);
	top_base_ = get_dist(point_2, point_3);
	base_ = get_dist(point_3, point_4);
	height_ = 0.5 * (sqrt(4 * side_ * side_ - (top_base_ - base_) * (top_base_ - base_)));
}

string Trapezium::classname()
{
	return this->classname_;
}

unsigned int Trapezium::size()
{
	return sizeof(CVector2D) * 5 + sizeof(double) * 4 + sizeof(classname_) + sizeof(mass_);
}

void CVector2D::assign(int a, int b)
{
	x = a;
	y = b;
}

Circle::Circle() = default;

Circle::Circle(double r, double x, double y)
	:R_(r)
{
		center_.x = x;
		center_.y = y;
}

double Circle::square()
{
	return 3.14 * R_ * R_;
}

double Circle::perimeter()
{
	
	return 2 * 3.14 * R_;
	
}

double Circle::mass()
{
	return mass_;
}

CVector2D Circle::position()
{
	return center_;
}

bool Circle::operator==(const IPhysObject& ob) const
{
	if (this->mass_ == ob.mass_) {
		return true;
	}
	else {
		return false;
	}
}

bool Circle::operator<(const IPhysObject& ob) const
{
	if (this->mass_ < ob.mass_) {
		return true;
	}
	else {
		return false;
	}
}

void Circle::draw()
{
	cout << "Круг с радиусом: \n";
	cout << R_ << "\n";
	cout << "С массой:" << "\n";
	cout << mass_ << "\n";
}

void Circle::initFromDialog()
{
	cout << "Введите радиус" << "\n";
	cin >> R_;
	cout << "Введите координаты центра" << "\n";
	cin >> center_.x >> center_.y;
	cout << "Введите массу" << "\n";
	cin >> mass_;
}

string Circle::classname()
{
	return this->classname_;
}

unsigned int Circle::size()
{
	return sizeof(CVector2D) + sizeof(double) + sizeof(classname_) + sizeof(mass_);
}

double get_dist(CVector2D a, CVector2D b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp(IFigure* a, IFigure* b)
{
	return a->mass_ < b->mass_;
}
