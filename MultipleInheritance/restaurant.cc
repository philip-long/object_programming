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
		Produit(string name,string unit="") : name_(name),units_(unit) {}
		string getNom() const;
		string getUnite() const;
		virtual string toString() const;
		virtual const Produit* adapter(double n) const;
		virtual double quantiteTotale(const string& nomProduit) const;
		virtual void test_function() const {cout<<"**Product**"<<endl;} 
};

string Produit::getNom() const{
	return name_;
}
string Produit::getUnite() const{
	return units_;
}
string Produit::toString() const{
	//return units_+" "+"de"+" "+name_;
	return name_;
}

const Produit* Produit::adapter(double n) const{	
	// Since this does not change return directly
	return this;
}
double Produit::quantiteTotale(const string& nomProduit) const{
	if(nomProduit==name_)
	{
		return 1.0;
	}
	else
	{
		return 0.0;
	}
}

//======================================================================
class Ingredient{
		private:
			const Produit& product;
			double quantity;
		public:
		Ingredient(const Produit& p, double quantity)
			: product(p),quantity(quantity) 
			{
			}
			const Produit& getProduit() const;
			double getQuantite() const ;
			string descriptionAdaptee() const;
			double quantiteTotale(const string& nomProduit);
		
};
const Produit& Ingredient::getProduit() const
{
	return product;
}
double Ingredient::getQuantite() const{
	return quantity;
}

string Ingredient::descriptionAdaptee() const{
	stringstream strs;
	cout.precision(6);
	strs << fixed << quantity;
	std::string str = strs.str();
	const Produit* p=product.adapter(quantity);
	return str+" "+ p->getUnite()+ " de " + p->toString();
	
}

double Ingredient::quantiteTotale(const string& nomProduit){
	return getQuantite()*product.quantiteTotale(nomProduit);
}

//======================================================================
class Recette{
	private :
		vector<Ingredient* > container;
		string name_;
		double nbFois_;
	public:
		Recette(string name,double number_of_times=1)		
			: name_(name),nbFois_(number_of_times)
			 {
				 //cout<<"Creating Recipe "<<name_<<" numbers "<<nbFois_<<endl;
				 }
		void ajouter(const Produit& p,double quantite) ;
		const Recette adapter(double n) const;
		string toString() const ;
		double quantiteTotale(const string& nomProduit) const;

};

void Recette::ajouter(const Produit& p,double quantite) 
{
	//container.push_back(new Ingredient(p,quantite*nbFois_));
	container.push_back(new Ingredient(p,quantite));
	//container.push_back(new Ingredient(p,quantite*nbFois_));
}

const Recette Recette::adapter(double n) const{
	// Create a copy
	
	Recette R(name_,nbFois_*n);
	for(auto i:container)
	{
		// copy ingredients *nbFois_
		R.ajouter(i->getProduit(),i->getQuantite()*nbFois_*n);
		//R.ajouter(i->getProduit(),i->getQuantite());
	}
	return R;
}

string Recette::toString() const {
		
	string returnString;
	ostringstream stringnbFois_;
	stringnbFois_ << nbFois_;
	string strnbFois = stringnbFois_.str();
	
	returnString="Recette \""+name_+"\" x "+strnbFois+":";
	int Counter=1;
	
	for(auto i: container)
	{
		
		ostringstream stringCounter;
		stringCounter << Counter;
		string str = stringCounter.str();
		returnString+="\n";
		returnString+=" "+str +". ";
		returnString+=i->descriptionAdaptee();
		Counter++;
	}
	return returnString;
}

// A recurisve function
double Recette::quantiteTotale(const string& nomProduit) const{
	double quantity_of_product=0.0;
	
	for(auto i:container)
	{
		if(i->getProduit().quantiteTotale(nomProduit)==1)
		{
			double q=i->getQuantite();
			quantity_of_product+=q;
		}
		else
		{
			
			double q=i->getQuantite()*i->getProduit().quantiteTotale(nomProduit);	
			quantity_of_product+=q;
			
		}

	}
	return quantity_of_product*nbFois_;
}
//======================================================================
class ProduitCuisine : public Produit {
	private :
		Recette recipe;
	public:
		ProduitCuisine(string name,string units_="portion(s)") :
			Produit(name,units_),recipe(name) { 
				}
			
		void ajouterARecette(const Produit& produit,double quantite) ;
		
		const ProduitCuisine* adapter(double n) const;
		
		virtual string toString() const;
		virtual double quantiteTotale(const string& nomProduit) const;
		virtual void test_function() const {cout<<"**Cooked Product**"<<endl;}
};

void ProduitCuisine::ajouterARecette(const Produit& produit,double quantite){	
	recipe.ajouter(produit,quantite);
}
const ProduitCuisine* ProduitCuisine::adapter(double n) const{
	// So I must find a way to change the recipe while not changing this product
	// this line is confusing only way I could make it work
	ProduitCuisine *p = new ProduitCuisine(name_);
	p->recipe=recipe.adapter(n);
	
	return p;
}
string ProduitCuisine::toString() const{
	return Produit::toString()+"\n"+recipe.toString();
}

double ProduitCuisine::quantiteTotale(const string& nomProduit) const{
	if(nomProduit==name_)
	{
		return 1.0;
	}
	else
	{		
		return recipe.quantiteTotale(nomProduit);
	}
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
