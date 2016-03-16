#ifndef GEOMLIB_LIBRARY_H
#define GEOMLIB_LIBRARY_H

#include <istream>
#include <cmath>
#include <vector>

typedef double FloatType;
const FloatType EPS = 1e-5;

/**
 * @class Point
 * @brief Point in a Cartesian plane class.
*/
struct Point
{
public:
	/**
	 * Coordinate of point.
	 */
	/**@{*/
	FloatType x, y;
	/**@}*/
};

/**
 * @class Vector
 * @brief Two-dimensional Euclidean vector class.
 */
struct Vector
{
public:
	/**
	 * Component of vector.
	 */
	/**@{*/
	FloatType x, y;
	/**@}*/
};

/**
 * @class Line
 * @brief Line in a Cartesian plane class.
 *
 * Equation: Ax + By + C = 0, where
 * x and y are coordinates of point.
 */
struct Line
{
public:
	/**
	 * Equation parameter.
	 */
	/**@{*/
	FloatType a, b, c;
	/**@}*/
};

struct Ray
{
public:
	Point a, b; // maybe Point a, Vector v (v.x * v.x + v.y * v.y = 1)
};

struct Segment
{
public:
	Point a, b;
};



//constructors
//Point

/**
 * @briefGet 2 FloatTypes return Point
 *
 * takes 2 FloatTypes returns a Point with coordinates equal to these 2 FloatTypes
 */
Point GetPoint(FloatType x, FloatType y);

/**
 * @brief Get Vector return Point
 *
 * Takes Vector returns a Point with coordinates equal to the coordinates of this Vector
 */
Point GetPoint(Vector v);

//Vector;

/**
 * @briefGet 2 FloatTypes return Vector
 *
 * takes 2 FloatTypes returns a Vector with coordinates equal to these 2 FloatTypes
 */
Vector GetVector(FloatType x, FloatType y);

/**
 * @brief Get Point return Vector
 *
 * Takes Point returns a Vector with coordinates equal to the coordinates of this Point
 */
Vector GetVector(Point a);

/**
 * @brief Get 2 Points return Vector
 *
 * Constructing vector directed from point 1 to point 2
 */
Vector GetVector(Point a, Point b);

//Line
Line GetLine(FloatType a, FloatType b, FloatType c);
Line GetLine(Point x, Point y);
Line GetLine(Point x, Vector v);
Line GetLine(Ray r);
Line GetLine(Segment s);

//Segment
Segment GetSegment(Point a, Point b);
Segment GetSegment(Point a, Vector v);

//Ray
Ray GetRay(Point a, Point b);
Ray GetRay(Point a, Vector v);

//another Gets
//Point
Point GetPointOnThisLine(Line a); //TODO: try to avoid

//Vector
Vector GetNormalVector(Line a); //TODO: normalize?
Vector GetDirectiveVector(Line a); //TODO: normalize? nado li?
Vector GetNormalForm(Vector v); //TODO: implement

//Ray
Vector GetDirectiveVector(Ray a); //TODO: implement, normalize?

//Line
Line GetNormalForm(Line a);

//equals
//FloatType

//Test if two numbers with precision error are equal.
bool Equal(FloatType a, FloatType b);

//Point
bool operator==(Point a, Point b);

//Vector
bool operator==(Vector a, Vector b);

//Line
bool operator==(Line a, Line b);

//Ray
bool operator==(Ray a, Ray b);

//Segment
bool operator==(Segment a, Segment b);

//in/out
//Point
std::istream& operator>>(std::istream& in, Point& a);
std::ostream& operator<<(std::ostream& out, Point a);

//Vector
std::istream& operator>>(std::istream& in, Vector& a);
std::ostream& operator<<(std::ostream& in, Vector a);

//Segment
std::istream& operator>>(std::istream& in, Segment& a);
std::ostream& operator<<(std::ostream& out, Segment a);

//Ray
std::istream& operator>>(std::istream& in, Ray& a);
std::ostream& operator<<(std::ostream& out, Ray a);

