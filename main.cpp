#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

const double EPS = 1e-5;

struct Point/*{{{*/
{
    double x, y; 
    Point(){}
};/*}}}*/

struct Vector/*{{{*/
{
    double x, y;
    Vector(){}
};/*}}}*/

struct Line/*{{{*/
{
    double a, b, c;
    Line(){}
    double operator [](Point x)
    {
        return a * x.x + b * x.y + c;
    }
};/*}}}*/

struct Ray/*{{{*/
{
    Point a, b;
    Ray(){}
};/*}}}*/

struct Segment/*{{{*/
{
    Point a, b;
    Segment(){}
};/*}}}*/

//announcement

//constructors{{{
    //Point{{{
	Point GetPoint(double _x, double _y);
	Point GetPoint(Vector a);
    //}}}

    //Vector{{{
	Vector GetVector(double _x, double _y);
	Vector GetVector(Point a);
	Vector GetVector(Segment a);
	Vector GetVector(Point a, Point b);
    //}}}

    //Lin{{{
	Line GetLine(double _a, double _b, double _c);
	Line GetLine(Point x, Point y);
	Line GetLine(Point x, Vector z);
	Line GetLine(Ray a);
	Line GetLine(Segment a);
    //}}}

    //Segment{{{
	Segment GetSegment(Point _a, Point _b);
	Segment GetSegment(Point _a, Vector b);
    //}}}

    //Ray{{{
	Ray GetRay(Point _a, Point _b);
    //}}}
//}}}

//another Gets{{{
    //Point{{{
	Point GetPointOnThisLine(Line a);
    //}}}

    //Vector{{{
	Vector GetNormal(Line a);
	Vector GetDrective(Line a);
    //}}}

    //Line{{{
	Line GetNorm(Line a);	
    //}}}
//}}}

//equals{{{
    //double{{{
	bool Equal(double a, double b);
    //}}}

    //Point{{{
	bool operator == (Point a, Point b);
    //}}}

    //Vector{{{
	bool operator == (Vector a, Vector b);
    //}}}

    //Line{{{
	bool operator == (Line a, Line b);
    //}}}

    //Ray{{{
	bool operator == (Ray a, Ray b);
    //}}}

    //Segment{{{
	bool operator == (Segment a, Segment b);
    //}}}
//}}}

//in/out{{{
    //Point{{{
	istream& operator >> (istream& _in, Point& a);
	ostream& operator << (ostream& _out, Point a);
    //}}}
	
    //Vector{{{
	istream& operator >> (istream& _in, Vector& a);
	ostream& operator << (ostream& _in, Vector a);
    //}}}

    //Segment{{{
	istream& operator >> (istream& _in, Segment& a);
	ostream& operator << (ostream& _out, Segment a);
    //}}}

    //Ray{{{
	istream& operator >> (istream& _in, Ray& a);
	ostream& operator << (ostream& _out, Ray a);
    //}}}
//}}}

//operators{{{
    //Point{{{
	Point operator + (Point a, Vector b);
    //}}}
	
    //Vector{{{
	Vector operator + (Vector a, Vector b);
	Vector operator * (Vector a, double b);
	Vector operator * (double a, Vector b);
	Vector operator / (Vector a, double b);
	Vector operator - (Point a, Point b);
    //}}}

    //Line{{{
	Line operator * (Line a, double b);
	Line operator / (Line a, double b);
    //}}}

    //double{{{
	double operator * (Vector a, Vector b);
	double operator ^ (Vector a, Vector b);
    //}}}
//}}}

//lens{{{
    //Vector{{{
	double Len(Vector a);
    //}}}

    //Segment{{{
	double Len(Segment a);
    //}}}
//}}}

//dists{{{
    double Dist(Line a, Ray b);
    double Dist(Line a, Line b);
    double Dist(Line a, Point b);
    double Dist(Point a, Line b);
    double Dist(Point a, Point b);
    double Dist(Ray a, Point b);
    double Dist(Point a, Ray b);
    double Dist(Segment a, Point b);
    double Dist(Point a, Segment b);
//}}}

//serv{{{
    double serv_Det(double a, double b, double c, double d);
//}}}

//intersections{{{
    vector<Point> Intersect(Line a, Line b);
    vector<Point> Intersect(Line a, Ray b);
    vector<Point> Intersect(Line a, Point b);
    vector<Point> Intersect(Ray a, Point b);
    vector<Point> Intersect(Segment a, Point b);
    vector<Point> Intersect(Line a, Segment b);
