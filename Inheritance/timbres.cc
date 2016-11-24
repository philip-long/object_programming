#include <iostream>
#include <string>
using namespace std;

class Timbre
{
private:
  static constexpr unsigned int ANNEE_COURANTE = 2016;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
	
protected:
	string nom;
	unsigned int annee;
	string pays;
	double valeur_faciale;

public:	
	Timbre(string nom, unsigned int annee,string pays="Suisse", double valeur_faciale=1.0)
		:nom(nom),annee(annee),pays(pays),valeur_faciale(valeur_faciale) {}
	unsigned int age() const 
	{
		return ANNEE_COURANTE-annee;
		};
	double vente() const 
	{
		if(age()<5){
			return valeur_faciale;
		}			
		else{
			return valeur_faciale*age()*2.5;
		}
		
	};
	void display(ostream& sortie) const{
				sortie<<"Timbre ";
				afficher(sortie);
	}
	void afficher(ostream& sortie) const{
		sortie<<"de nom "<<nom<<" datant de "<<annee<<" (provenance "<<pays<<") ";
				sortie<<"ayant pour valeur faciale "<<valeur_faciale<<" francs";
	}
};


class Rare : public Timbre{
	private:
		static constexpr double PRIX_BASE_TRES_RARE=600;
		static constexpr double PRIX_BASE_RARE=400;
		static constexpr double PRIX_BASE_PEU_RARE=50;
		int exemplaire;
	public:
	Rare(string nom, unsigned int annee,string pays, double valeur_faciale,int number_of_copies)
		: Timbre(nom,annee,pays,valeur_faciale),exemplaire(number_of_copies){}
		Rare(string nom, unsigned int annee,int number_of_copies)
		: Timbre(nom,annee),exemplaire(number_of_copies){}
	//Rare(const Rare& other);	
	void display(ostream& sortie) const{
				sortie<<"Timbre rare ("<<exemplaire<< " ex.) ";
				afficher(sortie);
	}
	int nb_exemplaires() const {return exemplaire;}
	double vente() const 
	{
		if(exemplaire<100){
			return PRIX_BASE_TRES_RARE*age()/10.0;
		}
		else if	(exemplaire<1000){
			return PRIX_BASE_RARE*age()/10.0;
		}		
		else{
			return PRIX_BASE_PEU_RARE*age()/10.0;
		}
		
	};
	
};

class Commemoratif : public Timbre{
	private:
	public:
	Commemoratif(string nom, unsigned int annee,string pays="Suisse", double valeur_faciale=1.0)
		: Timbre(nom,annee,pays,valeur_faciale){};
	
	void display(ostream& sortie) const {
				sortie<<"Timbre commémoratif ";
				afficher(sortie);
	}
	double vente() const 
	{
		return 2*Timbre::vente();
	};			
	
};

ostream& operator <<(ostream& sortie,const Commemoratif& t){ 
	t.display(sortie); 
	return sortie;
}
ostream& operator <<(ostream& sortie,const Timbre& t){ 
	t.display(sortie); 
	return sortie;
}
ostream& operator <<(ostream& sortie,const Rare& t){ 
	t.display(sortie); 
	return sortie;
}


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Rare t1( "Guarana-4574", 1960, "Mexique", 0.2, 98 );
  Rare t2( "Yoddle-201"  , 1916, "Suisse" , 0.8,  3 );

  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Commemoratif t3( "700eme-501"  , 2002, "Suisse", 1.5 );
  Timbre       t4( "Setchuan-302", 2004, "Chine" , 0.2 );

  /* Nous n'avons pas encore le polymorphisme :-(
   * (=> pas moyen de faire sans copie ici :-( )  */
  cout << t1 << endl;
  cout << "Prix vente : " << t1.vente() << " francs" << endl;
  cout << t2 << endl;
  cout << "Prix vente : " << t2.vente() << " francs" << endl;
  cout << t3 << endl;
  cout << "Prix vente : " << t3.vente() << " francs" << endl;
  cout << t4 << endl;
  cout << "Prix vente : " << t4.vente() << " francs" << endl;

  return 0;
}
