#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*****************************************************
  * Compléter le code à partir d'ici
 *****************************************************/
class Produit{
	protected:
		string name_;
		string units_;
	public:
		Produit(string name,sting unit="") : name_(name),unit_(unit) {}
		string getNom() const;
		string getUnite() const;
		string toString() const;
};

string Produit::getNom() const{
	return name_;
}
string Produit::getUnite() const{
	return units_;
}
string Produit::toString() const{
	return units_+" "<<de<<" "<<name;
}
//======================================================================
class Ingredient{
		private:
			const Produit product;
			double quantity;
		public:
		Ingredient(const Produit& p, double quantity)
			: product(p),quantity(quantity) {}
			const Produit& getProduit() const;
			double getQuantite() const ;
			void descriptionAdaptee() const;
		
};
const Produit& Ingredient::getProduit() const
{
	return product;
}
double Ingredient::getQuantite() const {
	return quantity;
}

void Ingredient::descriptionAdaptee() {
	cout<<quantity<" "<<product.toString();
	
}

//======================================================================
class Recette{
	private :
		vector<Ingredient* > container;
		string name_;
		unsigned int nbFois_;
	public:
		Recette(string name,unsigned int number_of_times=1)		
			: name_(name),nbFois_(number_of_times) {}
		void ajouter(const Produit& p,double quantite);
		Recette adapter(double n);
		void toString() const ;

};

void Recette::adjouter(const Produit& p,double quantite)
{
	container.push_back(new Ingredient(p,quantite*nbFois_));
}

Recette Recette::adapter(double n){
	// Create a copy
	Recette R(name_,nbFois_*n)
	for(auto i:container)
	{
		// copy ingredients
		R.adjouter(i,i.getQuantite*n);
	}
	return Recette;
}

void toString() const {
	cout<<"Recette \""<<name<<"\" x "<<nbFois_;
	for(auto i: container)
	{
		cout<<endl;
		cout<<"1."<<i.descriptionAdaptee()
	}
}

//======================================================================
class ProduitCuisine : public Produit {
	private :
		Recette recipe;
	public:
		ProduitCuisine(string name,string units_="portion(s)") :
			Produit(name,units_),recipe(name) {}
			
		void ajouterARecette(const Produit& produit,double quantite);
		
		const ProduitCuisine* adapter(double n);
		
		toString() const;
		
};

void ajouterARecette(const Produit& produit,double quantite){
	recipe.adjouter(const Produit& produit,double quantite)
}
const ProduitCuisine* adapter(double n){
	r.adapter(double n);
}

//======================================================================

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
void afficherQuantiteTotale(const Recette& recette, const Produit& produit)
{
  string nom = produit.getNom();
  cout << "Cette recette contient " << recette.quantiteTotale(nom)
       << " " << produit.getUnite() << " de " << nom << endl;
}

int main()
{
  // quelques produits de base
  Produit oeufs("oeufs");
  Produit farine("farine", "grammes");
  Produit beurre("beurre", "grammes");
  Produit sucreGlace("sucre glace", "grammes");
  Produit chocolatNoir("chocolat noir", "grammes");
  Produit amandesMoulues("amandes moulues", "grammes");
  Produit extraitAmandes("extrait d'amandes", "gouttes");

  ProduitCuisine glacage("glaçage au chocolat");
  // recette pour une portion de glaçage:
  glacage.ajouterARecette(chocolatNoir, 200);
  glacage.ajouterARecette(beurre, 25);
  glacage.ajouterARecette(sucreGlace, 100);
  cout << glacage.toString() << endl;

  ProduitCuisine glacageParfume("glaçage au chocolat parfumé");
  // besoin de 1 portions de glaçage au chocolat et de 2 gouttes
  // d'extrait d'amandes pour 1 portion de glaçage parfumé

  glacageParfume.ajouterARecette(extraitAmandes, 2);
  glacageParfume.ajouterARecette(glacage, 1);
  cout << glacageParfume.toString() << endl;

  Recette recette("tourte glacée au chocolat");
  recette.ajouter(oeufs, 5);
  recette.ajouter(farine, 150);
  recette.ajouter(beurre, 100);
  recette.ajouter(amandesMoulues, 50);
  recette.ajouter(glacageParfume, 2);

  cout << "===  Recette finale  =====" << endl;
  cout << recette.toString() << endl;
  afficherQuantiteTotale(recette, beurre);
  cout << endl;

  // double recette
  Recette doubleRecette = recette.adapter(2);
  cout << "===  Recette finale x 2 ===" << endl;
  cout << doubleRecette.toString() << endl;

  afficherQuantiteTotale(doubleRecette, beurre);
  afficherQuantiteTotale(doubleRecette, oeufs);
  afficherQuantiteTotale(doubleRecette, extraitAmandes);
  afficherQuantiteTotale(doubleRecette, glacage);
  cout << endl;

  cout << "===========================\n" << endl;
  cout << "Vérification que le glaçage n'a pas été modifié :\n";
  cout << glacage.toString() << endl;

  return 0;
}
