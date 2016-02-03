#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

const double EPS = 1e-5;

string GeomLibTechOut = "";

struct Point
{
    double x, y;
    Point(){}
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
};

struct Vector
{
    double x, y;
    Vector(){}
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

double Len(Vector a)
{
    return sqrt(a.x * a.x + a.y * a.y);
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
    Line(){}
    Line(double _a, double _b, double _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }
    Line(Point x, Point y)
    {
        if (x == y)
            GeomLibTechOut += "Runtime Eror: try to get line by two eqal points in constructor: Line(Point, Point)\n";
        a = y.y - x.y;
        b = x.x - y.x;
        c = -a * x.x - b * x.y;
    }
    Line(Point x, Vector z)
    {
        Point y = x + z;
        if (x == y)
            GeomLibTechOut += "Runtime Eror: try to get line by two eqal points in constructor: Line(Point, Vector)\n";
        a = y.y - x.y;
        b = x.x - y.x;
        c = -a * x.x - b * x.y;
    }
    double operator [](Point x)
    {
        return a * x.x + b * x.y + c;
    }
};

//Line operators
bool OnLine(Line a, Point b)
{
    return Equal(a[b], 0);
}

Line operator * (Line a, double b)
{
    return Line(a.a * b, a.b * b, a.c * b);
}

Point GetPointOnThisLine(Line a)
{
    if (Equal(a.b, 0))
    {
        return Point(-a.c / a.a, 0);
    }
    return Point(0, -a.c / a.b);
}

Line operator / (Line a, double b)
{
    return a * (1 / b);
}

Vector GetNormal(Line a)
{
    return Vector(a.a, a.b);
}

Vector GetDrective(Line a)
{
    return Vector(-a.b, a.a);
}

Line Norm(Line a)
{
    return a / (Len(GetNormal(a)));
}

bool operator == (Line a, Line b)
{
    a = Norm(a);
    b = Norm(b);
    return Equal(a.a, b.a) and Equal(a.b, b.b)and Equal(a.c, b.c);
}

double Dist(Line a, Point b)
{
    a = Norm(a);
    return a[b];
}

enum TypeOfIntersect {EMPTY, POINT, INF}; 

TypeOfIntersect GetTypeOfIntersect(Line a, Line b)
{
    if (a == b)
        return INF;
    if (Equal(a.a / b.a, a.b / b.b))
        return EMPTY;
    return POINT;
}

double serv_Det(double a, double b, double c, double d)
{
    return a * d - b * c;
}

Point Intersect(Line a, Line b)
{
    if (GetTypeOfIntersect(a, b) == INF)
    {
        return GetPointOnThisLine(a);
    }
    if (GetTypeOfIntersect(a, b) == EMPTY)
    {
        GeomLibTechOut += "Runtime Eror: try to get element of empty set in function: Intersect(Line, Line)\n";
        return Point(0, 0);
    }
    return Point(-serv_Det(a.c, a.b, b.c, b.b) / serv_Det(a.a, a.b, b.a, b.b), -serv_Det(a.a, a.c, b.a, b.c) /  serv_Det(a.a, a.b, b.a, b.b));
}

int main()
{
    Point a, b, c;
    cin >> a >> b >> c; 
    Line f(a, b), s(a, c);
    Point ans = Intersect(f, s);
    cout << (ans == a) << endl;
    cout << GeomLibTechOut;
}