//}}}

//realization

//constructors{{{
    //Point{{{
	Point GetPoint(double _x, double _y)
	{
	    Point a;
	    a.x = _x;
	    a.y = _y;
	    return a;
	}
	Point GetPoint(Vector a)
	{
	    Point b;
	    b.x = a.x;
	    b.y = a.y;
	    return b;
	}
    //}}}

    //Vector{{{
	Vector GetVector(double _x, double _y)
	{
	    Vector x;
	    x.x = _x;
	    x.y = _y;
	    return x;
	}
	Vector GetVector(Point a)
	{
	    return GetVector(a.x, a.y);
	}
	Vector GetVector(Segment a)
	{
	    return a.b - a.a;
	}
	Vector GetVector(Point a, Point b)
	{
	    return b - a;
	}
    //}}}

    //Line{{{
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
	    z.a = y.y - x.y;
	    z.b = x.x - y.x;
	    z.c = -z.a * x.x - z.b * x.y;
	    return z;
	}

	Line GetLine(Point x, Vector z)
	{
	    Line k;
	    Point y = x + z;
	    k.a = y.y - x.y;
	    k.b = x.x - y.x;
	    k.c = -k.a * x.x - k.b * x.y;
	    return k;
	}
	Line GetLine(Ray a)
	{
	    return GetLine(a.a, a.b);
	}
	Line GetLine(Segment a)
	{
	    return GetLine(a.a, a.b);
	}
    //}}}

    //Segment{{{
	Segment GetSegment(Point _a, Point _b)
	{
	    Segment ans;
	    ans.a = _a;
	    ans.b = _b;
	    return ans;
	}
	Segment GetSegment(Point _a, Vector _b)
	{
	    return GetSegment(_a, _a + _b);
	}
    //}}}

    //Ray{{{
	Ray GetRay(Point a, Point b)
	{
	    Ray ans;
	    ans.a = a;
	    ans.b = b;
	    return ans;
	}
    //}}}
//}}}

//another Gets{{{
    //Point{{{
	Point GetPointOnThisLine(Line a)
	{
	    if (Equal(a.b, 0))
	    {
		return GetPoint(-a.c / a.a, 0);
	    }
	    return GetPoint(0, -a.c / a.b);
	}
    //}}}

    //Vector{{{
	Vector GetNormal(Line a)
	{
	    return GetVector(a.a, a.b);
	}

	Vector GetDrective(Line a)
	{
	    return GetVector(-a.b, a.a);
	}
    //}}}

    //Line{{{
	Line GetNorm(Line a)
	{
	    return a / (Len(GetNormal(a)));
	}
    //}}}
//}}}

//equals{{{
    //double{{{
	bool Equal(double a, double b)
	{
	    return abs(a - b) < EPS;
	}
    //}}}

    //Point{{{
	bool operator == (Point a, Point b)
	{
	    return Equal(a.x, b.x) and Equal(a.y, b.y);
	}
    //}}}

    //Vector{{{
	bool operator == (Vector a, Vector b)
	{
	    return (Equal(b.x, a.x) and Equal(b.y, a.y));
	}
    //}}}

    //Line{{{
	bool operator == (Line a, Line b)
	{
	    a = GetNorm(a);
	    b = GetNorm(b);
	    return Equal(a.a, b.a) and Equal(a.b, b.b)and Equal(a.c, b.c);
	}
    //}}}

    //Ray{{{
	bool operator == (Ray a, Ray b)
	{
	    return (a.a == b.a and a.b == b.b);
	}
    //}}}

    //Segment{{{
	bool operator == (Segment a, Segment b)
	{
	    return (a.a == b.a and a.b == b.b) or (a.a == b.b and a.b == b.a);
	}
    //}}}
//}}}

//in/out{{{
    //Point{{{
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
    //}}}

    //Vector{{{
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
    //}}}

    //Segment{{{
	istream& operator >> (istream& _in, Segment& a)
	{
	    _in >> a.a >> a.b;
	    return _in;
	}

	ostream& operator << (ostream& _out, Segment a)
	{
	    _out << a.a << " " << a.b;
	    return _out;
	}
    ///}}}

    //Ray{{{
	istream& operator >> (istream& _in, Ray& a)
	{
	    _in >> a.a >> a.b;
	    return _in;
	}

	ostream& operator << (ostream& _out, Ray a)
	{
	    _out << a.a << " " << a.b;
	    return _out;
	}
    //}}}

