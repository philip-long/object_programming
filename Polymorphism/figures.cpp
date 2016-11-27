#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;


class Figure{
	private:
	protected:
	public:
		virtual void display() const =0;
		
		virtual unique_ptr<Figure> copy() const=0;
		virtual double area() const =0;
		virtual ~Figure(){}
};

class Circle :public Figure{
	private:
		double radius_;
	protected:
	public:
		Circle(double radius=0.0):radius_(radius){ cout<<"A Circle created"<<endl;}
		Circle(const Circle& c):Figure(c),radius_(c.radius_){cout<<"A Circle is copied"<<endl;}
		~Circle() {cout<<"A Circle is erased"<<endl;} 
		double area() const  {return M_PI*radius_*radius_;}
		void display() const { cout<<"This is a circle of radius "<< radius_<<endl;};
		// copy copies the current object
		// Circle(*this) creates a copy of the current object 
		// then this is placed in the memory with a dynamic allocation using new
		unique_ptr<Figure> copy() const override {
			return unique_ptr<Figure>(new Circle(*this)); }
};

class Triangle :public Figure{
	private:
		double height_;
		double width_;
	protected:
	public:
		Triangle(double height=0.0,double width=0.0):height_(height),width_(width){ cout<<"A Triangle created"<<endl;}
		Triangle(const Triangle& t):Figure(t),height_(t.height_),width_(t.width_){cout<<"A Triangle is copied"<<endl;}
		~Triangle() {cout<<"A Triangle is erased"<<endl;} 
		void display() const { cout<<"This is a triangle of height "<<height_<<" and width "<< width_<<endl;	};
		double area() const  {return 0.5*height_*width_;}
		unique_ptr<Figure> copy() const override {
			return unique_ptr<Figure>(new Triangle(*this)); }
};

class Square :public Figure{
	private:
		double width_;
	protected:
	public:
		Square(double width=0.0):width_(width){ cout<<"A square created"<<endl;}
		Square(const Square& s):Figure(s),width_(s.width_){cout<<"A square is copied"<<endl;}
		~Square() {cout<<"A Square is erased"<<endl;} 
		void display() const { cout<<"This is a square of width "<< width_<<endl;	};
		double area() const  {return width_*width_;}
		unique_ptr<Figure> copy() const override {
			return unique_ptr<Figure>(new Square(*this)); }
};

class Drawing{
	private:
		vector<unique_ptr<Figure>> collection;
	public: 
		void addFigure(const Figure& f);
		void deleteFigures() {
			collection.clear();
		}
		void display() const;
};

void Drawing::addFigure(const Figure& f){
		collection.push_back(f.copy());
}

void Drawing::display() const{
	for(auto const& i:collection){
		i->display();
	}
}


int main() {
	Drawing drawing;
	drawing.addFigure(Triangle(3,4));
	drawing.addFigure(Square(2));
	drawing.addFigure(Triangle(6,1));
	drawing.addFigure(Circle(12));
	cout << endl << "Affichage du dessin : " << endl;
	drawing.display();
}
