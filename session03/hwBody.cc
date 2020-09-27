#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <vector>

using namespace std;

class AnyType {
public:
	~AnyType() = default;
};

template<typename T>
class Any: public AnyType {
private:
	T val;
public:
	Any(T value): val(value) {}
	friend ostream& operator <<(ostream& s, Any a) {
		return s << a.val;
	}
friend class Body;
};

class Body {
private:

	string name, orbits;
	const double mass, diam, peri, aphe, orbper, rotper, axtlt, orbincln;
	double x, y, z;
	map<string, AnyType*> attrib;

	void printBody() {
		for (auto elem : attrib) {
			cout << elem.first << " " << elem.second << endl;
		}
	}

	void initAttribs() {
		attrib["Name"] = new Any<string>(name);
		attrib["Orbits"] = new Any<string>(orbits);
		attrib["Mass(kg)"] = new Any<double>(mass);
		attrib["Diam(m)"] = new Any<double>(diam);
		attrib["Perihelion(m)"] = new Any<double>(peri);
		attrib["Aphelion(m)"] = new Any<double>(aphe);
		attrib["orbPeriod(days)"] = new Any<double>(orbper);
		attrib["rotationalPeriod(hours)"] = new Any<double>(rotper);
		attrib["axialtilt(deg)"] = new Any<double>(axtlt);
		attrib["orbinclin(deg)"] = new Any<double>(orbincln);
	}

public:
	Body(string& name, string& orbits, double mass, double diam, double peri, double aphe, double orbper, 
		double rotper, double axtlt, double orbincln, double x, double y, double z): 
			name(name), orbits(orbits), mass(mass), diam(diam), peri(peri), aphe(aphe), 
			orbper(orbper), rotper(rotper), axtlt(axtlt), orbincln(orbincln), x(x), y(y), z(z) {
			initAttribs();
	}
	

	friend ostream& operator <<(ostream& s, Body b) {
		// b.printBody();
		return s << "Name: " << b.name << " Orbits: " << b.orbits;
	}
};

int main() {
	stringstream ss; 
	string line;

	string name, orbits;
	double mass, diam, peri, aphe, orbper, rotper, axtlt, orbincln;

	vector<Body> bodies;
	ifstream f("solarsystem.dat");
	while (getline(f, line)) {
		cout << line << endl;
		ss >> line;
		ss << name << orbits << mass << diam << peri
			<< aphe << orbper << rotper << axtlt << orbincln;
		
		bodies.push_back(Body(name, orbits, mass, diam, peri, aphe, orbper, rotper, axtlt, orbincln, 1, 2, 3));
	}

	for (auto body : bodies) {
		cout << body << endl;
	}
}	
	
