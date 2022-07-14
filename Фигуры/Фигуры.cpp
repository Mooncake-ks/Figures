#include <iostream>
#include <cmath>

const double PI =
3.141592653589793;

class Figure
{
public:
	virtual double area()const=0;
	virtual double perimeter()const=0;
	virtual void scale(const int& x) = 0;

};

class Square:public Figure
{
public:
	Square();
	Square(const double& a);

	double area()const override;
	double perimeter()const override;
	void scale(const int& x)override;
protected:
	double m_a;
};

class Rectangle:public Square
{
public:
	Rectangle();
	Rectangle(const double& a, const double& b);

	double area()const override;
	double perimeter()const override;
	void scale(const int& x)override;
protected:
	double m_b;
};

class Triangle : public Rectangle
{
public:
	Triangle();
	Triangle(const double& a, const double& b, const double& c);

	double area()const override;
	double perimeter()const override;
	void scale(const int& x)override;
private:
	double m_c;
};

class Clircle:public Figure
{
public:
	Clircle();
	Clircle(const double& r);

	double area()const override;
	double perimeter()const override;
	void scale(const int& x)override;
protected:
	double m_r;
};

class Ellipse:public Clircle
{
public:
	Ellipse();
	Ellipse(const double& min_r, const double& max_r);

	double area()const override;
	double perimeter()const override;
	void scale(const int& x)override;
private:
	double m_max_r;
};


void show(Figure& other);

int main()
{
	Rectangle a(3,5);
	Square b(6);
	Triangle c(12,13,14);
	Clircle t(5);
	Ellipse e(2, 4);
	a.scale(2);
	show(a);
    return 0;
}

Square::Square() :m_a{ 0 } {}
Square::Square(const double& a) : m_a{a} {}

double Square::area()const
{
	return std::pow(m_a,2);
}
double Square::perimeter()const
{
	return m_a*4;
}
void Square::scale(const int& x)
{
	m_a *= x;
}


Rectangle::Rectangle() : m_b{ 0 } {}
Rectangle::Rectangle(const double& a, const double& b) : Square(a), m_b{b} {}

double Rectangle::area()const
{
	return m_a*m_b;
}
double Rectangle::perimeter()const
{
	return (m_a+m_b)*2;
}
void Rectangle::scale(const int& x)
{
	m_a *= x;
	m_b *= x;
}


Triangle::Triangle() :m_c{0} {}
Triangle::Triangle(const double& a, const double& b, const double& c) : Rectangle(a, b), m_c{c} {}

double Triangle::area() const
{
	double p = (this->perimeter()) / 2;
	return sqrt(p*(p-m_a)*(p-m_b)*(p-m_c));
}
double Triangle::perimeter() const
{
	return m_a+m_b+m_c;
}

void Triangle::scale(const int& x)
{
	m_a *= x;
	m_b *= x;
	m_c *= x;
}

Clircle::Clircle():m_r { 0 }{}
Clircle::Clircle(const double& r) :m_r{r} {}

double Clircle::area() const
{
	return PI*pow(m_r,2);
}
double Clircle::perimeter() const
{
	return 2 * PI * m_r;
}
void Clircle::scale(const int& x)
{
	m_r *= x;
}

Ellipse::Ellipse() :m_max_r{0} {}
Ellipse::Ellipse(const double& min_r, const double& max_r) : Clircle(min_r), m_max_r{max_r}{}

double Ellipse::area() const
{
	return PI*m_r*m_max_r;
}
double Ellipse::perimeter() const
{
	return 4*((PI*m_r*m_max_r+(m_max_r-m_r))/(m_r+m_max_r));
}

void Ellipse::scale(const int& x)
{
	m_max_r *= x;
	m_r *= x;
}

void show(Figure& f)
{
	std::cout << "Area  =" << f.area() << std::endl;
	std::cout << "Perimeter  =" << f.perimeter() << std::endl;
}