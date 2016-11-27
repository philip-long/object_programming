#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Shape{
	private:
	protected:
	public:
		virtual void description() const { cout<<"This is a shape"<<endl;};
};

class Circle :public Shape{
	private:
	protected:
	public:
		void description() const { cout<<"This is a circle"<<endl;};
};

void displayDescription(Shape& f)
{
	f.description();
}

int main() {
	Shape f;
	Circle c;
	f.description();
	c.description();
	Shape f2(c);
	f2.description();
	displayDescription(c);
	return 0;
}
