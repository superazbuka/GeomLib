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

double Dist(Point a, Point b)
{
    return Len(a - b);
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

Vector operator * (double a, Vector b)
{
    return b * a;
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

double Dist(Point a, Line b)
{
    return Dist(b, a);
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

double Dist(Line a, Line b)
{
    if (GetTypeOfIntersect(a, b) != EMPTY)
        return 0;
    else
    {
        return abs(Norm(a).c - Norm(b).c);
    }
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

struct Ray
{
    Point a, b;
    Ray()
    {
        a = Point(0, 0);
        b = Point(0, 1);
    }
    Ray(Point _a, Point _b)
    {
        if (_a == _b)
            GeomLibTechOut += "Runtime Eror: try to get ray by two eqal points in constructor: Ray(Point, Point)\n";
        a = _a;
        b = _b;
    }
};

Line GetLine(Ray a)
{
    return Line(a.a, a.b);
}

bool OnRay(Ray a, Point b)
{
    return ((a.b - a.a) / Len(a.b - a.a) == (b - a.a) / Len(b - a.a));
}

double Dist(Ray a, Point b)
{
    if (OnRay(a, b))
    {
        return Dist(GetLine(a), b);
    }
    else
    {
        return Dist(a.a, b);
    }
}

double Dist(Point a, Ray b)
{
    return Dist(b, a);
}

struct Segment
{
    Point a, b;
    Segment()
    {
        a = Point(0, 0);
        b = Point(0, 1);
    }
    Segment(Point _a, Point _b)
    {
        if (_a == _b)
        {
            GeomLibTechOut += "Runtime Eror: try to get segment by two eqal points in constructor: Segment(Point, Point)\n";
        }
        a = _a;
        b = _b;
    }
};

istream& operator >> (istream& _in, Segment& a)
{
    _in >> a.b >> a.b;
    return _in;
}

ostream& operator << (ostream& _out, Segment a)
{
    _out << a.a << " " << a.b;
    return _out;
}

Line GetLine(Segment a)
{
    return Line(a.a, a.b);
}

bool OnSegment(Segment a, Point b)
{
    return OnRay(Ray(a.a, a.b), b) and OnRay(Ray(a.b, a.a), b);
}

double Dist(Segment a, Point b)
{
    return max(Dist(Ray(a.a, a.b), b), Dist(Ray(a.b, a.a), b));
}

double Dist(Point a, Segment b)
{
    return Dist(b, a);
}

int main()
{
    Vector a, b;
    cin >> a;
    cout << (a ^ (-1 * a)) << " " << (a ^ (2 * a)) << endl;
}
