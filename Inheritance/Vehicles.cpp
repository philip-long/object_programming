#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Vehicle{
	protected:
		string brand;
		unsigned int date;
		double cost_price;
		double price;
	public:
		Vehicle (string brand,unsigned int date, double cost_price) 
				:brand(brand),date(date),cost_price(cost_price){}
		void display(ostream& sortie) const;	
		void calculatePrice(unsigned int current_year);	
};

class Car : public Vehicle
{
	private:
		double engine_size;
		unsigned int doors;
		double horsepower;
		double kilometres;
	public: 
		Car(string brand,
			unsigned int date,
			double cost_price,
			double engine_size,
			unsigned int doors,
			double horsepower,
			double kilometres
) : 
			Vehicle(brand,date,cost_price),engine_size(engine_size),doors(doors),horsepower(horsepower),kilometres(kilometres){};
			void display(ostream& sortie) const;	
			void calculatePrice(unsigned int current_year);
};

class Plane : public Vehicle
{
	private:
		string type;		
		double flight_hours;
	public: 
	  Plane(string brand,
			unsigned int date,
			double cost_price,
			string type,
			double flight_time
			) : 
			Vehicle(brand,date,cost_price),type(type),flight_hours(flight_time){};
			void display(ostream& sortie) const;	
			void calculatePrice(unsigned int current_year);
};

int main(){
	vector<Car> garage;
	vector<Plane>   hangar;
  garage.push_back(Car("Peugeot", 1998, 147325.79, 2.5, 5, 180.0,
                           12000));
  garage.push_back(Car("Porsche", 1985, 250000.00, 6.5, 2, 280.0,
                           81320));
  garage.push_back(Car("Fiat",    2001,   7327.30, 1.6, 3,  65.0, 
                           3000));
  hangar.push_back(Plane("Cessna",1972, 1230673.90, "propellor",  
                         250));
  hangar.push_back(Plane("Nain Connu", 1992, 4321098.00, "jet",
                         1300));
  for (auto car : garage) {
    car.calculatePrice(2015);
    car.display(cout);
  }
  for (auto plane : hangar) {
    plane.calculatePrice(2015);
    plane.display(cout);
  }
  return 0;
	
	return 0;
}

// displays
void Vehicle::display(ostream& sortie) const{
	sortie<<"brand= "<<brand<<", date= "<<date;
	sortie<<" Cost_price= "<<cost_price<<", price= "<<price;
}

void Car::display(ostream& sortie) const{
	Vehicle::display(sortie);
	sortie<<" engine_size= "<<engine_size<<" doors= "<<doors;
	sortie<<" horsepower= "<<horsepower<<" kilometres= "<<kilometres<<endl;
}

void Plane::display(ostream& sortie) const{
	Vehicle::display(sortie);
	sortie<<" type= "<<type<<" flight_time= "<<flight_hours<<endl;
}

// Get current price
void Vehicle::calculatePrice(unsigned int current_year) {
	price=cost_price;
	for(unsigned int i=0; i<(current_year-date);i++){
		price=price -(price*1.0/100.0);
	}
	if(price<0.0) price=0.0;
}

void Car::calculatePrice(unsigned int current_year) {
	
	price=cost_price;
	// depreciation
	for(unsigned int i=0; i<(current_year-date);i++){
		price=price -(price*0.02); // 2% for every year
	}
	double d(0.0);
	if(brand=="Renault" || brand=="Fiat")
	{
		d=0.1;
	}
	else if(brand=="Ferrari" || brand=="Porsche")
	{
		d=0.2;
	}
	else
	{
		d=0.0;
	}
	for(int i=0; i<(kilometres);i+=10000){
		price=price -(price*d/100.0); // 2% for every year
	}
	if(price<0.0) price=0.0;
	
}


void Plane::calculatePrice(unsigned int current_year) {
	
	price=cost_price;

	int d=0;
	if(type=="propellor")
	{
		d=100;
	}
	else if(type=="jet")
	{
		d=1000;
	}
	else
	{
		d=0;
	}
	for(int i=0; i<(flight_hours);i+=d){
		price=price -(price*0.1); // 2% for every year
	}
	if(price<0.0) price=0.0;
	
}
