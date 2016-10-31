#include <iostream>
using namespace std;
class Rectangle{
	private:
		double height_;
		double width_;
	public:
	double surface() const;
	double Height() const;
	double Width() const;
	void Height(double s);
	void Width(double s);
	};


double Rectangle::surface() const
{
	return height_*width_;
}
double Rectangle::Height() const
{
	return height_;
}
double Rectangle::Width() const
{
	return width_;
}
void Rectangle::Height(double s)
{
	height_=s;
}
void Rectangle::Width(double s)
{
	width_=s;
}

int main()
{
	Rectangle rect;
	rect.Height(2.0);
	rect.Width(2.0);
	rect.surface();
	cout<<"height="<<rect.Height()<<endl;
}
