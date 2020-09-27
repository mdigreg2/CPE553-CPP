#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <vector>

using namespace std;

class Body {
private:

	string name, orbits;
	const double mass, diam, peri, aphe, orbper, rotper, axtlt, orbincln;
	double x, y, z;

public:
	Body(string& name, string& orbits, double mass, double diam, double peri, double aphe, double orbper, 
		double rotper, double axtlt, double orbincln, double x, double y, double z): 
			name(name), orbits(orbits), mass(mass), diam(diam), peri(peri), aphe(aphe), 
			orbper(orbper), rotper(rotper), axtlt(axtlt), orbincln(orbincln), x(x), y(y), z(z) { }
	

	friend ostream& operator <<(ostream& s, Body b) {
		return s << "Name: " << b.name << "\n\tOrbits: " << b.orbits
		<< "\n\tMass: " << b.mass << "\n\tDiam: " << b.diam << "\n\tPerihelion: " << b.peri
		<< "\n\tAphelion: " << b.aphe << "\n\tOrbital Period: " << b.orbper << "\n\tRotational Period: "
		<< b.rotper << "\n\tAxial Tilt: " << b.axtlt << "\n\tOrbital Incline: " << b.orbincln << endl;
	}
};

int main() {
	stringstream ss; 
	string line;

	string name, orbits, mass, diam, peri, aphe, orbper, rotper, axtlt, orbincln;
	string attributes[] = {name, orbits, mass, diam, peri, aphe, orbper, rotper, axtlt, orbincln};
	vector<Body> bodies;
	ifstream f("solarsystem.dat");
	while (getline(f, line)) {
		if (line.substr(0, 4) == "Name")
			continue;
		ss << line;
		ss >> name >> orbits >> mass >> diam >> peri >> aphe >> orbper >> rotper >> axtlt >> orbincln;

		for (auto s : attributes) {
			if (s == "NaN")
				s = "0";
		}

		bodies.push_back(Body(name, orbits, stod(mass), stod(diam), stod(peri), stod(aphe), stod(orbper), stod(rotper), stod(axtlt), stod(orbincln), 1, 2, 3));
		ss.clear();
	}

	for (auto body : bodies) {
		cout << body << endl;
	}
}	
	
