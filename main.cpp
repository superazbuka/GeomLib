#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef double FloatType;
const FloatType EPS = 1e-5;

class Point/*{{{*/
{
public:
    FloatType x, y; 
};/*}}}*/

class Vector/*{{{*/
{
public:
    FloatType x, y;
};/*}}}*/

class Line/*{{{*/
{
public:
    FloatType a, b, c;
    FloatType operator ()(Point x)
    {
        return a * x.x + b * x.y + c;
    }
};/*}}}*/

class Ray/*{{{*/
{
public:
    Point a, b; // maybe Point a, Vector v (v.x * v.x + v.y * v.y = 1)
};/*}}}*/

class Segment/*{{{*/
{
public:
    Point a, b;
};/*}}}*/

//announcement

//constructors{{{
    //Point{{{
	Point GetPoint(FloatType x, FloatType y);
	Point GetPoint(Vector v);
    //}}}

    //Vector{{{
	Vector GetVector(FloatType x, FloatType y);
	Vector GetVector(Point a);
	Vector GetVector(Segment s); //TODO: ??
	Vector GetVector(Point a, Point b);
    //}}}

    //Line{{{
	Line GetLine(FloatType a, FloatType b, FloatType c);
	Line GetLine(Point x, Point y);
	Line GetLine(Point x, Vector v);
	Line GetLine(Ray r);
	Line GetLine(Segment s);
    //}}}

    //Segment{{{
	Segment GetSegment(Point a, Point b);
	Segment GetSegment(Point a, Vector v);
    //}}}

    //Ray{{{
	Ray GetRay(Point a, Point b);
	Ray GetRay(Point a, Vector v); //TODO: implement
    //}}}
//}}}

//another Gets{{{
    //Point{{{
	Point GetPointOnThisLine(Line a); //TODO: try to avoid
    //}}}

    //Vector{{{
	Vector GetNormalVector(Line a); //TODO: normalize?
	Vector GetDirectiveVector(Line a); //TODO: normalize? nado li?
	Vector GetNormalForm(Vector v); //TODO: implement
    //}}}

	//Ray{{{
	Vector GetDirectiveVector(Ray a); //TODO: implement, normalize?
	//}}}

    //Line{{{
	Line GetNormalForm(Line a);
    //}}}
//}}}

//equals{{{
    //FloatType{{{
	bool Equal(FloatType a, FloatType b);
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
	istream& operator >> (istream& in, Point& a);
	ostream& operator << (ostream& out, Point a);
    //}}}
	
    //Vector{{{
	istream& operator >> (istream& in, Vector& a);
	ostream& operator << (ostream& in, Vector a);
    //}}}

    //Segment{{{
	istream& operator >> (istream& in, Segment& a);
	ostream& operator << (ostream& out, Segment a);
    //}}}

    //Ray{{{
	istream& operator >> (istream& in, Ray& a);
	ostream& operator << (ostream& out, Ray a);
    //}}}
//}}}

//operators{{{
    //Point{{{
	Point operator + (Point a, Vector b);
	Point operator - (Point a, Vector b); //TODO: implement
    //}}}
	
    //Vector{{{
	Vector operator + (Vector a, Vector b);
	Vector operator * (Vector a, FloatType b);
	Vector operator * (FloatType a, Vector b);
	Vector operator / (Vector a, FloatType b);
	Vector operator - (Point a, Point b);
    //}}}

    //Line{{{
	Line operator + (Line a, Vector v); //TODO: implement
	Line operator - (Line a, Vector v); //TODO: implement
	Line operator * (Line a, FloatType b);
	Line operator / (Line a, FloatType b);
    //}}}

    //FloatType{{{
	FloatType operator * (Vector a, Vector b); //TODO: replace with functions
	FloatType operator ^ (Vector a, Vector b); //TODO: replace with functions
    //}}}
//}}}

//lens{{{
    //Vector{{{
	FloatType Length(Vector a);
    //}}}

    //Segment{{{
	FloatType Length(Segment a);
    //}}}
//}}}

