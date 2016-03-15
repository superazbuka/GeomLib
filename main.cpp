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

	FloatType operator()(Point x);
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
	Vector GetVector(Ray s); //TODO: ??
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
	Ray GetRay(Point a, Vector v);
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
	bool operator==(Point a, Point b);
    //}}}

    //Vector{{{
	bool operator==(Vector a, Vector b);
    //}}}

    //Line{{{
	bool operator==(Line a, Line b);
    //}}}

    //Ray{{{
	bool operator==(Ray a, Ray b);
    //}}}

    //Segment{{{
	bool operator==(Segment a, Segment b);
    //}}}
//}}}

//in/out{{{
    //Point{{{
	istream& operator>>(istream& in, Point& a);
	ostream& operator<<(ostream& out, Point a);
    //}}}
	
    //Vector{{{
	istream& operator>>(istream& in, Vector& a);
	ostream& operator<<(ostream& in, Vector a);
    //}}}

    //Segment{{{
	istream& operator>>(istream& in, Segment& a);
	ostream& operator<<(ostream& out, Segment a);
    //}}}

    //Ray{{{
	istream& operator>>(istream& in, Ray& a);
	ostream& operator<<(ostream& out, Ray a);
    //}}}
//}}}

//operators{{{
    //Point{{{
	Point operator+(Point a, Vector b);
	Point operator-(Point a, Vector b);
    //}}}
	
    //Vector{{{
	Vector operator+(Vector a, Vector b);
	Vector operator*(Vector a, FloatType b);
	Vector operator*(FloatType a, Vector b);
	Vector operator/(Vector a, FloatType b);
	Vector operator-(Point a, Point b);
    //}}}

    //Line{{{
	Line operator+(Line a, Vector v); //TODO: implement
	Line operator-(Line a, Vector v); //TODO: implement
	Line operator*(Line a, FloatType b);
	Line operator/(Line a, FloatType b);
    //}}}

    //FloatType{{{
	FloatType operator*(Vector a, Vector b); //TODO: replace with functions
	FloatType operator^(Vector a, Vector b); //TODO: replace with functions
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

int main()
{

}
