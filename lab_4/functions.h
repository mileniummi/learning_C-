#pragma once
#include <iostream> 
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
class IGeoFig {
public:
	virtual double square() = 0;
	virtual double perimeter() = 0;
};

class CVector2D {
public:
	double x, y;
	void assign(int a, int b);
};

class IPhysObject {
public:
	double mass_  = 0;
	virtual double mass() = 0;
	virtual CVector2D position() = 0;
	virtual bool operator== (const IPhysObject& ob) const = 0;
	virtual bool operator< (const IPhysObject& ob) const = 0;
};

class IPrintable {
public:
	virtual void draw() = 0;
};

class IDialogInitiable {
public:
	virtual void initFromDialog() = 0;
};
class BaseCObject {
public:
	virtual string classname() = 0;
	virtual unsigned int size() = 0;
};

class IFigure : public IGeoFig, public IDialogInitiable, public IPhysObject, public IPrintable, public BaseCObject {
};

double get_dist(CVector2D a, CVector2D b);

class Circle :public IFigure {
private:
	double R_;
	CVector2D center_;
	string classname_ = "Circle";
public:
	Circle();
	Circle(double r, double x, double y);
	double square() override;
	double perimeter() override;
	double mass() override;
	CVector2D position() override;
	bool operator== (const IPhysObject& ob) const override;
	bool operator< (const IPhysObject& ob) const override;
	void draw()override;
	void initFromDialog() override;
	string  classname() override;
	unsigned int size()override;
};
class Trapezium :public IFigure {
private:
	CVector2D point_1;
	CVector2D point_2;
	CVector2D point_3;
	CVector2D point_4;
	CVector2D center_;
	double side_;
	double top_base_;
	double base_;
	double  height_;
	string classname_ = "Triangle";
public:
	Trapezium();
	double square() override;
	double perimeter() override;
	double mass() override;
	CVector2D position() override;
	bool operator== (const IPhysObject& ob) const override;
	bool operator< (const IPhysObject& ob) const override;
	void draw()override;
	void initFromDialog() override;
	string classname();
	unsigned int size() override;	
};

bool cmp(IFigure* a, IFigure* b);