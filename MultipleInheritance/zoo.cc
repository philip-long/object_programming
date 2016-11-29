#include <iostream>
#include <cmath>
using namespace std;

class Animal{
	public : 
		Animal () { cout<< "Animal Alive !" <<endl; }
		~Animal() { cout<< "Animal Dead  !" <<endl; }
};

class Vivipare : public virtual Animal{
	protected:
		unsigned int gestation;
	public:
		Vivipare(unsigned int days=270) : gestation(days) 
		{
			cout<<"Vivipare created"<<endl;
			}
		void birth() const;

};

void Vivipare::birth() const {
	cout<<" After "<<gestation<<" days of gestation I just had a new baby"<<endl;
}


class Ovipare: public virtual Animal{
	protected:
		unsigned int number_of_eggs;
	public:
		Ovipare(unsigned int eggs=270) : number_of_eggs(eggs) 
		{
			cout<<"Ovipare created eggs:"<<number_of_eggs<<endl;
		}
		void birth() const ;
};

void Ovipare::birth() const {
	cout<<" I just laid "<<number_of_eggs<<" eggs"<<endl;
}

class Ovovivipare : public Vivipare , public Ovipare{
	private :
		bool rare;
	public : 
		Ovovivipare (unsigned int days, unsigned int eggs, bool rare=false) :
			Vivipare(days),Ovipare(eggs),rare(rare) {};
		void birth() const;
};


void Ovovivipare::birth() const{
		cout<<"  After "<<gestation<<" days of gestation I just had "<<number_of_eggs<< " babies "<<endl;
}


int main(){
	Ovovivipare o(200,2);
	o.birth();
	return 0;
};
