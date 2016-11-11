#include <iostream>
#include <vector>
#include <string>
using namespace std;
int total_tills=0;

class Article{
	private:
		const string nom_; // const string as string is object
		double prix_;
		bool on_sale_;
	public:
		Article (string const& nom,double prix, bool on_sale=false):
				nom_(nom),prix_(prix),on_sale_(on_sale){}
		Article (const Article& autre) :
				nom_(autre.nom_),prix_(autre.prix_),on_sale_(autre.on_sale_){}
		
		string name() const{
			return nom_;
		} 
		double price() const{
			return prix_;
		}
		bool on_sale() const {
			return on_sale_;
		}
	
};

class Achats{
	private:
		const Article article;
		const unsigned int quantity; 
	public:
		Achats(const Article& item,unsigned int quantity=1):
				article(item),quantity(quantity){
					}
				
		void afficher() const {
			cout<<article.name()<<" :"<<article.price()<<" x "<<quantity<<" Frs";
			
			if(article.on_sale())
			{
				cout<<" = "<<article.price()*quantity*0.5<<"( en action)"<<endl;
			}
			else
			{
				cout<<" = "<<article.price()*quantity*0.5<<endl;
			}
		}
		const Article& getArticle() const{
			return article;
		}
		int Quantity() const{
			return quantity;
		}
		double achat_price() const{
			double prix(quantity*article.price());
			if(article.on_sale())
				prix*=0.5;
			return prix;
		}
};
class Caddie{
	private:
		vector<Achats> achats;
	public:
		void remplir(const Article& item,unsigned int quantity=1){
				achats.push_back(Achats(item,quantity));
		}
		
		double	total()	const	{
			double	somme(0.0);
			
			for	(auto	const&	achat	:	achats)	{
				achat.afficher();
				somme	+=	achat.achat_price();
			}
		return	somme;
		}
		
};	

class Caisse{
	private:
		int till_no;
		double total_amount;
	public:
		Caisse() : total_amount(0.0){
			total_tills+=1;
			till_no=total_tills;			
		}
		~Caisse(){
			total_tills-=1;
		}
		
		void afficher(){
			cout<<"La caisse "<<till_no<<" a encaisse "<<total_amount<<" Frs audjourdhui"<<endl;
		}
		void scanner(const Caddie& caddie){
			double local_total(caddie.total());			
			total_amount+=local_total;
			cout	<<	"-----"	<<	endl;
			cout<<"Totale a payer : "<<local_total<<endl;			
		}
};


// ======================================================================
int main()
{
  // Les articles vendus dans le supermarché
  Article choufleur ("Chou-fleur extra"      ,  3.50 );
  Article roman     ("Les malheurs de Sophie", 16.50, true );
  Article camembert ("Cremeux 100%MG"        ,  5.80 );
  Article cdrom     ("C++ en trois jours"    , 48.50 );
  Article boisson   ("Petit-lait"            ,  2.50, true);
  Article petitspois("Pois surgeles"         ,  4.35 );
  Article poisson   ("Sardines"              ,  6.50 );
  Article biscuits  ("Cookies de grand-mere" ,  3.20 );
  Article poires    ("Poires Williams"       ,  4.80 );
  Article cafe      ("100% Arabica"          ,  6.90, true);
  Article pain      ("Pain d'epautre"        ,  6.90 );

  // Les caddies du supermarché, disons 3 ici
  vector<Caddie> caddies(3);

  // Les caisses du supermarché, disons 2
  vector<Caisse> caisses(2);

  // Les clients font leurs achats :
  // le second argument de la méthode remplir correspond à une quantité

  // remplissage du 1er caddie
  caddies[0].remplir(choufleur, 2);
  caddies[0].remplir(cdrom       );
  caddies[0].remplir(biscuits , 4);
  caddies[0].remplir(boisson  , 6);
  caddies[0].remplir(poisson  , 2);

  // remplissage du 2eme caddie
  caddies[1].remplir(roman        );
  caddies[1].remplir(camembert    );
  caddies[1].remplir(petitspois, 2);
  caddies[1].remplir(poires    , 2);

  // remplissage du 3eme caddie
  caddies[2].remplir(cafe     , 2);
  caddies[2].remplir(pain        );
  caddies[2].remplir(camembert, 2);

  // Les clients passent à la caisse :
  caisses[0].scanner(caddies[0]);
  cout << "=========================================" << endl;
  caisses[0].scanner(caddies[1]);
  cout << "=========================================" << endl;
  caisses[1].scanner(caddies[2]);
  cout << "=========================================" << endl;

  // Affichage du résultat des caisses
  cout << "Résultats du jour :" << endl;
  for (size_t i(0); i < caisses.size(); ++i) {
    cout << "Caisse " << i+1 << " : " ;
    caisses[i].afficher();
    cout << endl;
  }

  return 0;
}
