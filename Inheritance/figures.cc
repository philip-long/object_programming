#include <iostream>
#include <cmath>

using namespace std;

class Figure{
	protected: 
		double x,y;
	public:
		Figure(double x,double y):x(x),y(y){}
		void display(ostream& sortie){
				sortie<<"x= "<<x<<", y= "<<y;
			}
			
		void GetOrigin(double& px, double& py){ px=x;py=y;};
		void SetOrigin(double  px, double  py){ x=px;y=py;};
	
};
class Rectangle : public Figure{
	protected: 
		double width;
		double height;		
	public:
		Rectangle(double w,double h,double x=0.0, double y=0.0): Figure(x,y),width(w),height(h) 
		{
			};
		double surface() const {return width*height;};
		double Width() const {return width;};
		double Height() const {return height;};
};

class Circle : public Figure{
	private: 
		double radius;
	public:
		Circle (double radius,double x=0.0, double y=0.0):Figure(x,y),radius(radius) {};
		double surface() const {return M_PI*radius*radius;};
		double Radius() const {return radius;};
		void display(ostream& sortie){Figure::display(sortie); sortie<<" radius= "<<radius; } 
};

class ColouredRectangle : public Rectangle
{
	private:
		unsigned int colour;
	public:
		ColouredRectangle (double width,double height, unsigned int colour): Rectangle(width,height),colour(colour)
		{
		};
		unsigned int Colour() const {return colour;};
	
};



int main(){
	Rectangle r(0.1,0.2,0.5,0.3);
	Circle c(0.1,0.5,0.1);
	ColouredRectangle cr(3.0,20.0,2);
	cout<<cr.Width()<<endl;
	c.SetOrigin(0.2,0.6);
	r.SetOrigin(0.2,0.6);
	r.display(cout);
	c.display(cout);
	return 0;
}
