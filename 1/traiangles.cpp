#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
class Point3D
{
		private:
		 double x_,y_,z_;		 
		public:
		 void init(double x,double y,double z);	
		 void init();	
		 // optimisation by passing a constant reference
		 bool compare(const Point3D& point2) const;	
		 void getCoords(double& x,double& y, double& z) const;
		 void display() const;
};

class Triangle
{
	private: 
		double d01_,d02_,d12_;
		vector<Point3D> points;
		double getDistance(const Point3D& p1,const Point3D& p2) const;		
	    void createPoint(int i);
	public:
		void constructTriangle();
	    void calculatePerimetre();
};


int main(){
	Triangle tri;
	cout<<"constructing Triangle"<<endl;
	tri.constructTriangle();
	tri.calculatePerimetre();
}

void Triangle::constructTriangle()
{
	points.resize(3);
	for(auto& p:points)
	{
		p.init();
	}
}

void Triangle::calculatePerimetre(){
	
	d01_=getDistance(points[0],points[1]);
	d02_=getDistance(points[0],points[2]);
	d12_=getDistance(points[1],points[2]);
	cout<<" Perimeter="<<(d01_+d02_+d12_)<<endl;
	
	if(	d01_ == d02_ ||  d01_ == d12_ || d02_ == d12_)
	{
		cout<<" Triangle is isoceles"<<endl;
	}
	else
	{
		cout<<" Triangle not isoceles"<<endl;
	}
}
double Triangle::getDistance(const Point3D& p1,const Point3D& p2) const{
	double x,y,z;
	double x1,y1,z1;
	p1.getCoords(x,y,z);
	p2.getCoords(x1,y1,z1);
	return sqrt ((x1-x)*(x1-x) + (y1-y)*(y1-y) +(z1-z)*(z1-z) );
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
 
  void Point3D::init()
 {
	cout<<" Creating point "<<endl;
	cout<<" Enter x "; cin>>x_;
	cout<<" Enter y "; cin>>y_;
	cout<<" Enter z "; cin>>z_;
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
