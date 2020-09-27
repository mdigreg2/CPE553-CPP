#include <iostream>
#include <cmath>

using namespace std;

class Vec3d {
private:
	double x, y, z;
public:
	Vec3d(double x, double y, double z): x(x), y(y), z(z) {}
	Vec3d(double x, double y): x(x), y(y), z(0) {}
	Vec3d(double x): x(x), y(0), z(0) {}
	Vec3d(): x(0), y(0), z(0) {}
	
	double mag() const {
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	double magSq() const {
		return pow(x, 2) + pow(y, 2);
	}

	double dot(const Vec3d& a) const {
		return a.x * x + a.y * y + a.z * z;
	}

	double dist(const Vec3d& a) const {
		return sqrt(pow(a.x-x, 2) + pow(a.y-y, 2) + pow(a.z-z, 2));
	}

	friend double dot(const Vec3d& a, const Vec3d& b) {
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	friend Vec3d operator +(const Vec3d& a, const Vec3d& b) {
		return Vec3d(a.x+b.x, a.y+b.y, a.z+b.z);
	}

	friend Vec3d operator -(const Vec3d& a, const Vec3d& b) {
		return Vec3d(a.x-b.x, a.y-b.y, a.z-b.z);
	}

	friend Vec3d operator -(const Vec3d& a) {
		return Vec3d(-a.x, -a.y, -a.z);
	}

	friend ostream& operator <<(ostream& s, const Vec3d& v) {
		return s << '(' << v.x << ", " << v.y << ", " << v.z << ')';
	}

};


int main() {
	// Main() Section 1
	const Vec3d a(1.0,2.5,3.5); // double precision!
	const Vec3d b(2.0);         //(2,0,0)
	const Vec3d c(2.0,3.5);     //(2,3.5,0)
	const Vec3d d;              //(0,0,0)

	// Main() Section 2
	const Vec3d e = a + d;
	const Vec3d f = c - b;
	const Vec3d g = -e;
	
	// Main() Section 3	
	double r = dot(e, f); // regular function  e.x*f.x + e.y*f.y + e.z*f.z
	double s = e.dot(f); // method

	// Main() Section 4	
	double x = e.mag(); // square root of sum of square
	double y = e.magSq(); // sum of square
	double z = e.dist(f); // sqrt or sum of square of diff

	// Main() Section 5	
	cout << "a: " << a << '\n';
	cout << "b: " << b << '\n';
	cout << "c: " << c << '\n';
	cout << "d: " << d << '\n';
	cout << "e: " << e << '\n';
	cout << "f: " << f << '\n';
	cout << "g: " << g << '\n';
	cout << "r: " << r << '\n';
	cout << "s: " << s << '\n';
	cout << "x: " << x << '\n';
	cout << "y: " << y << '\n';
	cout << "z: " << z << '\n';
}	
