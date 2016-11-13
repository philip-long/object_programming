#include <iostream>

using namespace std;
class Complex{
	private:
		double real;
		double imag;
	public:
		Complex (double x=0.0, double y=0.0) :real(x),imag(y) {}		
		Complex operator ++(){
			real++;
			return *this;
		}
		double Real() const{
			return real;
		}
		double Imag() const{
			return imag;
		}
		friend ostream& operator<<(ostream& out,const Complex& z);
};
ostream& operator <<(ostream& out,const Complex& z){
	//z.display(out);
	return cout<<"("<<z.real<<", "<<z.imag<<")"<<endl;
}



int main(){
	Complex z1(1.2,12);
	cout<<z1<<endl;
	
	
}
