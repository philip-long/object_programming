#include <iostream>
#include <cmath>

using namespace std;
struct Point{
	double x;
	double y;
};

class Circle{
	private:
		double radius_;
		Point centre_;
	public:
		void setCentre(Point p);
		void getCentre(Point& p) const;
		void Radius(double radius);
		double Radius() const;
		double Surface() const;
		bool isInside(Point p) const;
	};

void Circle::Radius(double radius)
{
	if(radius>0.0)
	{
	radius_=radius;
	}
	else
	{
	radius_=0.0;	
	}
}

double Circle::Radius() const
{
	return radius_;
}
void Circle::setCentre(Point p)
{
	centre_.x=p.x;
	centre_.y=p.y;
}
void Circle::getCentre(Point& p) const
{
	p=centre_;
}

double Circle::Surface() const
{
	return M_PI*radius_*radius_;
}
bool  Circle::isInside(Point p) const
{
	if ((( (p.x-centre_.x)*(p.x-centre_.x)) + ( (p.y-centre_.y)*(p.y-centre_.y)) ) > radius_*radius_ ) 
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	Circle circle;
	Point p1,p2;
	double radius;
	cout<<"centre x";cin>>p2.x;
	cout<<"centre y";cin>>p2.y;
	cout<<"radius ";cin>>radius;
	circle.setCentre(p2);
	circle.Radius(radius);
	cout<<"Point x";cin>>p1.x;
	cout<<"Point y";cin>>p1.y;
	
	cout<<"Surface area is "<<circle.Surface()<<endl;
	cout<<"Does point ("<<p1.x<<", "<<p1.y<<") lie in circle?   "<<circle.isInside(p1)<<endl;
	return 1;
	}
