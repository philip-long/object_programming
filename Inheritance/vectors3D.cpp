#include <iostream>
#include <cmath>
using namespace std;
class Point3D
{
		protected:
		 double x_,y_,z_;
		public:

		Point3D(double x=0.0,double y=0.0,double z=0.0):x_(x),y_(y),z_(z){}
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
	 sortie<<"("<<x_<<", "<<y_<<", "<<z_<<")";
 }
 

 
class Vector : public Point3D{
	private:
	
	public:
		
		// Constructor with point
		Vector(const Point3D& P) : Point3D(P) {}
		// Constructor without point
		Vector():Point3D(){}
		// Constructor with Coordinates
		Vector(double x,double y,double z) : Point3D(x,y,z) {}
		//
		Vector& operator+=(const Vector&);
		Vector& operator-=(const Vector&);
		const Vector operator-() const;
		Vector& operator*=(double k);
		double norm() const;
		
};

Vector& Vector::operator+=(const Vector& v)
{
		x_=x_+v.x_;
		y_=y_+v.y_;
		z_=z_+v.z_;
		return *this;
}

const Vector operator+(Vector v,const Vector& v2){
	v+=v2;
	return v;
}
Vector& Vector::operator-=(const Vector& v)
{
		x_=x_-v.x_;
		y_=y_-v.y_;
		z_=z_-v.z_;
		return *this;
}
const Vector operator-(Vector v,const Vector& v2){
	v-=v2;
	return v;
}
const Vector Vector::operator-() const{
	//Point3D p(-x_,-y_,-z_);
	// Vector v(p);
	Vector v(-x_,-y_,-z_);	
	return v;
}
Vector& Vector::operator*=(double k)
{
		x_=x_*k;
		y_=y_*k;
		z_=z_*k;
		return *this;
}

const Vector operator*(Vector v,double k)
{
		v*=k;
		return v;
}
const Vector operator*(double k,const Vector& v)
{
		return v*k;
}


// Solution recommends an internal overload
double operator*(const Vector& v,const Vector& v2)
{		
		double x,y,z;
		double i,j,k;
		v.getCoords(x,y,z);
		v2.getCoords(i,j,k);
		return (x*i)+(y*j)+(z*k);
}
double Vector::norm() const {
			//return pow((x_*x_)+ (y_*y_) + (z_*z_) , 0.5);
			// the solution is neater
			double p=sqrt(*this * *this);
			return p;
}

double angle(const Vector& v1, const Vector& v2)
{ 
	return acos((v1 * v2) / (v1.norm() * v2.norm())); 
}


int main(){
	Point3D p0;
	Point3D p1(1.0,2.0,-0.1);
	Point3D p2(2.6,3.5,4.1);
	Point3D p3(0,0,0);
	
	Vector v1(p1);
	Vector v2(p2);
	Vector v3;
	
	cout<<v1<<"+ "<<v2<<"= "<<(v1+v2)<<endl;
	cout<<v2<<"+ "<<v1<<"= "<<(v2+v1)<<endl;
	cout<<v1<<"+ "<<v3<<"= "<<(v1+v3)<<endl;
	cout<<v3<<"+ "<<v1<<"= "<<(v3+v1)<<endl;
	
	cout<<v1<<"- "<<v2<<"= "<<(v1-v2)<<endl;
	cout<<v2<<"- "<<v2<<"= "<<(v2-v2)<<endl;
	cout<<"- "<<v1<<"= "<<(-v1)<<endl;
	cout<<"- "<<v2<<" + "<<v1<<"= "<<(-v2+v1)<<endl;


	cout<<"3 *"<<v1<<"= "<<(3*v1)<<endl;
	cout<<v1<<"* "<<v2<<"= "<<(v1*v2)<<endl;
	cout<<v2<<"* "<<v1<<"= "<<(v2*v1)<<endl;
	cout<<"|| "<<v1<<"||"<<(v1.norm())<<endl;
	cout<<"|| "<<v2<<"||"<<(v2.norm())<<endl;
	cout<<"angle("<<v2<<",+ "<<v1<<")="<<angle(v2,v1)<<endl;

	return 0;
}
