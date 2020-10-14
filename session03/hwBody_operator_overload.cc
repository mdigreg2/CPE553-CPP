#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
using namespace std;

	default_random_engine gen(0);
	uniform_int_distribution<int> distribution(0, 99);

class Vec3d {
	public: 
		double x, y, z;
		Vec3d() {}
		Vec3d(double x, double y, double z): x(x), y(y), z(z){}

		friend ostream& operator <<(ostream& s, Vec3d v) {
			return s << "(" << v.x << "," << v.y << "," << v.z <<")";
		}
};

class Body {
	private:
		string name;
		double mass, radius;
		Vec3d position;
		int random = distribution(gen);
	public:
		Body() {}

		friend ostream& operator <<(ostream& s, Body &b) {
			return s << "Name: " << b.name << " Mass: " << b.mass << " Radius: " << b.radius << " Position: " << b.position;
		}
		friend void operator >>(istream &out, Body &b) {
				string i;
				vector<string> attribs;
				while (out >> i) {
					attribs.push_back(i);
				}
				if (attribs.size() != 10) {
					throw length_error("Invalid input length. Expected 10 columns");
				}
				b.name = attribs.at(0);
				b.mass = stod(attribs.at(2));
				b.radius = stod(attribs.at(3))/2;
				double rad = stod(attribs.at(4)) + stod(attribs.at(5)) / 2;
				b.position = Vec3d(rad*cos(b.random), rad*sin(b.random), 0);
		}
};

int main() {
	stringstream ss;
	string line;
	string name, orbits, mass, diam, rest;
	vector<Body> bodies;
	ifstream f("solarsystem.dat");

	int counter = 0;
	while(getline(f, line)) {
		if (line.substr(0, 4) == "Name")
			continue;
		Body b;
		ss << line;
		ss >> b;
		cout << b << endl;
		bodies.push_back(b);
		counter ++;
		ss.clear();
	}
}