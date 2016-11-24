#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int distance(int x, int y)
{
  return abs(x - y);
}

class Creature
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
	protected:
		string nom_;
		int niveau_;
		int points_de_vie_;
		int force_;
		int position_;
	public:
		Creature (string nom, 
				  int niveau,
				  int points_de_vie,
				  int force,
				  int position=0):
				  nom_(nom),
				  niveau_(niveau),
				  points_de_vie_(points_de_vie),
				  force_(force),
				  position_(position){}
		bool vivant() const;
		int points_attaque() const ;
		void deplacer(int d);
		void adieux() const;
		void faiblir(int b);
		void afficher() const;
		int position() const { return position_;};

};

bool Creature::vivant() const{
	if(points_de_vie_>0)
	{
		return true;
	}
	else
	{
		
		return false;
	}
}
int Creature::points_attaque() const{
	if(vivant())
		return niveau_*force_;
	else
		return 0;
}

void Creature::deplacer(int d){
	if(vivant())
	{
	position_+=d;
	}
}
void Creature::adieux() const {
	cout<<nom_<<" n'est plus !"<<endl;
}
void Creature::faiblir(int b){
	points_de_vie_-=b;
	if(!vivant()){
		points_de_vie_=0;
		adieux();
	}
}

void Creature::afficher() const{
	cout<<nom_<< ", niveau: "<<niveau_;
	cout<< ", points de vie: "<<points_de_vie_;
    cout<< ", force: "<<force_;
    cout<< ", points d'attaque: "<<points_attaque();
    cout<< ", position: "<<position_<<endl;
}

class Dragon : public Creature{
	private:
	int portee_flamme_;
	public:
	Dragon(string nom, 
		   int niveau,
		   int points_de_vie,
		   int force,
		   int portee_flamme_,
		   int position=0):
		   Creature(nom,niveau,points_de_vie,force,position),portee_flamme_(portee_flamme_){};
		//Dragon(string nom, 
		   //int niveau,
		   //int points_de_vie,
		   //int force,
		   //int portee_flamme_
		   //):
		   //Creature(nom,niveau,points_de_vie,force),portee_flamme_(portee_flamme_){};	   
		   void voler(int d) ;
		   void souffle_sur(Creature& bete);
};
void Dragon::souffle_sur(Creature& bete)
{
	// not sure if I can use position here;
	int d=distance(position(),bete.position());
	if(vivant() && bete.vivant() && d<portee_flamme_){
		bete.faiblir(points_attaque());
		faiblir(d);
		if(vivant() && !bete.vivant())
		{
			niveau_++;
		}
	}
}

void Dragon::voler(int d){
	position_=d;
}

class Hydre: public Creature{
	private:
		int longueur_cou_;
		int dose_poison_;	
	public:
		Hydre(string nom, 
		   int niveau,
		   int points_de_vie,
		   int force,
		   int longueur_cou_,
		   int dose_poison_,
		   int position=0):
		   Creature(nom,niveau,points_de_vie,force,position),longueur_cou_(longueur_cou_),dose_poison_(dose_poison_){};
		void empoisonne(Creature& bete);
};

void Hydre::empoisonne(Creature& bete)
{
	int d=distance(position(),bete.position());
	if(vivant() && bete.vivant() && d<longueur_cou_){
		bete.faiblir(points_attaque()+dose_poison_);
		if(vivant() && !bete.vivant())
		{
			niveau_++;
		}
	}
}
void combat(Dragon& dragon,Hydre& hydre)
{
	hydre.empoisonne(dragon);
	dragon.souffle_sur(hydre);
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  Dragon dragon("Dragon rouge"   , 2, 10, 3, 20         );
  Hydre  hydre ("Hydre maléfique", 2, 10, 1, 10, 1,  42 );
 Creature a("Charybde",5, 85, 4, 169);
	a.afficher();
	a.faiblir(10);
	a.afficher();
	a.faiblir(17);
	a.afficher();
	a.faiblir(11);a.afficher();
	a.faiblir(17);a.afficher();
	a.afficher();
	a.faiblir(18);a.afficher();
	a.faiblir(17);a.afficher();
	a.deplacer(-1);a.afficher();
	
	
	
	
	
	
  dragon.afficher();
  cout << "se prépare au combat avec :" << endl;
  hydre.afficher();

  cout << endl;
  cout << "1er combat :" << endl;
  cout << "    les créatures ne sont pas à portée, donc ne peuvent pas s'attaquer."
       << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon vole à proximité de l'hydre :" << endl;
  dragon.voler(hydre.position() - 1);
  dragon.afficher();

  cout << endl;
  cout << "L'hydre recule d'un pas :" << endl;
  hydre.deplacer(1);
  hydre.afficher();

  cout << endl;
  cout << "2e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 2 points de vie supplémentaires\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 41 = 2 ].\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon avance d'un pas :" << endl;
  dragon.deplacer(1);
  dragon.afficher();

  cout << endl;
  cout << "3e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 1 point de vie supplémentaire\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 42 = 1 ] ;\n\
  + l'hydre est vaincue et le dragon monte au niveau 3.\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "4e Combat :" << endl;
  cout << "    quand une créature est vaincue, rien ne se passe." << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  return 0;
}
