#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
	Flacon(string name,double volume,double pH)
			: nom(name),volume(volume),pH(pH) {};
	Flacon()=delete; // delete default constuctor		
	
	ostream& etiquette(ostream& sortie) const {
		sortie<<nom<<" : "<<volume<<" ml, pH "<<pH;
		return sortie;
	}
	const Flacon operator+(Flacon const& f2) const
	{	
		string name_out=nom+" + "+f2.nom;
		double volume_out(volume+f2.volume);
		double pH_out( -log10( (volume*pow(10,-pH) + f2.volume*pow(10,-f2.pH))/(volume+f2.volume) ) );
		return Flacon(name_out,volume_out,pH_out);
	}
	Flacon& operator+=(Flacon const& f2)
	{	
		//double volume_out(volume+f2.volume);
		//double pH_out( -log10( (volume*pow(10,-pH) + f2.volume*pow(10,-f2.pH))/(volume+f2.volume) ) );
		//volume=volume_out;
		//pH=pH_out;
		*this=*this+f2;
		return *this;
	}

};

ostream& operator<<(ostream& out,const Flacon& f){
	f.etiquette(out);
	return out;
}

#define BONUS
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);
  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);
  return 0;

}
