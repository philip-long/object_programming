#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
class Auteur{
	private:
		string nom;
		bool prix;
	public:
		Auteur(string nom,bool prix=false) : nom(nom),prix(prix){}
		string getNom() const{
			return nom;
		}
		bool getPrix() const{
			return prix;
		}
};
class Oeuvre{
	private:
		string title;
		const Auteur& auteur;
		string language;
	public:
		// passing author as a constant ref
		Oeuvre(string title,const Auteur& other_auteur,string language) 
			:title(title),auteur(other_auteur),language(language)
			{
			}
			
		Oeuvre(Oeuvre const&)=delete;	// Means object cannot be copied
		
		~Oeuvre(){
			cout<<"L'oeuvre \""<<title<<", "<<auteur.getNom()<<", en "<<language<<"\" n'est plus disponible."<<endl;
		}
		
		string getTitre() const{
			return title;
		}
		string getLangue() const{
			return language;
		}
		// returning a constant reference
		const Auteur& getAuteur() const{
			return auteur;
		}
		void affiche() const{
			cout<<title<<", "<<auteur.getNom()<<", en "<<language<<endl;
		}
};
class Exemplaire{
	private:
		Oeuvre& book_; // Points to value of input book
	public:
		// Passing book as ref in constructor
		Exemplaire(Oeuvre& other_book): book_(other_book)
		{
			cout<<"Nouvel exemplaire de : "<<book_.getTitre()<<", "<<book_.getAuteur().getNom()<<", en "<<book_.getLangue()<<endl;
		}
		Exemplaire(Exemplaire const& other_copy) : book_(other_copy.book_)		
		{
			cout<<"Copie d'un exemplaire de : "<<book_.getTitre()<<", "<<book_.getAuteur().getNom()<<", en "<<book_.getLangue()<<endl;
		}
		~Exemplaire(){
			cout<<"Un exemplaire de \""<<book_.getTitre()<<", "<<book_.getAuteur().getNom()<<", en "<<book_.getLangue()<<"\" a été jeté !"<<endl;
		}
		// returning a const reference
		const Oeuvre& getOeuvre() const{
			return book_;
		}
		void affiche(){
			cout<<"Exemplaire de :"<<book_.getTitre()<<", "<<book_.getAuteur().getNom()<<", en "<<book_.getLangue();
		}
};

class Bibliotheque{
	private:
		// A vector of pointers to the exemplaires
		// Each element is itself a pointer to a work
		vector<Exemplaire*> copys;
		string name;
	public:
		Bibliotheque(string name):name(name)
		{
			cout<<"La bibliothèque "<<name<<" est ouverte !"<<endl;
		}
		~Bibliotheque(){
			cout<<"La bibliothèque "<<name<<" ferme ses portes,"<<endl<<"et détruit ses exemplaires :"<<endl;
			for(auto& i:copys){
				delete i; // delete all copies
			}
		}
		
		string getNom() const{
			return name;
		}
		// passing in a reference to a work
		void stocker(Oeuvre& o,int number=1)
		{			
			
			for(int i=0;i<number;i++){			
				//cout<<" Pushing backing the exemplaire"<<endl;
				copys.push_back(new Exemplaire(o)); // passing in a new class but not creating a copy!!								
			}
		}
		void lister_exemplaires(string langue="")
		{
			for(auto i:copys)
			{
				if(langue.empty() || i->getOeuvre().getLangue()==langue ) 
				{
					i->affiche();
					cout<<endl;
				}		
			}
		}
		int compter_exemplaires(const Oeuvre& o)
		{
			int number_of_copies=0;
			for(auto i:copys)
			{
				if(i->getOeuvre().getTitre()==o.getTitre())
				{
					number_of_copies++;
				}
			}
			return number_of_copies;
		}
		void afficher_auteurs(bool with_prize=false)
		{
			for(auto i:copys)
			{
				if(with_prize)
				{	
					if(i->getOeuvre().getAuteur().getPrix() )
					{
						cout<<i->getOeuvre().getAuteur().getNom()<<endl;
					}
				}
				else
				{
					cout<<i->getOeuvre().getAuteur().getNom()<<endl;
				}
			}
		}
};

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