//operators
//Point
Point operator+(Point a, Vector b);
Point operator-(Point a, Vector b);

//Vector
Vector operator+(Vector a, Vector b);
Vector operator*(Vector a, FloatType b);
Vector operator*(FloatType a, Vector b);
Vector operator/(Vector a, FloatType b);
Vector operator-(Point a, Point b);

//Line
Line operator+(Line a, Vector v); //TODO: implement
Line operator-(Line a, Vector v); //TODO: implement
Line operator*(Line a, FloatType b);
Line operator/(Line a, FloatType b);

//FloatType
FloatType operator*(Vector a, Vector b); //TODO: replace with functions
FloatType operator^(Vector a, Vector b); //TODO: replace with functions

//lens
//Vector
FloatType Length(Vector a);

//Segment
FloatType Length(Segment a);
//

//dists
//Point
FloatType Distance(Point a, Line b);
FloatType Distance(Point a, Point b);
FloatType Distance(Point a, Segment b);
FloatType Distance(Point a, Ray b);

//Line
FloatType Distance(Line a, Ray b);
FloatType Distance(Line a, Line b);
FloatType Distance(Line a, Point b);
FloatType Distance(Line a, Segment b);

//Ray
FloatType Distance(Ray a, Point b);
FloatType Distance(Ray a, Line b);
FloatType Distance(Ray a, Ray b);
FloatType Distance(Ray a, Segment b);

//Segment
FloatType Distance(Segment a, Point b);
FloatType Distance(Segment a, Line b);
FloatType Distance(Segment a, Ray b); //TODO: implement
FloatType Distance(Segment a, Segment b); //TODO: implement

//serv
FloatType GetDeterminant(FloatType a, FloatType b, FloatType c, FloatType d);

//intersections
//Point
std::vector<Point> Intersect(Point a, Line b); //TODO: avoid
std::vector<Point> Intersect(Point a, Ray b); //TODO: avoid
std::vector<Point> Intersect(Point a, Point b); //TODO: avoid
std::vector<Point> Intersect(Point a, Segment b); //TODO: avoid

//Line
std::vector<Point> Intersect(Line a, Line b); //TODO: return type = Intersection(None, Point, Line)
std::vector<Point> Intersect(Line a, Ray b); //TODO: return type = Intersection(None, Point, Ray)
std::vector<Point> Intersect(Line a, Point b); //TODO: avoid
std::vector<Point> Intersect(Line a, Segment b); //TODO: return type = Intersection(None, Point, Segment)

//Ray
std::vector<Point> Intersect(Ray a, Line b); //TODO: return type = Intersection(None, Point, Ray)
std::vector<Point> Intersect(Ray a, Point b); //TODO: avoid
std::vector<Point> Intersect(Ray a, Ray b); //TODO: return type = Intersection(None, Point, Segment, Ray)
std::vector<Point> Intersect(Ray a, Segment b); //TODO: return type = Intersection(None, Point, Segment)

//Segment
std::vector<Point> Intersect(Segment a, Point b); //TODO: avoid
std::vector<Point> Intersect(Segment a, Segment b); //TODO: return type = Intersection(None, Point, Segment)
std::vector<Point> Intersect(Segment a, Line b); //TODO: return type = Intersection(None, Point, Segment)
std::vector<Point> Intersect(Segment a, Ray b); //TODO: return type = Intersection(None, Point, Segment)

//realization

bool Equal(const FloatType a, const FloatType b)
{
	return std::abs(a - b) <= EPS;
}

//constructors
//Point

Point GetPoint(FloatType x, FloatType y)
{
	return {x, y};
}

Point GetPoint(Vector v)
{
	return {v.x, v.y};
}

//Vector

Vector GetVector(FloatType x, FloatType y)
{
	return {x, y};
}

Vector GetVector(Point a)
{
	return {a.x, a.y};
}

Vector GetVector(Point a, Point b)
{
	return {b.x - a.x, b.y - a.y};
}


#endif //GEOMLIB_LIBRARY_H