//dists{{{
    //Point{{{
	FloatType Distance(Point a, Line b);
	FloatType Distance(Point a, Point b);
	FloatType Distance(Point a, Segment b);
	FloatType Distance(Point a, Ray b);
    //}}}

    //Line{{{
	FloatType Distance(Line a, Ray b);
	FloatType Distance(Line a, Line b);
	FloatType Distance(Line a, Point b);
	FloatType Distance(Line a, Segment b);
    //}}}

    //Ray{{{
	FloatType Distance(Ray a, Point b);
	FloatType Distance(Ray a, Line b);
	FloatType Distance(Ray a, Ray b); //TODO: implement
	FloatType Distance(Ray a, Segment b); //TODO: implement
    //}}}

    //Segment{{{
	FloatType Distance(Segment a, Point b);
	FloatType Distance(Segment a, Line b);
	FloatType Distance(Segment a, Ray b); //TODO: implement
	FloatType Distance(Segment a, Segment b); //TODO: implement
    //}}}
//}}}

//serv{{{
    FloatType GetDeterminant(FloatType a, FloatType b, FloatType c, FloatType d);
//}}}

//intersections{{{
    //Point{{{
	vector<Point> Intersect(Point a, Line b); //TODO: avoid
	vector<Point> Intersect(Point a, Ray b); //TODO: avoid
	vector<Point> Intersect(Point a, Point b); //TODO: avoid
	vector<Point> Intersect(Point a, Segment b); //TODO: avoid
    //}}}

    //Line{{{
	vector<Point> Intersect(Line a, Line b); //TODO: return type = Intersection(None, Point, Line)
	vector<Point> Intersect(Line a, Ray b); //TODO: return type = Intersection(None, Point, Ray)
	vector<Point> Intersect(Line a, Point b); //TODO: avoid
	vector<Point> Intersect(Line a, Segment b); //TODO: return type = Intersection(None, Point, Segment)
    //}}}

    //Ray{{{
	vector<Point> Intersect(Ray a, Line b); //TODO: return type = Intersection(None, Point, Ray)
	vector<Point> Intersect(Ray a, Point b); //TODO: avoid
	vector<Point> Intersect(Ray a, Ray b); //TODO: return type = Intersection(None, Point, Segment, Ray)
	vector<Point> Intersect(Ray a, Segment b); //TODO: return type = Intersection(None, Point, Segment)
    //}}}

    //Segment{{{
	vector<Point> Intersect(Segment a, Point b); //TODO: avoid
	vector<Point> Intersect(Segment a, Segment b); //TODO: return type = Intersection(None, Point, Segment)
	vector<Point> Intersect(Segment a, Line b); //TODO: return type = Intersection(None, Point, Segment)
	vector<Point> Intersect(Segment a, Ray b); //TODO: return type = Intersection(None, Point, Segment)
    //}}}
//}}}

//realization

