#include <iostream>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/
class Tirelire{
	private:
		double montant;
	public:
		double getMontant() const;
		void afficher() const;
		void remplir(double deposit);
		void vider();
		void puiser(double withdrawal);
		void secouer() const;
		bool montant_suffisant(double withdrawal,double& balance) const;
};

double Tirelire::getMontant() const
{
	return montant;
}

void Tirelire::afficher() const
{
	if(montant>0)
	{
		cout<<"Vous avez : "<< montant<<" euros dans votre tirelire."<<endl;
	}
	else
	{
		cout<<"Vous etes sans le sou."<<endl;
	}
}

void Tirelire::secouer() const
{
	if(montant > 0)
	{
		cout<<"Bing bing"<<endl;
	}
}

void Tirelire::remplir(double deposit)
{
	if(deposit>0)
	{
		montant=montant+deposit;
	}
}

void Tirelire::vider()
{
	montant=0.0;
}

void Tirelire::puiser(double withdrawal)
{
	if(withdrawal>=montant)
	{
		vider();
	}
	else if(withdrawal>0.0)
	{
		montant=montant-withdrawal;
	}
}

bool Tirelire::montant_suffisant(double withdrawal,double& balance) const
{
	double remaining_money=montant-withdrawal;
	if(withdrawal <= 0.0)
	{
		balance=montant;
		return true;
	}
	
	if((remaining_money >= 0.0) )
	{
		balance=remaining_money;
		return true;
	}
	else
	{
		balance=remaining_money*-1.0;
		return false;
	}
}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Tirelire piggy;

  piggy.vider();
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(20.0);
  piggy.secouer();
  piggy.afficher();

  piggy.remplir(550.0);
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(10.0);
  piggy.puiser(5.0);
  piggy.afficher();

  cout << endl;

  // le budget de vos vacances de rève.
  double budget;

  cout << "Donnez le budget de vos vacances : ";
  cin >> budget;

  // ce qui resterait dans la tirelire après les
  // vacances
  double solde(0.0);

  if (piggy.montant_suffisant(budget, solde)) {
    cout << "Vous êtes assez riche pour partir en vacances !"
         << endl
         << "Il vous restera " << solde << " euros"
         << " à la rentrée." << endl << endl;
    piggy.puiser(budget);
  } else {
    cout << "Il vous manque " << solde << " euros"
         << " pour partir en vacances !" << endl << endl;
  }
  return 0;
}
