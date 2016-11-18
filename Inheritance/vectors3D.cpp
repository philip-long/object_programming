#include <iostream>
#include <cmath>
using namespace std;
class Point3D
{
		protected:
		 double x_,y_,z_;
		public:
		Point3D(double x,double y,double z):x_(x),y_(y),z_(z){}
		Point3D(const Point3D& other):x_(other.x_),y_(other.y_),z_(other.z_){}
		 // optimisation by passing a constant reference
		 bool compare(const Point3D& point2) const;	
		 void getCoords(double& x,double& y, double& z) const;
		 void display(ostream& sortie) const;
};

ostream& operator<<(ostream& out,const Point3D& f){
	f.display(out);
	return out;
}

void Point3D::getCoords(double& x,double& y, double& z) const
{
	x=x_;
	y=y_;
	z=z_;
}	

 bool Point3D::compare(const Point3D& point2) const
 {
	 double x2,y2,z2;
	point2.getCoords(x2,y2,z2);
	 return (x_==x2 && y_==y2 && z_==z2);		 
 }	
 void Point3D::display(ostream& sortie) const
 {
	 sortie<<"x= "<<x_<<" y= "<<y_<<" z="<<z_<<endl;
 }
 
class Vectors : public Point3D{
	private:
	
	public:
		Vectors(const Point3D& P) : Point3D(P) {}
		Vectors& operator+=(const Vectors&);
		Vectors& operator-=(const Vectors&);
		const Vectors operator-() const;
		Vectors& operator*=(double k);
		
};

Vectors& Vectors::operator+=(const Vectors& v)
{
		x_=x_+v.x_;
		y_=y_+v.x_;
		z_=z_+v.x_;
		return *this;
}
const Vectors operator+(Vectors v,const Vectors& v2){
	v+=v2;
	return v;
}
Vectors& Vectors::operator-=(const Vectors& v)
{
		x_=x_-v.x_;
		y_=y_-v.x_;
		z_=z_-v.x_;
		return *this;
}
const Vectors operator-(Vectors v,const Vectors& v2){
	v-=v2;
	return v;
}
const Vectors Vectors::operator-() const{
	Point3D p(-x_,-y_,-z_);
	Vectors v(p);
	return v;
}
Vectors& Vectors::operator*=(double k)
{
		x_=x_*k;
		y_=y_*k;
		z_=z_*k;
		return *this;
}

const Vectors operator*(Vectors v,double k)
{
		v*=k;
		return v;
}
const Vectors operator*(double k,const Vectors& v)
{
		v*=k;
		return v;
}
double operator*(const Vectors& v,const Vectors& v2)
{		
		double x,y,z;
		double i,j,k;
		v.getCoords(x,y,z);
		v2.getCoords(i,j,k);
		return (x*i)+(y*j)+(z*k);
}

double angle


int main(){
	return 0;
}