//constructors{{{
    //Point{{{
	Point GetPoint(FloatType x, FloatType y)
	{
	    Point a;
	    a.x = x;
	    a.y = y;
	    return a;
	}
	Point GetPoint(Vector v)
	{
	    Point b;
	    b.x = v.x;
	    b.y = v.y;
	    return b;
	}
    //}}}

    //Vector{{{
	Vector GetVector(FloatType x, FloatType y)
	{
	    Vector v;
	    v.x = x;
	    v.y = y;
	    return v;
	}
	Vector GetVector(Point a)
	{
	    return GetVector(a.x, a.y);
	}
	Vector GetVector(Segment s)
	{
	    return GetVector(s.a, s.b);
	}
	Vector GetVector(Point a, Point b)
	{
	    return b - a;
	}
    //}}}

    //Line{{{
	Line GetLine(FloatType a, FloatType b, FloatType c)
	{
	    Line x;
	    x.a = a;
	    x.b = b;
	    x.c = c;
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

	Line GetLine(Point x, Vector v)
	{
	    Line k;
	    Point y = x + v;
	    k.a = y.y - x.y;
	    k.b = x.x - y.x;
	    k.c = -k.a * x.x - k.b * x.y;
	    return k;
	}
	Line GetLine(Ray r)
	{
	    return GetLine(r.a, r.b);
	}
	Line GetLine(Segment s)
	{
	    return GetLine(s.a, s.b);
	}
    //}}}

    //Segment{{{
	Segment GetSegment(Point a, Point b)
	{
	    Segment ans;
	    ans.a = a;
	    ans.b = b;
	    return ans;
	}
	Segment GetSegment(Point a, Vector v)
	{
	    return GetSegment(a, a + v);
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
	Vector GetNormalVector(Line a)
	{
	    return GetVector(a.a, a.b);
	}

	Vector GetDirectiveVector(Line a)
	{
	    return GetVector(-a.b, a.a);
	}
    //}}}

    //Line{{{
	Line GetNormalForm(Line a)
	{
	    return a / (Length(GetNormalVector(a)));
	}
    //}}}
//}}}

//equals{{{
    //FloatType{{{
	bool Equal(FloatType a, FloatType b)
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
	    a = GetNormalForm(a);
	    b = GetNormalForm(b);
	    return Equal(a.a, b.a) and Equal(a.b, b.b)and Equal(a.c, b.c);
	}
    //}}}

    //Ray{{{
	bool operator == (Ray a, Ray b)
	{
	    return (a.a == b.a and a.b == b.b); //TODO: incorrect
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
	istream& operator >> (istream& in, Point& a)
	{
	    in >> a.x >> a.y;
	    return in;
	}

	ostream& operator << (ostream& out, Point a)
	{
	    out << a.x << " " << a.y;
	    return out;
	}
    //}}}

    //Vector{{{
	istream& operator >> (istream& in, Vector& a)
	{
	    in >> a.x >> a.y;
	    return in;
	}

	ostream& operator << (ostream& out, Vector a)
	{
	    out << a.x << " " << a.y;
	    return out;
	}
    //}}}

    //Segment{{{
	istream& operator >> (istream& in, Segment& a)
	{
	    in >> a.a >> a.b;
	    return in;
	}

	ostream& operator << (ostream& out, Segment a)
	{
	    out << a.a << " " << a.b;
	    return out;
	}
    ///}}}

    //Ray{{{
	istream& operator >> (istream& in, Ray& a)
	{
	    in >> a.a >> a.b;
	    return in;
	}

	ostream& operator << (ostream& out, Ray a)
	{
	    out << a.a << " " << a.b;
	    return out;
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
	Vector operator * (Vector a, FloatType b)
	{
	    return GetVector(a.x * b, a.y * b);
	}

	Vector operator / (Vector a, FloatType b)
	{
	    return a * (1 / b); //TODO: optimal))0)
	}

	Vector operator * (FloatType a, Vector b)
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
	Line operator * (Line a, FloatType b)
	{
	    return GetLine(a.a * b, a.b * b, a.c * b);
	}

	Line operator / (Line a, FloatType b)
	{
	    return a * (1 / b); //TODO: optimize
	}
    //}}}

    //FloatType{{{
	FloatType operator * (Vector a, Vector b)
	{
	    return a.x * b.x * a.y * b.y;
	}
	FloatType operator ^ (Vector a, Vector b)
	{
	    return a.x * b.y - a.y * b.x;
	}
    //}}}
//}}}

//lens{{{
    //Vector{{{
	FloatType Length(Vector a)
	{
	    return sqrt(a.x * a.x + a.y * a.y);
	}
    //}}}

    //Segments{{{
	FloatType Length(Segment a)
	{
	    return Length(a.a - a.b);
	}
    //}}}
//}}}

//dists{{{
    //Point{{{
	FloatType Distance(Point a, Line b)/*{{{*/
	{
	    return Distance(b, a);
	}/*}}}*/

	FloatType Distance(Point a, Point b)/*{{{*/
	{
	    return Length(a - b);
	}/*}}}*/

	FloatType Distance(Point a, Segment b)/*{{{*/
	{
	    return Distance(b, a);
	}/*}}}*/

	FloatType Distance(Point a, Ray b)/*{{{*/
	{
	    return Distance(b, a);
	}/*}}}*/
    //}}}

    //Line{{{
	FloatType Distance(Line a, Line b)/*{{{*/
    {
	    if(!Intersect(a, b).empty())
	    {
		    return 0;
	    }
	    else
	    {
		    return abs(GetNormalForm(a).c - GetNormalForm(b).c);
	    }
    }/*}}}*/

	FloatType Distance(Line a, Point b)/*{{{*/
	{
	    return GetNormalForm(a)(b);
	}/*}}}*/

	FloatType Distance(Line a, Ray b)/*{{{*/
	{
		if(!Intersect(a, b).empty())
		{
			return 0;
		}
		return Distance(a, b.a);
	}/*}}}*/

	FloatType Distance(Line a, Segment b)/*{{{*/
	{
	    return max(Distance(a, GetRay(b.a, b.b)), Distance(a, GetRay(b.b, b.a))); //TODO: ?????
	}/*}}}*/
    //}}}

    //Ray{{{
	FloatType Distance(Ray a, Point b)/*{{{*/
	{
		//TODO: Grishanya
	    if (!Intersect(a, b).empty())
	    {
		return Distance(GetLine(a), b);
	    }
	    else
	    {
		return Distance(a.a, b);
	    }
	}/*}}}*/
    
	FloatType Distance(Ray a, Line b)/*{{{*/
	{
	    return Distance(b, a);
	}/*}}}*/
    //}}}

    //Segment{{{
	FloatType Distance(Segment a, Point b)/*{{{*/
	{
	    return max(Distance(GetRay(a.a, a.b), b), Distance(GetRay(a.b, a.a), b));
	}/*}}}*/

	FloatType Distance(Segment a, Line b)/*{{{*/
	{
	    return Distance(b, a);
	}/*}}}*/
    //}}}
//}}}

//serv{{{
    FloatType GetDeterminant(FloatType a, FloatType b, FloatType c, FloatType d)
    {
	return a * d - b * c;
    }
//}}}

//intersections{{{
    //Point{{{			
	vector<Point> Intersect(Point a, Line b)/*{{{*/
	{
	    return Intersect(b, a);
	}/*}}}*/

	vector<Point> Intersect(Point a, Ray b)/*{{{*/
	{
	    return Intersect(b, a);
	}/*}}}*/

	vector<Point> Intersect(Point a, Point b)/*{{{*/
	{
	    if (a == b)
		return {a};
	    else
		return {};
	}/*}}}*/

	vector<Point> Intersect(Point a, Segment b)/*{{{*/
	{
	    return Intersect(b, a);
	}/*}}}*/
    //}}}

    //Line{{{
	vector<Point> Intersect(Line a, Point b)/*{{{*/
	{
	    if (Equal(a(b), 0))
	    {
		return {b};
	    }
	    return {};
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
	    return vector<Point>({GetPoint(-GetDeterminant(a.c, a.b, b.c, b.b) / GetDeterminant(a.a, a.b, b.a, b.b),
	                                   -GetDeterminant(a.a, a.c, b.a, b.c) / GetDeterminant(a.a, a.b, b.a, b.b))});
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
    //}}}

    //Ray{{{
	vector<Point> Intersect(Ray a, Line b)/*{{{*/
	{
	    return Intersect(b, a);
	}/*}}}*/

	vector<Point> Intersect(Ray a, Point b)/*{{{*/
	{
	    if (Equal((a.b - a.a) ^ (b - a.a), 0) and (a.b - a.a) * (b - a.a) > -EPS)
	    {
		return vector<Point> ({b});
	    }
	    return vector<Point>{};
	}/*}}}*/

	vector<Point> Intersect(Ray a, Ray b)/*{{{*/
	{
	    vector<Point> ans;
	    ans = Intersect(GetLine(a), b);
	    if (ans.empty() or !Intersect(a, ans[0]).empty())
		return ans;
	    return {};
	}/*}}}*/

	vector<Point> Intersect(Ray a, Segment b)/*{{{*/
	{
	    vector<Point> ans1 = Intersect(a, GetRay(b.a, b.b));
	    vector<Point> ans2 = Intersect(a, GetRay(b.b, b.a));
	    if (ans1.empty() or ans2.empty())
		return {};
	    else
		return ans1;
	}/*}}}*/
    //}}}

    //Segment{{{ 
	vector<Point> Intersect(Segment a, Point b)/*{{{*/
	{
	    if (!Intersect(GetRay(a.a, a.b), b).empty() and !Intersect(GetRay(a.b, a.a), b).empty())
		return {b};
	    else
		return {};
	}/*}}}*/

	vector<Point> Intersect(Segment a, Segment b)/*{{{*/
	{
	    vector<Point> ans1 = Intersect(GetRay(b.a, b.b), a);
	    vector<Point> ans2 = Intersect(GetRay(b.b, b.a), a);
	    if (ans1.empty() or ans2.empty())
		return {};
	    else
		return ans1;
	}/*}}}*/

	vector<Point> Intersect(Segment a, Line b)/*{{{*/
	{
	    return Intersect(b, a);
	}/*}}}*/
	
	vector<Point> Intersect(Segment a, Ray b)/*{{{*/
	{
	    return Intersect(b, a);
	}/*}}}*/
    //}}}
//}}}

int main()
{

}
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef double FloatType;
const FloatType EPS = 1e-5;

class Point/*{{{*/
{
public:
    FloatType x, y; 
};/*}}}*/

class Vector/*{{{*/
{
public:
    FloatType x, y;
};/*}}}*/

class Line/*{{{*/
{
public:
    FloatType a, b, c;
    FloatType operator ()(Point x)
    {
        return a * x.x + b * x.y + c;
    }
};/*}}}*/

class Ray/*{{{*/
{
public:
    Point a, b; // maybe Point a, Vector v (v.x * v.x + v.y * v.y = 1)
};/*}}}*/

class Segment/*{{{*/
{
public:
    Point a, b;
};/*}}}*/

//announcement

//constructors{{{
    //Point{{{
	Point GetPoint(FloatType x, FloatType y);
	Point GetPoint(Vector v);
    //}}}

    //Vector{{{
	Vector GetVector(FloatType x, FloatType y);
	Vector GetVector(Point a);
	Vector GetVector(Segment s); //TODO: ??
	Vector GetVector(Point a, Point b);
    //}}}

    //Line{{{
	Line GetLine(FloatType a, FloatType b, FloatType c);
	Line GetLine(Point x, Point y);
	Line GetLine(Point x, Vector v);
	Line GetLine(Ray r);
	Line GetLine(Segment s);
    //}}}

    //Segment{{{
	Segment GetSegment(Point a, Point b);
	Segment GetSegment(Point a, Vector v);
    //}}}

    //Ray{{{
	Ray GetRay(Point a, Point b);
	Ray GetRay(Point a, Vector v); //TODO: implement
    //}}}
//}}}

//another Gets{{{
    //Point{{{
	Point GetPointOnThisLine(Line a); //TODO: try to avoid
    //}}}

    //Vector{{{
	Vector GetNormalVector(Line a); //TODO: normalize?
	Vector GetDirectiveVector(Line a); //TODO: normalize? nado li?
	Vector GetNormalForm(Vector v); //TODO: implement
    //}}}

	//Ray{{{
	Vector GetDirectiveVector(Ray a); //TODO: implement, normalize?
	//}}}

    //Line{{{
	Line GetNormalForm(Line a);
    //}}}
//}}}

//equals{{{
    //FloatType{{{
	bool Equal(FloatType a, FloatType b);
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
	istream& operator >> (istream& in, Point& a);
	ostream& operator << (ostream& out, Point a);
    //}}}
	
    //Vector{{{
	istream& operator >> (istream& in, Vector& a);
	ostream& operator << (ostream& in, Vector a);
    //}}}

    //Segment{{{
	istream& operator >> (istream& in, Segment& a);
	ostream& operator << (ostream& out, Segment a);
    //}}}

    //Ray{{{
	istream& operator >> (istream& in, Ray& a);
	ostream& operator << (ostream& out, Ray a);
    //}}}
//}}}

//operators{{{
    //Point{{{
	Point operator + (Point a, Vector b);
	Point operator - (Point a, Vector b); //TODO: implement
    //}}}
	
    //Vector{{{
	Vector operator + (Vector a, Vector b);
	Vector operator * (Vector a, FloatType b);
	Vector operator * (FloatType a, Vector b);
	Vector operator / (Vector a, FloatType b);
	Vector operator - (Point a, Point b);
    //}}}

    //Line{{{
	Line operator + (Line a, Vector v); //TODO: implement
	Line operator - (Line a, Vector v); //TODO: implement
	Line operator * (Line a, FloatType b);
	Line operator / (Line a, FloatType b);
    //}}}

    //FloatType{{{
	FloatType operator * (Vector a, Vector b); //TODO: replace with functions
	FloatType operator ^ (Vector a, Vector b); //TODO: replace with functions
    //}}}
//}}}

//lens{{{
    //Vector{{{
	FloatType Length(Vector a);
    //}}}

    //Segment{{{
	FloatType Length(Segment a);
    //}}}
//}}}

//dists{{{
    //Point{{{
	FloatType Distance(Point a, Line b);
	FloatType Distance(Point a, Point b);
	FloatType Distance(Point a, Segment b);
	FloatType Distance(Point a, Ray b);
    //}}}

    //Line{{{
	FloatType Distance(Line a, Ray b);
	FloatType Distance(Line a, Line b);
	FloatType Distance(Line a, Point b);
	FloatType Distance(Line a, Segment b);
    //}}}

    //Ray{{{
	FloatType Distance(Ray a, Point b);
	FloatType Distance(Ray a, Line b);
	FloatType Distance(Ray a, Ray b); //TODO: implement
	FloatType Distance(Ray a, Segment b); //TODO: implement
    //}}}

    //Segment{{{
	FloatType Distance(Segment a, Point b);
	FloatType Distance(Segment a, Line b);
	FloatType Distance(Segment a, Ray b); //TODO: implement
	FloatType Distance(Segment a, Segment b); //TODO: implement
    //}}}
//}}}

//serv{{{
    FloatType GetDeterminant(FloatType a, FloatType b, FloatType c, FloatType d);
//}}}

//intersections{{{
    //Point{{{
	vector<Point> Intersect(Point a, Line b); //TODO: avoid
	vector<Point> Intersect(Point a, Ray b); //TODO: avoid
	vector<Point> Intersect(Point a, Point b); //TODO: avoid
	vector<Point> Intersect(Point a, Segment b); //TODO: avoid
    //}}}

    //Line{{{
	vector<Point> Intersect(Line a, Line b); //TODO: return type = Intersection(None, Point, Line)
	vector<Point> Intersect(Line a, Ray b); //TODO: return type = Intersection(None, Point, Ray)
	vector<Point> Intersect(Line a, Point b); //TODO: avoid
	vector<Point> Intersect(Line a, Segment b); //TODO: return type = Intersection(None, Point, Segment)
    //}}}

    //Ray{{{
	vector<Point> Intersect(Ray a, Line b); //TODO: return type = Intersection(None, Point, Ray)
	vector<Point> Intersect(Ray a, Point b); //TODO: avoid
	vector<Point> Intersect(Ray a, Ray b); //TODO: return type = Intersection(None, Point, Segment, Ray)
	vector<Point> Intersect(Ray a, Segment b); //TODO: return type = Intersection(None, Point, Segment)
    //}}}

    //Segment{{{
	vector<Point> Intersect(Segment a, Point b); //TODO: avoid
	vector<Point> Intersect(Segment a, Segment b); //TODO: return type = Intersection(None, Point, Segment)
	vector<Point> Intersect(Segment a, Line b); //TODO: return type = Intersection(None, Point, Segment)
	vector<Point> Intersect(Segment a, Ray b); //TODO: return type = Intersection(None, Point, Segment)
    //}}}
//}}}

//realization

//constructors{{{
    //Point{{{
	Point GetPoint(FloatType x, FloatType y)
	{
	    Point a;
	    a.x = x;
	    a.y = y;
	    return a;
	}
	Point GetPoint(Vector v)
	{
	    Point b;
	    b.x = v.x;
	    b.y = v.y;
	    return b;
	}
    //}}}

    //Vector{{{
	Vector GetVector(FloatType x, FloatType y)
	{
	    Vector v;
	    v.x = x;
	    v.y = y;
	    return v;
	}
	Vector GetVector(Point a)
	{
	    return GetVector(a.x, a.y);
	}
	Vector GetVector(Segment s)
	{
	    return GetVector(s.a, s.b);
	}
	Vector GetVector(Point a, Point b)
	{
	    return b - a;
	}
    //}}}

    //Line{{{
	Line GetLine(FloatType a, FloatType b, FloatType c)
	{
	    Line x;
	    x.a = a;
	    x.b = b;
	    x.c = c;
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

	Line GetLine(Point x, Vector v)
	{
	    Line k;
	    Point y = x + v;
	    k.a = y.y - x.y;
	    k.b = x.x - y.x;
	    k.c = -k.a * x.x - k.b * x.y;
	    return k;
	}
	Line GetLine(Ray r)
	{
	    return GetLine(r.a, r.b);
	}
	Line GetLine(Segment s)
	{
	    return GetLine(s.a, s.b);
	}
    //}}}

    //Segment{{{
	Segment GetSegment(Point a, Point b)
	{
	    Segment ans;
	    ans.a = a;
	    ans.b = b;
	    return ans;
	}
	Segment GetSegment(Point a, Vector v)
	{
	    return GetSegment(a, a + v);
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
	Vector GetNormalVector(Line a)
	{
	    return GetVector(a.a, a.b);
	}

	Vector GetDirectiveVector(Line a)
	{
	    return GetVector(-a.b, a.a);
	}
    //}}}

    //Line{{{
	Line GetNormalForm(Line a)
	{
	    return a / (Length(GetNormalVector(a)));
	}
    //}}}
//}}}

//equals{{{
    //FloatType{{{
	bool Equal(FloatType a, FloatType b)
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
	    a = GetNormalForm(a);
	    b = GetNormalForm(b);
	    return Equal(a.a, b.a) and Equal(a.b, b.b)and Equal(a.c, b.c);
	}
    //}}}

    //Ray{{{
	bool operator == (Ray a, Ray b)
	{
	    return (a.a == b.a and a.b == b.b); //TODO: incorrect
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
	istream& operator >> (istream& in, Point& a)
	{
	    in >> a.x >> a.y;
	    return in;
	}

	ostream& operator << (ostream& out, Point a)
	{
	    out << a.x << " " << a.y;
	    return out;
	}
    //}}}

    //Vector{{{
	istream& operator >> (istream& in, Vector& a)
	{
	    in >> a.x >> a.y;
	    return in;
	}

	ostream& operator << (ostream& out, Vector a)
	{
	    out << a.x << " " << a.y;
	    return out;
	}
    //}}}

    //Segment{{{
	istream& operator >> (istream& in, Segment& a)
	{
	    in >> a.a >> a.b;
	    return in;
	}

	ostream& operator << (ostream& out, Segment a)
	{
	    out << a.a << " " << a.b;
	    return out;
	}
    ///}}}

    //Ray{{{
	istream& operator >> (istream& in, Ray& a)
	{
	    in >> a.a >> a.b;
	    return in;
	}

	ostream& operator << (ostream& out, Ray a)
	{
	    out << a.a << " " << a.b;
	    return out;
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
	Vector operator * (Vector a, FloatType b)
	{
	    return GetVector(a.x * b, a.y * b);
	}

	Vector operator / (Vector a, FloatType b)
	{
	    return a * (1 / b); //TODO: optimal))0)
	}

	Vector operator * (FloatType a, Vector b)
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
	Line operator * (Line a, FloatType b)
	{
	    return GetLine(a.a * b, a.b * b, a.c * b);
	}

	Line operator / (Line a, FloatType b)
	{
	    return a * (1 / b); //TODO: optimize
	}
    //}}}

    //FloatType{{{
	FloatType operator * (Vector a, Vector b)
	{
	    return a.x * b.x * a.y * b.y;
	}
	FloatType operator ^ (Vector a, Vector b)
	{
	    return a.x * b.y - a.y * b.x;
	}
    //}}}
//}}}

//lens{{{
    //Vector{{{
	FloatType Length(Vector a)
	{
	    return sqrt(a.x * a.x + a.y * a.y);
	}
    //}}}

    //Segments{{{
	FloatType Length(Segment a)
	{
	    return Length(a.a - a.b);
	}
    //}}}
//}}}

//dists{{{
    //Point{{{
	FloatType Distance(Point a, Line b)/*{{{*/
	{
	    return Distance(b, a);
	}/*}}}*/

	FloatType Distance(Point a, Point b)/*{{{*/
	{
	    return Length(a - b);
	}/*}}}*/

	FloatType Distance(Point a, Segment b)/*{{{*/
	{
	    return Distance(b, a);
	}/*}}}*/

	FloatType Distance(Point a, Ray b)/*{{{*/
	{
	    return Distance(b, a);
	}/*}}}*/
    //}}}

    //Line{{{
	FloatType Distance(Line a, Line b)/*{{{*/
    {
	    if(!Intersect(a, b).empty())
	    {
		    return 0;
	    }
	    else
	    {
		    return abs(GetNormalForm(a).c - GetNormalForm(b).c);
	    }
    }/*}}}*/

	FloatType Distance(Line a, Point b)/*{{{*/
	{
	    return GetNormalForm(a)(b);
	}/*}}}*/

	FloatType Distance(Line a, Ray b)/*{{{*/
	{
		if(!Intersect(a, b).empty())
		{
			return 0;
		}
		return Distance(a, b.a);
	}/*}}}*/

	FloatType Distance(Line a, Segment b)/*{{{*/
	{
	    return max(Distance(a, GetRay(b.a, b.b)), Distance(a, GetRay(b.b, b.a))); //TODO: ?????
	}/*}}}*/
    //}}}

    //Ray{{{
	FloatType Distance(Ray a, Point b)/*{{{*/
	{
		//TODO: Grishanya
	    if (!Intersect(a, b).empty())
	    {
		return Distance(GetLine(a), b);
	    }
	    else
	    {
		return Distance(a.a, b);
	    }
	}/*}}}*/
    
	FloatType Distance(Ray a, Line b)/*{{{*/
	{
	    return Distance(b, a);
	}/*}}}*/
    //}}}

    //Segment{{{
	FloatType Distance(Segment a, Point b)/*{{{*/
	{
	    return max(Distance(GetRay(a.a, a.b), b), Distance(GetRay(a.b, a.a), b));
	}/*}}}*/

	FloatType Distance(Segment a, Line b)/*{{{*/
	{
	    return Distance(b, a);
	}/*}}}*/
    //}}}
//}}}

//serv{{{
    FloatType GetDeterminant(FloatType a, FloatType b, FloatType c, FloatType d)
    {
	return a * d - b * c;
    }
//}}}

//intersections{{{
    //Point{{{			
	vector<Point> Intersect(Point a, Line b)/*{{{*/
	{
	    return Intersect(b, a);
	}/*}}}*/

	vector<Point> Intersect(Point a, Ray b)/*{{{*/
	{
	    return Intersect(b, a);
	}/*}}}*/

	vector<Point> Intersect(Point a, Point b)/*{{{*/
	{
	    if (a == b)
		return {a};
	    else
		return {};
	}/*}}}*/

	vector<Point> Intersect(Point a, Segment b)/*{{{*/
	{
	    return Intersect(b, a);
	}/*}}}*/
    //}}}

    //Line{{{
	vector<Point> Intersect(Line a, Point b)/*{{{*/
	{
	    if (Equal(a(b), 0))
	    {
		return {b};
	    }
	    return {};
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
	    return vector<Point>({GetPoint(-GetDeterminant(a.c, a.b, b.c, b.b) / GetDeterminant(a.a, a.b, b.a, b.b),
	                                   -GetDeterminant(a.a, a.c, b.a, b.c) / GetDeterminant(a.a, a.b, b.a, b.b))});
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
    //}}}

    //Ray{{{
	vector<Point> Intersect(Ray a, Line b)/*{{{*/
	{
	    return Intersect(b, a);
	}/*}}}*/

	vector<Point> Intersect(Ray a, Point b)/*{{{*/
	{
	    if (Equal((a.b - a.a) ^ (b - a.a), 0) and (a.b - a.a) * (b - a.a) > -EPS)
	    {
		return vector<Point> ({b});
	    }
	    return vector<Point>{};
	}/*}}}*/

	vector<Point> Intersect(Ray a, Ray b)/*{{{*/
	{
	    vector<Point> ans;
	    ans = Intersect(GetLine(a), b);
	    if (ans.empty() or !Intersect(a, ans[0]).empty())
		return ans;
	    return {};
	}/*}}}*/

	vector<Point> Intersect(Ray a, Segment b)/*{{{*/
	{
	    vector<Point> ans1 = Intersect(a, GetRay(b.a, b.b));
	    vector<Point> ans2 = Intersect(a, GetRay(b.b, b.a));
	    if (ans1.empty() or ans2.empty())
		return {};
	    else
		return ans1;
	}/*}}}*/
    //}}}

    //Segment{{{ 
	vector<Point> Intersect(Segment a, Point b)/*{{{*/
	{
	    if (!Intersect(GetRay(a.a, a.b), b).empty() and !Intersect(GetRay(a.b, a.a), b).empty())
		return {b};
	    else
		return {};
	}/*}}}*/

	vector<Point> Intersect(Segment a, Segment b)/*{{{*/
	{
	    vector<Point> ans1 = Intersect(GetRay(b.a, b.b), a);
	    vector<Point> ans2 = Intersect(GetRay(b.b, b.a), a);
	    if (ans1.empty() or ans2.empty())
		return {};
	    else
		return ans1;
	}/*}}}*/

	vector<Point> Intersect(Segment a, Line b)/*{{{*/
	{
	    return Intersect(b, a);
	}/*}}}*/
	
	vector<Point> Intersect(Segment a, Ray b)/*{{{*/
	{
	    return Intersect(b, a);
	}/*}}}*/
    //}}}
//}}}

int main()
{

}

