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
};



struct Vector
{
    double x, y;
    Vector(){}
};


struct Line
{
    double a, b, c;
    Line(){}
    double operator [](Point x)
    {
        return a * x.x + b * x.y + c;
    }
};

struct Ray
{
    Point a, b;
    Ray(){}
};

struct Segment
{
    Point a, b;
    Segment(){}
};

enum TypeOfIntersect {EMPTY, POINT, INF}; 

//constructors{
    //Point:
	Point GetPoint(double _x, double _y);
    //Vector
	Vector GetVector(double _x, double _y);
    //Line:
	Line GetLine(double _a, double _b, double _c);
	Line GetLine(Point x, Point y);
	Line GetLine(Point x, Vector z);
	Line GetLine(Ray a);
	Line GetLine(Segment a);
    //Segment:
	Segment GetSegment(Point _a, Point _b);
    //Ray:
	Ray GetRay(Point _a, Point _b);
	Ray GetRay(Point _a, Point _b);
//}

//another Gets{
    //Point:
	Point GetPointOnThisLine(Line a);
    //Vector: 
	Vector GetNormal(Line a);
	Vector GetDrective(Line a);
    //TypeOfIntersect:
	TypeOfIntersect GetTypeOfIntersect(Line a, Line b);
    //Line:
	Line GetNorm(Line a);
//}

//equals{
    //double
	bool Equal(double a, double b);
    //Point:
	bool operator == (Point a, Point b);
    //Vector:
	bool operator == (Vector a, Vector b);
    //Line:
	bool operator == (Line a, Line b);
//}

//in/out{
    //Point:
	istream& operator >> (istream& _in, Point& a);
	ostream& operator << (ostream& _out, Point a);
    //Vector:
	istream& operator >> (istream& _in, Vector& a);
    //Segment:
	istream& operator >> (istream& _in, Segment& a);
	ostream& operator << (ostream& _out, Segment a);
//}

//operators{
    //Vector:
	Vector operator + (Vector a, Vector b);
	Vector operator * (Vector a, double b);
	Vector operator * (double a, Vector b);
	Vector operator / (Vector a, double b);
	Vector operator - (Point a, Point b);
    //Line:
	Line operator * (Line a, double b);
	Line operator / (Line a, double b);
    //double:
	double operator * (Vector a, Vector b);
	double operator ^ (Vector a, Vector b);
//}

//lens{
    //Vector:
	double Len(Vector a);
//}

//dists{
    double Dist(Line a, Line b);
    double Dist(Line a, Point b);
    double Dist(Point a, Line b);
    double Dist(Point a, Point b);
    double Dist(Ray a, Point b);
    double Dist(Point a, Ray b);
    double Dist(Segment a, Point b);
    double Dist(Point a, Segment b);
//}

//serv{
    double serv_Det(double a, double b, double c, double d);
//}

//intersections{
    bool OnLine(Line a, Point b);
    Point Intersect(Line a, Line b);
    bool OnRay(Ray a, Point b);
    bool OnSegment(Segment a, Point b);
//}

bool Equal(double a, double b)
{
    return abs(a - b) < EPS;
}

Point GetPoint(double _x, double _y)
{
    Point a;
    a.x = _x;
    a.y = _y;
    return a;
}

bool operator == (Point a, Point b)
{
    return Equal(a.x, b.x) and Equal(a.y, b.y);
}

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

Vector GetVector(double _x, double _y)
{
    Vector x;
    x.x = _x;
    x.y = _y;
    return x;
}

bool operator == (Vector a, Vector b)
{
    return (Equal(b.x, a.x) and Equal(b.y, a.y));
}

double Len(Vector a)
{
    return sqrt(a.x * a.x + a.y * a.y);
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

Vector operator + (Vector a, Vector b)
{
    return GetVector(a.x + b.x, a.y + b.y);
}

Point operator + (Point a, Vector b)
{
    return GetPoint(a.x + b.x, a.y + b.y);
}

Vector operator - (Point a, Point b)
{
    return GetVector(a.x - b.x, a.y - b.y);
}
Line GetLine(double _a, double _b, double _c)
{
    Line x;
    x.a = _a;
    x.b = _b;
    x.c = _c;
    return x;
}

Line GetLine(Point x, Point y)
{
    Line z;
    if (x == y)
	GeomLibTechOut += "Runtime Eror: try to get line by two eqal points in function: GetLine(Point, Point)\n";
    z.a = y.y - x.y;
    z.b = x.x - y.x;
    z.c = -z.a * x.x - z.b * x.y;
    return z;
}

Line GetLine(Point x, Vector z)
{
    Line k;
    Point y = x + z;
    if (x == y)
	GeomLibTechOut += "Runtime Eror: try to get line by two eqal points in function: Line(Point, Vector)\n";
    k.a = y.y - x.y;
    k.b = x.x - y.x;
    k.c = -k.a * x.x - k.b * x.y;
    return k;
}
Segment GetSegment(Point _a, Point _b)
{
    Segment ans;
    if (_a == _b)
    {
	GeomLibTechOut += "Runtime Eror: try to get segment by two eqal points in constructor: Segment(Point, Point)\n";
    }
    ans.a = _a;
    ans.b = _b;
    return ans;
}


Vector operator * (Vector a, double b)
{
    return GetVector(a.x * b, a.y * b);
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


//Line operators
bool OnLine(Line a, Point b)
{
    return Equal(a[b], 0);
}

Line operator * (Line a, double b)
{
    return GetLine(a.a * b, a.b * b, a.c * b);
}

Point GetPointOnThisLine(Line a)
{
    if (Equal(a.b, 0))
    {
        return GetPoint(-a.c / a.a, 0);
    }
    return GetPoint(0, -a.c / a.b);
}

Line operator / (Line a, double b)
{
    return a * (1 / b);
}

Vector GetNormal(Line a)
{
    return GetVector(a.a, a.b);
}

Vector GetDrective(Line a)
{
    return GetVector(-a.b, a.a);
}

Line GetNorm(Line a)
{
    return a / (Len(GetNormal(a)));
}

bool operator == (Line a, Line b)
{
    a = GetNorm(a);
    b = GetNorm(b);
    return Equal(a.a, b.a) and Equal(a.b, b.b)and Equal(a.c, b.c);
}

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
        return GetPoint(0, 0);
    }
    return GetPoint(-serv_Det(a.c, a.b, b.c, b.b) / serv_Det(a.a, a.b, b.a, b.b), -serv_Det(a.a, a.c, b.a, b.c) /  serv_Det(a.a, a.b, b.a, b.b));
}


Line GetLine(Ray a)
{
    return GetLine(a.a, a.b);
}

bool OnRay(Ray a, Point b)
{
    return ((a.b - a.a) / Len(a.b - a.a) == (b - a.a) / Len(b - a.a));
}

//Dists
double Dist(Line a, Line b)
{
    if (GetTypeOfIntersect(a, b) != EMPTY)
        return 0;
    else
    {
        return abs(Norm(a).c - Norm(b).c);
    }
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

double Dist(Point a, Point b)
{
    return Len(a - b);
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
    return GetLine(a.a, a.b);
}

bool OnSegment(Segment a, Point b)
{
    return OnRay(GetRay(a.a, a.b), b) and OnRay(GetRay(a.b, a.a), b);
}

double Dist(Segment a, Point b)
{
    return max(Dist(GetRay(a.a, a.b), b), Dist(GetRay(a.b, a.a), b));
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
