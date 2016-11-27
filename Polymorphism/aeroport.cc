#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
using namespace std;


class Vehicle{
	public :
		virtual void display(ostream& out)=0;
		virtual ~Vehicle() {}
		Vehicle(string type,double price) :type(type),price(price) {}
	protected: 
		string type ;
		double price;
};

class Plane : public Vehicle{
	public :
		Plane(string type,double price) :Vehicle(type,price){}
		void display(ostream& out)  {
			out<<"This is a plane "<<type<< " Price= "<<price<< endl;
			
		}
};
class Car : public Vehicle{
	private:
		double km;
	public :
			Car(string type,double price,double km) :Vehicle(type,price),km(km){}
			void display(ostream& out)  {
			out<<"This is a car "<<type<< " Price= "<<price<< "Km= "<<km<<endl;
		}
};


class Aeroport{
	private :
		vector<unique_ptr<Vehicle>> p;
	public :
	void display_vehicles(ostream& out) const;
	void add_vehicles(Vehicle* v);
	void remove_vehicles();
	void delete_vehicles();
	
};

void Aeroport::add_vehicles(Vehicle* v){
	if(v!=nullptr)
	{
		p.push_back(unique_ptr<Vehicle>(v));
	}
}

void Aeroport::display_vehicles(ostream& out) const{
	for(auto const& i:p)
	{
		i->display(out);
	}
}
void Aeroport::remove_vehicles() {
	p.clear();
}

ostream& operator<<(ostream& out,const Aeroport& f){
	f.display_vehicles(out);
	return out;
}
void Aeroport::delete_vehicles(){
remove_vehicles();
}

int main(){
	Aeroport aer;
	
	aer.add_vehicles(new Car("fiat",100.0,10000));
	aer.add_vehicles(new Plane("Airbus",100000.0));
	cout<<aer<<endl;
	return 0;
}
