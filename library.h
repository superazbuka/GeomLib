/** @file library.h
 * Geometry library for sportive programming.
 */


#ifndef GEOMLIB_LIBRARY_H
#define GEOMLIB_LIBRARY_H

#include <istream>
#include <cmath>
#include <vector>

namespace geom
{
typedef double FloatType;
const FloatType EPS = 1e-5;

/** @defgroup objects
 * Elementary geometry data types
 *  @{
 */

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

/**
 * @class Ray
 * @brief Ray in a Cartesian plane class.
 */
struct Ray
{
public:
	/**
	 * Initial point of ray.
	 */
	Point p;
	/**
	 * Directive vector of ray.
	 */
	Vector v;
};

/**
 * @class Segment
 * @brief Segment in a Cartesian plane class.
 */
struct Segment
{
public:
	/**
	 * Endpoint of segment.
	 */
	/**@{*/
	Point a, b;
	/**@}*/
};
/**
 * @}
 */

enum TypeOfIntersect
{
	NONE,
	POINT,
	LINE,
	SEGMENT,
	RAY
};

struct Intersection
{
	void * data;
	TypeOfIntersect t;
};





/** @defgroup constructors
 * Constructors for geometry objects.
 *  @{
 */
/**
 * @brief Get point by two coordinates.
 * @param x, y Coordinates.
 * @return point(x, y)
 */
Point GetPoint(FloatType x, FloatType y);

/**
 * @brief Get point by position vector.
 * @param v Position vector.
 * @return point(v.x, v.y)
 */
Point GetPoint(Vector v);

/**
 * @brief Get vector by components.
 * @param x, y Components.
 * @return vector(x, y)
 */
Vector GetVector(FloatType x, FloatType y);

/**
 * @brief Get position vector for point.
 * @param a Point.
 * @return vector(a.x, a.y)
 */
Vector GetVector(Point a);

/**
 * @brief Get vector between points.
 * @param a, b Endpoints.
 * @return vector(b.x - a.x, b.y - a.y)
 */
Vector GetVector(Point a, Point b);

/**
 * @brief Get line by equation parameters.
 * @param a, b, c Equation parameters.
 * @exception if a == 0 and b == 0.
 * @return line(a, b, c)
 */
Line GetLine(FloatType a, FloatType b, FloatType c);

/**
 * @brief Get line by two points on it.
 * @param a, b Points.
 * @exception if a == b.
 * @return line
 */
Line GetLine(Point a, Point b);

/**
 * @brief Get line by point and directive vector.
 * @param a Point.
 * @param v Directive vector.
 * @exception if v.x == 0 and v.y == 0.
 * @return line
 */
Line GetLine(Point x, Vector v);

/**
 * @brief Get line by ray.
 * @param r Ray.
 * @exception if r.v.x == 0 and r.v.y == 0.
 * @return line
 */
Line GetLine(Ray r);

/**
 * @brief Get line by segment.
 * @param s Segment.
 * @exception if length(s) == 0.
 * @return line
 */
Line GetLine(Segment s);

/**
 * @brief Get segment by endpoints.
 * @param a, b Endpoints.
 * @return segment
 */
Segment GetSegment(Point a, Point b);

/**
 * @brief Get segment by endpoint and directive vector.
 * @param a Endpoint.
 * @param v Directive vector.
 * @return segment
 */
Segment GetSegment(Point a, Vector v);

/**
 * @brief Get ray by initial point and a point on it
 * @param a Initial point.
 * @param b Point on ray.
 * @exception if a == b.
 * @return ray
 */
Ray GetRay(Point a, Point b);

/**
 * @brief Get ray by initial point and a directive vector
 * @param a Initial point.
 * @param v Directive vector.
 * @exception if v.x == 0 and v.y == 0.
 * @return ray
 */
Ray GetRay(Point a, Vector v);
/**
 * @}
 */

Intersection GetIntersection(TypeOfIntersect t, void* data);
Intersection GetIntersection(Point a);
Intersection GetIntersection(Line a);
Intersection GetIntersection(Ray a);
Intersection GetIntersection(Segment a);


Vector GetNormalVector(Line a);
Vector GetNormalForm(Vector v);
Vector GetDirectiveVector(Ray a);

Line GetNormalForm(Line a);
bool Equal(FloatType a, FloatType b);
bool operator==(Point a, Point b);
bool operator==(Vector a, Vector b);
bool operator==(Line a, Line b);
bool operator==(Ray a, Ray b);
bool operator==(Segment a, Segment b);

std::istream& operator>>(std::istream& in, Point& a);
std::ostream& operator<<(std::ostream& out, Point a);
std::istream& operator>>(std::istream& in, Vector& a);
std::ostream& operator<<(std::ostream& out, Vector a);
std::istream& operator>>(std::istream& in, Segment& a);
std::ostream& operator<<(std::ostream& out, Segment a);
std::istream& operator>>(std::istream& in, Ray& a);
std::ostream& operator<<(std::ostream& out, Ray a);

Point operator+(Point a, Vector b);
Point operator-(Point a, Vector b);
Vector operator+(Vector a, Vector b);
Vector operator*(Vector a, FloatType b);
Vector operator*(FloatType a, Vector b);
Vector operator/(Vector a, FloatType b);
Vector operator-(Point a, Point b);

Line operator+(Line a, Vector v);
Line operator-(Line a, Vector v);
Line operator*(Line a, FloatType b);
Line operator/(Line a, FloatType b);

FloatType DotProduct(Vector a, Vector b);
FloatType CrossProduct(Vector a, Vector b);

FloatType Length(Vector a);
FloatType Length(Segment a);

FloatType Distance(Point a, Line b);
FloatType Distance(Point a, Point b);
FloatType Distance(Point a, Segment b);
FloatType Distance(Point a, Ray b);

FloatType Distance(Line a, Point b);
FloatType Distance(Ray a, Point b);
FloatType Distance(Segment a, Point b);
inline FloatType Sqr(const FloatType &a);

FloatType Distance(Line a, Ray b);
FloatType Distance(Line a, Line b);
FloatType Distance(Line a, Segment b);
FloatType Distance(Ray a, Line b);
FloatType Distance(Ray a, Ray b);
FloatType Distance(Ray a, Segment b);
FloatType Distance(Segment a, Line b);
FloatType Distance(Segment a, Ray b); //TODO: implement
FloatType Distance(Segment a, Segment b); //TODO: implement
FloatType GetDeterminant(FloatType a, FloatType b, FloatType c, FloatType d);

Intersection Intersect(Line a, Line b);
Intersection Intersect(Line a, Ray b);
Intersection Intersect(Line a, Segment b);
Intersection Intersect(Ray a, Line b);
Intersection Intersect(Segment a, Line b);

std::vector<Point> Intersect(Ray a, Point b); //TODO: avoid
std::vector<Point> Intersect(Ray a, Ray b); //TODO: return type = Intersection(None, Point, Segment, Ray)
std::vector<Point> Intersect(Ray a, Segment b); //TODO: return type = Intersection(None, Point, Segment)
std::vector<Point> Intersect(Segment a, Point b); //TODO: avoid
std::vector<Point> Intersect(Segment a, Segment b); //TODO: return type = Intersection(None, Point, Segment)
std::vector<Point> Intersect(Segment a, Ray b); //TODO: return type = Intersection(None, Point, Segment)

Point CastToPoint(Intersection is);
Line CastToLine(Intersection is);
Segment CastToSegment(Intersection is);
Ray CastToRay(Intersection is);

Point CastToPoint(Intersection is)
{
	if (is.t != POINT)
		throw;
	return *((Point*)is.data);
}

Line CastToLine(Intersection is)
{
	if (is.t != POINT)
		throw;
	return *((Line*)is.data);
}

Segment CastToSegment(Intersection is)
{
	if (is.t != POINT)
		throw;
	return *((Segment*)is.data);
}

Ray CastToRay(Intersection is)
{
	if (is.t != POINT)
		throw;
	return *((Ray*)is.data);
}


bool Equal(const FloatType a, const FloatType b)
{
	return std::abs(a - b) <= EPS;
}

bool operator==(Point a, Point b)
{
	return Equal(a.x, b.y) and Equal(a.y, b.y);
}

bool operator==(Vector a, Vector b)
{
	return Equal(a.x, b.x) and Equal(a.y, b.y);
}

bool operator==(Line a, Line b)
{
	FloatType len_a = std::sqrt((a.a * a.a) + (a.b * a.b));
	FloatType len_b = std::sqrt((b.a * b.a) + (b.b * b.b));
	return Equal(a.a / len_a, b.a / len_b) and Equal(a.b / len_a, b.b / len_b) and Equal(a.c / len_a, b.c / len_b);
}

Point operator+(Point a, Vector b)
{
	return {a.x + b.x, a.y + b.y};
}

Point operator-(Point a, Vector b)
{
	return {a.x - b.x, a.y - b.y};
}

Vector operator+(Vector a, Vector b)
{
	return {a.x + b.x, a.y + b.y};
}

Vector operator*(Vector a, FloatType b)
{
	return {a.x * b, a.y * b};
}
Vector operator*(FloatType a, Vector b)
{
	return {b.x * a, b.y * a};
}

Vector operator/(Vector a, FloatType b)
{
	return {a.x / b, a.y / b};
}

Vector operator-(Point a, Point b)
{
	return {b.x - a.x, b.y - a.y};
}

bool operator==(Ray a, Ray b)
{
	return a.p == b.p and a.v / Length(a.v) == b.v / Length(b.v);
}

bool operator==(Segment a, Segment b)
{
	return ((a.a == b.a) and (a.b == b.b)) or ((a.b == b.a) and (a.a == b.b));
}

Point GetPoint(FloatType x, FloatType y)
{
	return {x, y};
}

Point GetPoint(Vector v)
{
	return {v.x, v.y};
}

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

Line GetLine(FloatType a, FloatType b, FloatType c)
{
	if(Equal(a, 0) and Equal(b, 0))
		throw;
	return {a, b, c};
}

Line GetLine(Point a, Point b)
{
	if(a == b)
		throw;
	return {b.y - a.y, a.x - b.x, b.x * a.y - a.x * b.y};
};

Line GetLine(Point a, Vector v)
{
	if(Equal(v.x, 0) and Equal(v.y, 0))
		throw;
	return {v.y, -v.x, a.y * v.x - a.x * v.y};
}

Line GetLine(Ray r)
{
	if(Equal(r.v.x, 0) and Equal(r.v.y, 0))
		throw;
	return {r.v.y, -r.v.x, r.p.y * r.v.x - r.p.x * r.v.y};
}

Line GetLine(Segment s)
{
	if(s.a == s.b)
		throw;
	return {s.b.y - s.a.y, s.a.x - s.b.x, s.b.x * s.a.y - s.a.x * s.b.y};
}

Segment GetSegment(Point a, Point b)
{
	return {a, b};
}

Segment GetSegment(Point a, Vector v)
{
	return {a, GetPoint(a.x + v.x, a.y + v.y)};
}

Ray GetRay(Point a, Point b)
{
	return {a, GetVector(a, b)};
}

Ray GetRay(Point a, Vector v)
{
	return {a, v};
}
 

Vector GetNormalVector(Line a)
{
	return GetVector(a.a, a.b);
}

Vector GetNormalForm(Vector v)
{
	FloatType len = std::sqrt(v.x * v.x + v.y * v.y);
	return GetVector(v.x / len, v.y / len);
}

Vector GetDirectiveVector(Ray a)
{
	return a.v;
}

std::istream& operator>>(std::istream& in, Point& a)
{
	in >> a.x >> a.y;
	return in;
}

std::ostream& operator<<(std::ostream& out, Point a)
{
	out << a.x << " " << a.y;
	return out;
}

std::istream& operator>>(std::istream& in, Vector& a)
{
	in >> a.y >> a.y;
	return in;
}

std::ostream& operator<<(std::ostream& out, Vector a)
{
	out << a.x << " " << a.y;
	return out;
}

std::istream& operator>>(std::istream& in, Segment& a)
{
	in >> a.a >> a.b;
	return in;
}

std::ostream& operator<<(std::ostream& out, Segment a)
{
	out << a.a << " " << a.b;
	return out;
}

std::istream& operator>>(std::istream& in, Ray& a)
{
	in >> a.p >> a.v;
	return in;
}

std::ostream& operator<<(std::ostream& out, Ray a)
{
	out << a.p << " " << a.v;
	return out;
}

Line operator+(Line a, Vector v)
{
	return {a.a, a.b, a.c + DotProduct(GetNormalForm(GetNormalVector(a)), v)};
}

Line operator-(Line a, Vector v)
{
	return {a.a, a.b, a.c - DotProduct(GetNormalForm(GetNormalVector(a)), v)};
}

FloatType DotProduct(Vector a, Vector b)
{
	return a.x * b.x + a.y * b.y;
}

FloatType CrossProduct(Vector a, Vector b)
{
	return a.x * b.y - a.y * b.x;
}

Line operator*(Line a, FloatType b)
{
	return GetLine(a.a * b, a.b * b, a.c * b);
}

Line operator/(Line a, FloatType b)
{
	return GetLine(a.a / b, a.b / b, a.c / b);
}

FloatType Length(Vector a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

FloatType Length(Segment a)
{
	return Length(a.a - a.b);
}

FloatType Distance(Point a, Line b)
{
	FloatType err = std::sqrt(b.a * b.a + b.b * b.b);
	return (a.x * b.a + a.y * b.b + b.c) / err;
}

inline FloatType Sqr(const FloatType &a)
{
	return a * a;
}

FloatType Distance(Point a, Point b)
{
	return std::sqrt(Sqr(a.x - b.x) + Sqr(a.y - b.y));
}

FloatType Distance(Point a, Ray b)
{
	if (DotProduct(b.v, GetVector(b.p, a)) < 0)
		return Distance(a, b.p);
	return Distance(a, GetLine(b));
}

FloatType Distance(Point a, Segment b)
{
	return std::max(Distance(a, GetRay(b.a, b.b)), Distance(a, GetRay(b.b, b.a)));
}

FloatType Distance(Line a, Point b)
{
	return Distance(b, a);
}

FloatType Distance(Ray a, Point b)
{
	return Distance(b, a);
}

FloatType Distance(Segment a, Point b)
{
	return Distance(b, a);
}

Intersection GetIntersection(TypeOfIntersect t, void* data)
{
	Intersection a;
	a.t = t;
	a.data = data;
	return a;
}

Intersection GetIntersection()
{
	return GetIntersection(NONE, (void*)(new int()));
}

Intersection GetIntersection(Point a)
{
	return GetIntersection(POINT, ((void*)(&a)));
}

Intersection GetIntersection(Line a)
{
	return GetIntersection(LINE , ((void*)(&a)));
}

Intersection GetIntersection(Ray a)
{
	return GetIntersection(RAY, ((void*)(&a)));
}

Intersection GetIntersection(Segment a)
{
	return GetIntersection(SEGMENT, ((void*)(&a)));
}

bool IsParallel(const Line &a, const Line &b)
{
	return Equal(a.a * b.b - a.b * b.a, 0);
}

FloatType GetDeterminant(FloatType a, FloatType b, FloatType c, FloatType d)
{
	return a * d - c * b;
}

Intersection Intersect(Line a, Line b)
{
	FloatType zn = GetDeterminant(a.a, a.b, b.a, b.b);
	if (Equal(zn, 0))
	{
		return GetIntersection();
	}
	return GetIntersection(GetPoint(-GetDeterminant(a.c, a.b, b.c, b.b) / zn,
				-GetDeterminant(a.a, a.c, b.a, b.c) / zn));
}

bool OnLine(Line a, Point b)
{
	return Equal(a.a * b.x + a.b + b.y + a.c, 0);
}

bool OnRay(Ray a, Point b)
{
	return Equal(CrossProduct(a.v, b - a.p), 0) and DotProduct(a.v, b - a.p) >= 0;
}

bool OnSegment(Segment a, Point b)
{
	return OnRay(GetRay(a.a, a.b), b) and DotProduct(a.a - a.b, b - a.b) >= 0;
}

Intersection Intersect(Line a, Ray b)
{
	Intersection its = Intersect(a, GetLine(b));
	if (its.t == NONE)
		return its;
	if (its.t == LINE)
		return GetIntersection(b);
	Point p = CastToPoint(its);
	if (OnRay(b, p))
		return its;
	else
		return GetIntersection();
}

Intersection Intersect(Line a, Segment b)
{
	Intersection its = Intersect(a, GetLine(b));
	if (its.t == NONE)
		return its;
	if (its.t == LINE)
		return GetIntersection(b);
	Point p = CastToPoint(its);
	if (OnSegment(b, p))
		return its;
	else
		return GetIntersection();
}

Intersection Intersect(Ray a, Line b)
{
	return Intersect(b, a);
}

Intersection Intersect(Segment a, Line b)
{
	return Intersect(b, a);
}

}

#endif //GEOMLIB_LIBRARY_H
