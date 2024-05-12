#include <iostream>

class Base
{
protected:
	int dat;
public:
	Base() : dat(1) {}
	Base(int d) : dat(d) {}
};
class D1 : protected Base
{
protected:
	int d1;
public:
	D1() : d1(1) {}
	D1(int d) : d1(d) {}
	D1(int d, int dt) : Base(dt), d1(d) {}
};
class D2 : protected Base
{
protected:
	double d2;
public:
	D2() : d2(1) {}
	D2(int d) : d2(d) {}
	D2(int d, double dt) : Base(d), d2(dt) {}
};
class D11 : protected D1
{
protected:
	double dt;
public:
	D11() : dt(1) {}
	D11(int d) : dt(d) {}
	D11(int a, int b, int e) : D1(a, b), dt(e) {}
};
class D22 : protected D2
{
protected:
	double dt;
public:
	D22() : dt(1) {}
	D22(int d) : dt(d) {}
	D22(int c, int d, int e) : D2(c, d), dt(e) {}
};
class R : protected D11, protected D22, protected D2
{
protected:
	double dt;

public:
	R() : dt(1) {}
	R(int d) : dt(d) {}
	R(int a, int b, int c, double d, int e) : D11(a, b, e), D22(c, d, e), D2(c, d), dt(e + 1.) {}

	void showDat()
	{
		std::cout << "dat from D11: " << D11::dat << std::endl;
		std::cout << "dat from D22: " << D22::dat << std::endl;
		std::cout << "dat from D2: " << D2::dat << std::endl;
	}
};
// virtual
//
class D1V : virtual protected Base
{
protected:
	int d1;
public:
	D1V() : d1(1) {}
	D1V(int d) : d1(d) {}
	D1V(int d, int dt) : Base(dt), d1(d) {}
};
class D2V : virtual protected Base
{
protected:
	double d2;
public:
	D2V() : d2(1) {}
	D2V(int d) : d2(d) {}
	D2V(int d, double dt) : Base(d), d2(dt) {}
};
class D11V : virtual protected D1V
{
protected:
	double dt;
public:
	D11V() : dt(1) {}
	D11V(int d) : dt(d) {}
	D11V(int a, int b, int e) : D1V(a, b),  dt(e) {}
};
class D22V : virtual protected D2V
{
protected:
	double dt;
public:
	D22V() : dt(1) {}
	D22V(int d) : dt(d) {}
	D22V(int c, int d, int e) : D2V(c, d), dt(e) {}
};
class RV : virtual protected D11V, virtual protected D22V, virtual protected D2V
{
protected:
	double dt;
public:
	RV() : dt(1) {}
	RV(int d) : dt(d) {}
	RV(int a, int b, int c, double d, int e) : D11V(a, b, e), D22V(c, d, e), D2V(c, d), dt(e + 1.) {}
	void showDat()
	{
		std::cout << "dat from D11V: " << D11V::dat << std::endl;
		std::cout << "dat from D22V: " << D22V::dat << std::endl;
		std::cout << "dat from D2V: " << D2V::dat << std::endl;
	}
};


class Quadrilateral {
public:
	virtual double calculateArea() const = 0;
	virtual double calculatePerimeter() const = 0;
};

class Square : public Quadrilateral {
private:
	double side;
public:
	Square(double s) : side(s) {}

	double calculateArea() const override {
		return side * side;
	}

	double calculatePerimeter() const override {
		return 4 * side;
	}
};

class Rectangle : public Quadrilateral {
private:
	double length;
	double width;
public:
	Rectangle(double l, double w) : length(l), width(w) {}

	double calculateArea() const override {
		return length * width;
	}

	double calculatePerimeter() const override {
		return 2 * (length + width);
	}
};

class Parallelogram : public Quadrilateral {
private:
	double base;
	double height;
public:
	Parallelogram(double b, double h) : base(b), height(h) {}

	double calculateArea() const override {
		return base * height;
	}

	double calculatePerimeter() const override {
		return 2 * (base + height);
	}
};

class Trapezoid : public Quadrilateral {
private:
	double base1;
	double base2;
	double height;
	double side1;
	double side2;
public:
	Trapezoid(double b1, double b2, double h, double s1, double s2) : base1(b1), base2(b2), height(h), side1(s1), side2(s2) {}

	double calculateArea() const override {
		return (base1 + base2) * height / 2;
	}

	double calculatePerimeter() const override {
		return base1 + base2 + side1 + side2;
	}
};


int main () {
	 int choice;
std::cout << "Choose the operation: \n1. 1\n2. 2\n";
std::cin >> choice;
if (choice == 1) {
	R a, b(1, 2, 3, 4.5, 5);
	RV av, bv(1, 2, 3, 4.5, 5);
	std::cout << "Test !\n";
	std::cout << "Size for Base " << sizeof(Base) << std::endl;
	std::cout << "Size for D1 " << sizeof(D1) << std::endl;
	std::cout << "Size for D2 " << sizeof(D2) << std::endl;
	std::cout << "Size for D12 " << sizeof(D11) << std::endl; // Виправлено на D11
	std::cout << "Size for R " << sizeof(R) << std::endl;
	std::cout << "Size for Base " << sizeof(Base) << std::endl;
	std::cout << "Size for D1V " << sizeof(D1V) << std::endl;
	std::cout << "Size for D2V " << sizeof(D2V) << std::endl;
	std::cout << "Size for D12V " << sizeof(D11V) << std::endl; // Виправлено на D11V
	std::cout << "Size for RV " << sizeof(RV) << std::endl;
	std::cout << "Size for object class R " << sizeof(R) << " or "
		<< sizeof(a) << " or " << sizeof(b) << std::endl;
	std::cout << "Size for object class RV " << sizeof(RV) << " or "
		<< sizeof(av) << " or " << sizeof(bv) << std::endl;
	b.showDat();
	bv.showDat();
 }
else if (choice == 2) {
	Square square(5);
	Rectangle rectangle(4, 6);
	Parallelogram parallelogram(5, 7);
	Trapezoid trapezoid(3, 6, 4, 5, 5);

	std::cout << "Square: Area = " << square.calculateArea() << ", Perimeter = " << square.calculatePerimeter() << std::endl;
	std::cout << "Rectangle: Area = " << rectangle.calculateArea() << ", Perimeter = " << rectangle.calculatePerimeter() << std::endl;
	std::cout << "Parallelogram: Area = " << parallelogram.calculateArea() << ", Perimeter = " << parallelogram.calculatePerimeter() << std::endl;
	std::cout << "Trapezoid: Area = " << trapezoid.calculateArea() << ", Perimeter = " << trapezoid.calculatePerimeter() << std::endl;


}else {
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
