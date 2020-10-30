#include <iostream>

using namespace std;
class Complex {
private:
	double real, im;
public:
	Complex(double real, double im) : real(real), im(im) {}

	friend Complex operator +(Complex a, Complex b) {
		return Complex(a.real + b.real, a.im + b.im);
	}

	friend Complex operator -(Complex c) {
		return Complex(-c.real, c.im);
	}

	friend ostream& operator <<(ostream& s, Complex c) {
		return s << "(" << c.real << "," << c.im << ")";
	}

	friend Complex operator *(const Complex& left, const Complex& right) {
		return Complex(left.real*right.real, left.im*right.im);
	}

};


int main() {
	const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
	const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
	const Complex c = a + b;   // overload operator + using member
	Complex d = -c; // use friend
	const Complex e = a * b;   // complex multiplication
	cout << c << '\t' << d << '\t' << e << '\n';
}