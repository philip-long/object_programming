#include <iostream>
#include <cmath>

using namespace std;
class Point3D
{
		private:
		 double x_,y_,z_;
		public:
		 void init(double x,double y,double z);	
		 // optimisation by passing a constant reference
		 bool compare(const Point3D& point2) const;	
		 void getCoords(double& x,double& y, double& z) const;
		 void display() const;
};




int main(){
	Point3D point1;
	Point3D point2;
	Point3D point3;
	point1.init(1.0, 2.0, -0.1);
	point2.init(2.6, 3.5, 4.1);
	point3 = point1;
	cout << "Point 1 :";
	point1.display();
	cout << "Point 2 :";
	point2.display();
	cout << "point 1  is ";
if (point1.compare(point2)) {
	cout << "identical";
	} 
else {
	cout << "different to";
	}
	cout << " point 2." << endl;
	cout << "point 1  is ";
if (point1.compare(point3)) {
	cout << "identical";
	} 
else {
	cout << "different to";
	}
cout << " point 3." << endl;
}


void Point3D::getCoords(double& x,double& y, double& z) const
{
	x=x_;
	y=y_;
	z=z_;
}	
 void Point3D::init(double x,double y,double z)
 {
	x_=x;
	y_=y;
	z_=z;
 }
 bool Point3D::compare(const Point3D& point2) const
 {
	 double x2,y2,z2;
	point2.getCoords(x2,y2,z2);
	 return (x_==x2 && y_==y2 && z_==z2);		 
 }	
 void Point3D::display() const
 {
	 cout<<"x= "<<x_<<" y= "<<y_<<" z="<<z_<<endl;
 }
