#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class A{
	public:
	A() {cout<<"A";}
	virtual ~A(){cout<<"a";}
};
class B : public A{
	public:
	B() {cout<<"B";}
	virtual ~B(){cout<<"b";}
};
class C :public  A{
	public:
	C() {cout<<"C";}
	virtual ~C(){cout<<"c";}
};
class D :public B, public C{
	public:
	D() {cout<<"D";}
	virtual ~D(){cout<<"d";}
};

int main(){
	D d;
}
