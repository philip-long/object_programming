#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Animal{	
	protected :
		string name;
		string continent;
	public : 
		Animal (string name,string continent)
			: name(name),continent(continent)
			 { cout<< "New Animal protected  !" <<endl; }
		~Animal() { cout<< "No longer protected !" <<endl; }
		void display() const {
			cout<<" I am a "<<name<<" and I live in "<<continent<<endl;
		}
};

class Endangered{
	protected:
		unsigned int number;
	public:
		Endangered(unsigned int number=270) : number(number) 
		{
			cout<<"New endangered animanl"<<endl;
		}
		~Endangered()
		{
			cout<<"No longer endangered "<<endl;
		}
		void display() const {
			cout<<" There are only "<<number<<" individuals left"<<endl;
		}
};


class Gadget{
	protected:
		string name;
		double price;
	public:
		Gadget(string name, double price) : name(name),price(price) 
		{
			cout<<"New gadget"<<endl;
		}
		~Gadget() {
			cout<<"No longer a  gadget"<<endl;
		}
		void display() const {
			cout<<" My name is "<<name<<endl;
		}
		void display_price() const {
			cout<<" Buy me for "<<price<<" euro and help save my speices"<<endl;
		}
};


class Teddy : public Animal, public Endangered , public Gadget
{
	
	public :
			Teddy(string type,
				  string name,
				 string continent,
				 unsigned int number,
				 double price) 
				 :
				 Animal(type,continent),
				 Endangered(number),
				 Gadget(name,price) {}				 
				 
			void label(){
				cout<<" Hello, "<<endl; 
				Gadget::display();
				Animal::display();
				Endangered::display();
				// no need to define scope as there 
				// is only one function of this name
				display_price(); 
			}
};

int main(){
	Teddy panda("Panda","Ming","Asie", 200, 20.0);
	Teddy serpent("Cobra","Ssss","Asie", 500, 10.0);
	Teddy toucan("Toucan","Bello","Amérique", 1000, 15.0);
	panda.label();
	serpent.label();
	toucan.label();
	return 0;
};
