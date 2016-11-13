//Le but de cet exercice est d'illustrer par un exemple détaillé, d'une part la manière d'écrire les constructeurs et destructeurs, et d'autre part de
//mettre en évidence leur fonctionnement.
//On propose pour cela de jouer avec des animaux en peluche. Ces peluches seront caractérisées par l'espèce de l'animal représenté, le nom
//donné à la peluche ainsi que son prix de vente.
//Avec vos connaissances de la semaine passée, commencez à écrire une première base pour modeliser les animaux en peluche (attributs,
//accesseurs, modificateur). On considèrera que les attributs espece et nom ne changent plus une fois qu'une peluche d'une espèce donnée
//est fabriquée (on ne la transforme pas en une autre), ce qui n'est pas le cas du prix ; on fournira donc pour ce seul attribut une méthode
//permettant d'en changer la valeur.
#include <iostream>
#include <string>
using namespace std;


class Teddy{
	public:
		// Constructor
		Teddy(double price,string name,string type) : price_(price),name_(name), type_(type) 
		{
			cout<<name_ << " is born" << endl;
		}
		
		Teddy(const Teddy& Ted) : price_(Ted.Price()),name_(Ted.Name()+"_copy"), type_(Ted.Type())
		{
			
			cout << "Copying teddy" << endl;
		}

		~Teddy(){
			cout<<"I am destroying " << name_<<endl;
		}
		void Price(double price);
		//Accesors
		double Price() const;		
		string Name() const;
		string Type() const;
		// Modifiers

		
		
	private:
		double price_;
		string name_;
		string const type_;
};

void label(const Teddy& ted){
	cout << "Hello, my name is " << ted.Name() << endl
	<< "I am a " << ted.Type() << " and I cost "
	<< ted.Price() << " euro" << endl;
};

int main(){
	
	Teddy ted(1.2,"teddy_bear","bear");
	cout<<"label"<<endl;
	label(ted);
	Teddy* bello; // pas encore d'objet, juste un pointeur
	{
	Teddy ssss(10.00,"ssss", "Cobra");
	bello = new Teddy(20.00,"Bello","toucan");
	}
	Teddy bello_clone(*bello);
	label(bello_clone);
	delete bello;
	return 0;
}


void Teddy::Price(double price)
{
	price_=price;
}

double Teddy::Price() const
{
	return price_;
}

string Teddy::Name() const
{
	return name_;
}
string Teddy::Type() const{
	return type_;
}