///}}}

//operators{{{
    //Point{{{
	Point operator + (Point a, Vector b)
	{
	    return GetPoint(a.x + b.x, a.y + b.y);
	}
    //}}}

    //Vector{{{
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

	Vector operator + (Vector a, Vector b)
	{
	    return GetVector(a.x + b.x, a.y + b.y);
	}

	Vector operator - (Point a, Point b)
	{
	    return GetVector(a.x - b.x, a.y - b.y);
	}
    //}}}

    //Line{{{
	Line operator * (Line a, double b)
	{
	    return GetLine(a.a * b, a.b * b, a.c * b);
	}

	Line operator / (Line a, double b)
	{
	    return a * (1 / b);
	}
    //}}}

    //double{{{
	double operator * (Vector a, Vector b)
	{
	    return a.x * b.x * a.y * b.y;
	}
	double operator ^ (Vector a, Vector b)
	{
	    return a.x * b.y - a.y * b.x;
	}
    //}}}
//}}}

//lens{{{
    //Vector{{{
	double Len(Vector a)
	{
	    return sqrt(a.x * a.x + a.y * a.y);
	}
    //}}}

    //Segments{{{
	double Len(Segment a)
	{
	    return Len(a.a - a.b);
	}
    //}}}
//}}}

//dists{{{
    double Dist(Line a, Line b)
    {
	if (!Intersect(a, b).empty())
	    return 0;
	else
	{
	    return abs(GetNorm(a).c - GetNorm(b).c);
	}
    }

    double Dist(Line a, Point b)
    {
	a = GetNorm(a);
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
	if (!Intersect(a, b).empty())
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
    double Dist(Segment a, Point b)
    {
	return max(Dist(GetRay(a.a, a.b), b), Dist(GetRay(a.b, a.a), b));
    }

    double Dist(Point a, Segment b)
    {
	return Dist(b, a);
    }

//}}}

//serv{{{
    double serv_Det(double a, double b, double c, double d)
    {
	return a * d - b * c;
    }
//}}}

//intersections{{{
    vector<Point> Intersect(Line a, Ray b)/*{{{*/
    {
	vector<Point> ans;
	if (a == GetLine(b))
	{
	    return vector<Point>({b.a});
	}
	ans = Intersect(a, GetLine(b));
	if (ans.empty() or !Intersect(b, ans[0]).empty())
	    return ans;
	else
	    return vector<Point>();
    }/*}}}*/

    vector<Point> Intersect(Line a, Line b)/*{{{*/
    {
	if (a == b)
	{
	    return vector<Point>({GetPointOnThisLine(a)});
	}
	if (Equal(a.a / b.a, a.b / b.b))
	{
	    return vector<Point>();
	}
	return vector<Point>({GetPoint(-serv_Det(a.c, a.b, b.c, b.b) / serv_Det(a.a, a.b, b.a, b.b),
		-serv_Det(a.a, a.c, b.a, b.c) /  serv_Det(a.a, a.b, b.a, b.b))});
    }/*}}}*/

    vector<Point>Intersect(Ray a, Point b)/*{{{*/
    {
	if (Equal((a.b - a.a) ^ (b - a.a), 0) and (a.b - a.a) * (b - a.a) > -EPS)
	{
	    return vector<Point> ({b});
	}
	return vector<Point>{};
    }/*}}}*/

    vector<Point> Intersect(Line a, Point b)/*{{{*/
    {
	if (Equal(a[b], 0))
	{
	    return {b};
	}
	return {};
    }/*}}}*/

    vector<Point> Intersect(Segment a, Point b)/*{{{*/
    {
	if (!Intersect(GetRay(a.a, a.b), b).empty() and !Intersect(GetRay(a.b, a.a), b).empty())
	    return {b};
	else
	    return {};
    }/*}}}*/

    vector<Point> Intersect(Line a, Segment b)/*{{{*/
    {
	vector<Point> ans1 = Intersect(a, GetRay(b.a, b.b));
	vector<Point> ans2 = Intersect(a, GetRay(b.b, b.a));
	if (ans1.empty() or ans2.empty())
	    return {};
	else
	    return ans1;
    }/*}}}*/
//}}}

int main()
{
}
