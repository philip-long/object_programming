#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;


class Shape{
	private:
	protected:
	public:
		virtual void description() const { cout<<"This is a shape"<<endl;};
		virtual double area() const =0;
};

class Circle :public Shape{
	private:
		double radius_;
	protected:
	public:
		Circle(double radius=0.0):radius_(radius){}
		void description() const { cout<<"This is a circle of radius "<< radius_<<endl;};
		double area() const  {return M_PI*radius_*radius_;}
};

class Triangle :public Shape{
	private:
		double height_;
		double width_;
	protected:
	public:
		Triangle(double height=0.0,double width=0.0):height_(height),width_(width){}
		void description() const { cout<<"This is a triangle of height "<<height_<<" and width "<< width_<<endl;	};
		double area() const  {return 0.5*height_*width_;}
};

void displayDescription(Shape& f)
{
	f.description();
	cout<<"Area of this shape ="<<f.area()<<endl;
}

int main() {
	Circle c(0.2);
	Triangle t(0.2,0.5);
	displayDescription(c);
	displayDescription(t);
	return 0;
}
