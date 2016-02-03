#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const double EPS = 1e-5;

struct Point
{
    double x, y;
    Point(double _x, double _y)
    {
       x = _x;
       y = _y;
    }
};

struct Vector
{
    double x, y;
    Vector(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
};

//cin, cout overload to Point and Vector
istream& operator >> (istream& _in, Point& a)
{
   _in >> a.x >> a.y;
   return _in;
}

ostream& operator << (ostream& _out, Point a)
{
    _out << a.x << " " << a.y;
    return _out;
}

istream& operator >> (istream& _in, Vector& a)
{
   _in >> a.x >> a.y;
   return _in;
}

ostream& operator << (ostream& _out, Vector a)
{
    _out << a.x << " " << a.y;
    return _out;
}

//simple operators for Point and Vector
Vector operator - (Point a, Point b)
{
    return Vector(a.x - b.x, a.y - b.y);
}

Vector operator + (Vector a, Vector b)
{
    return Vector(a.x + b.x, a.y + b.y);
}

Point operator + (Point a, Vector b)
{
    return Point(a.x + b.x, a.y + b.y);
}

bool Equal(double a, double b)
{
    return abs(a - b) < EPS;
}

bool operator == (Point a, Point b)
{
    return Equal(a.x, b.x) and Equal(a.y, b.y);
}

bool operator == (Vector a, Vector b)
{
    return Equal(a.x, b.x) and Equal(a.y, b.y);
}

Vector operator * (Vector a, double b)
{
    return Vector(a.x * b, a.y * b);
}

Vector operator / (Vector a, double b)
{
    return a * (1 / b);
}

double operator * (Vector a, Vector b)
{
    return a.x * b.x * a.y * b.y;
}

double operator ^ (Vector a, Vector b)
{
    return a.x * b.y - a.y * b.x;
}

struct Line
{
    double a, b, c;
    Line(Point x, Point y)
    {
        a = y.y - x.y;
        b = x.x - y.x;
        c = -a * x.x - b * x.y;
    }
    Line(Point x, Vector y)
    {
        Line(x, x + y);
    }
};


int main()
{
}
