/** @file library.h
 * Geometry library for sportive programming.
 */


#ifndef GEOMLIB_LIBRARY_H
#define GEOMLIB_LIBRARY_H

#include <istream>
#include <cmath>
#include <vector>

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
	Point a;
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

Point GetPointOnThisLine(Line a); //TODO: try to avoid
Vector GetNormalVector(Line a); //TODO: normalize?
Vector GetDirectiveVector(Line a); //TODO: normalize? nado li?
Vector GetNormalForm(Vector v); //TODO: implement
Vector GetDirectiveVector(Ray a); //TODO: implement, normalize?
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
std::ostream& operator<<(std::ostream& in, Vector a);
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
Line operator+(Line a, Vector v); //TODO: implement
Line operator-(Line a, Vector v); //TODO: implement
Line operator*(Line a, FloatType b);
Line operator/(Line a, FloatType b);
FloatType operator*(Vector a, Vector b); //TODO: replace with functions
FloatType operator^(Vector a, Vector b); //TODO: replace with functions
FloatType Length(Vector a);
FloatType Length(Segment a);
FloatType Distance(Point a, Line b);
FloatType Distance(Point a, Point b);
FloatType Distance(Point a, Segment b);
FloatType Distance(Point a, Ray b);
FloatType Distance(Line a, Ray b);
FloatType Distance(Line a, Line b);
FloatType Distance(Line a, Point b);
FloatType Distance(Line a, Segment b);
FloatType Distance(Ray a, Point b);
FloatType Distance(Ray a, Line b);
FloatType Distance(Ray a, Ray b);
FloatType Distance(Ray a, Segment b);
FloatType Distance(Segment a, Point b);
FloatType Distance(Segment a, Line b);
FloatType Distance(Segment a, Ray b); //TODO: implement
FloatType Distance(Segment a, Segment b); //TODO: implement
FloatType GetDeterminant(FloatType a, FloatType b, FloatType c, FloatType d);
std::vector<Point> Intersect(Point a, Line b); //TODO: avoid
std::vector<Point> Intersect(Point a, Ray b); //TODO: avoid
std::vector<Point> Intersect(Point a, Point b); //TODO: avoid
std::vector<Point> Intersect(Point a, Segment b); //TODO: avoid
std::vector<Point> Intersect(Line a, Line b); //TODO: return type = Intersection(None, Point, Line)
std::vector<Point> Intersect(Line a, Ray b); //TODO: return type = Intersection(None, Point, Ray)
std::vector<Point> Intersect(Line a, Point b); //TODO: avoid
std::vector<Point> Intersect(Line a, Segment b); //TODO: return type = Intersection(None, Point, Segment)
std::vector<Point> Intersect(Ray a, Line b); //TODO: return type = Intersection(None, Point, Ray)
std::vector<Point> Intersect(Ray a, Point b); //TODO: avoid
std::vector<Point> Intersect(Ray a, Ray b); //TODO: return type = Intersection(None, Point, Segment, Ray)
std::vector<Point> Intersect(Ray a, Segment b); //TODO: return type = Intersection(None, Point, Segment)
std::vector<Point> Intersect(Segment a, Point b); //TODO: avoid
std::vector<Point> Intersect(Segment a, Segment b); //TODO: return type = Intersection(None, Point, Segment)
std::vector<Point> Intersect(Segment a, Line b); //TODO: return type = Intersection(None, Point, Segment)
std::vector<Point> Intersect(Segment a, Ray b); //TODO: return type = Intersection(None, Point, Segment)

bool Equal(const FloatType a, const FloatType b)
{
	return std::abs(a - b) <= EPS;
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


#endif //GEOMLIB_LIBRARY_H
