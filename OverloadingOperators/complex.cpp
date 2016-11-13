#include <iostream>

using namespace std;
class Complex{
	private:
		double real;
		double imag;
	public:
		void display(ostream& out) const;	
		Complex (double x=0.0, double y=0.0) :real(x),imag(y) {}
		bool operator ==(const Complex& other) const;
		Complex& operator +=(const Complex& other);
		Complex&  operator -=(const Complex& other);
		Complex& operator *=(const Complex& other);
		Complex&  operator /=(const Complex& other);
		
		Complex operator +(const Complex& other) const;
		Complex  operator -(const Complex& other) const;
		Complex operator *(const Complex& other) const;
		Complex  operator /(const Complex& other) const;
		
		double Real() const;
		double Imag() const;
};

Complex& Complex::operator +=(const Complex& other){
	real+=other.real;
	imag+=other.imag;
	return *this;
}
Complex&  Complex::operator -=(const Complex& other){
	real-=other.real;
	imag-=other.imag;
	return *this;
}
Complex& Complex::operator *=(const Complex& other){
	double old_real(real);
	real=real*other.real + imag*other.imag;
	imag=old_real*other.imag +imag*other.real;
	return *this;
}
Complex&  Complex::operator /=(const Complex& other){
	double old_real(real);
	real=(real*other.real +imag*other.imag) /( other.real*other.real + other.imag*other.imag);
	imag=(imag*other.real - old_real*other.imag)/( other.real*other.real + other.imag*other.imag);	
	return *this;
}
// Creates a copy this does not modify original
// returns the copy 
Complex Complex::operator +(const Complex& other) const{

	return(Complex(*this) +=other);
}
Complex Complex::operator -(const Complex& other) const{
	return(Complex(*this)-=other);
}
Complex Complex::operator *(const Complex& other) const{
	return(Complex(*this) *=other);
}
Complex Complex::operator /(const Complex& other) const{
	return(Complex(*this) /=other);
}

bool Complex::operator ==(const Complex& other) const{
	
	return real==other.real and imag==other.imag;	
}
void Complex::display(ostream& out) const{
	out<<real<<" + "<<imag<<"j";
}

double Complex::Real() const{
	return real;
}
double Complex::Imag() const{
	return imag;
}
//===================================================================
//-------------------------------------------------------------------
ostream& operator <<(ostream& out,const Complex& z){
	//z.display(out);
	return cout<<"("<<z.Real()<<", "<<z.Imag()<<")"<<endl;
}

const Complex operator+(double x,Complex const& z2)
{	
	return Complex(x)+z2;
}
const Complex operator-(double x,Complex const& z2)
{	
	return Complex(x)-z2;
}
const Complex operator*(double x,Complex const& z2)
{	
	return Complex(x)*z2;
}

const Complex operator/(double x,Complex const& z2)
{	
	return Complex(x)/z2;
}



int main(){
	Complex z1;
	Complex defaut;
	Complex zero(0.0, 0.0);
	Complex one(1.0,0.0);
	Complex i(0.0, 1.0);
	Complex j;
	
	i+=j+=i;
	cout<<"i"<<i<<endl;
	cout << zero << " ==? " << defaut;
	if (zero == defaut) cout << " oui" << endl;
	else cout << " non" << endl;
	
	j = one + i;
	cout << one << " + " << i << " = " << j << endl;
	Complex trois(one);
	trois += one;
	trois += 1.0;
	cout << one << " + " << one << " + 1.0 = " << trois << endl;
	Complex deux(trois);
	deux -= one;
	cout << trois << " - " << one << " = " << deux << endl;
	trois = 1.0 + deux;
	cout << "Here 1.0 + " << deux << " = " << trois << endl;
	trois =  deux+2.0;
	cout << "Here 1.0 + " << deux << " = " << trois << endl;
	Complex z(i*i);
	cout << i << " * " << i << " = " << z << endl;
	cout << z << " / " << i << " = " << z/i << " = ";
	cout << (z/=i) << endl;
	
	
	//====================
	Complex a,b;
	a=a+b;
	a++b;
	a+=a+b;
	return 0;
}
