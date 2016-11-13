#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
	Brique(Forme form,Couleur colour): forme(form),couleur(colour){}
	Brique()=delete;
	ostream& afficher(ostream& sortie) const ;
};
ostream& Brique::afficher(ostream& sortie) const {
	if(!couleur.empty()){
		sortie<<"("<<forme<<", "<<couleur<<")";
	}
	else
	{
		sortie<<forme;
	}
	return sortie;
}
ostream& operator<<(ostream& out,const Brique& B){
	B.afficher(out);
	return out;
}
class Construction
{
  friend class Grader;
  vector<vector<vector<Brique>>> contenu;
  public :
  Construction (const Brique& brick) :contenu(1,vector<vector<Brique>>(1,vector<Brique>(1,brick)))
  {}
  ostream& afficher(ostream& sortie) const ;
  Construction& operator^=(Construction other_construction);  
  Construction& operator-=(Construction const& other_construction);  
  Construction& operator+=(Construction const& other_construction);  
};
Construction& Construction::operator -=(Construction const& other_construction){
	if(contenu.size()>other_construction.contenu.size()){
	}
	else if(contenu.size()<=other_construction.contenu.size()){
		for(unsigned int i=0;i<contenu.size();i++){
			for(auto j:other_construction.contenu[i])
			contenu[i].push_back(j);
		}
	}
	return *this;
}
// External Counterpart
const Construction operator-(Construction c1,Construction const& c2)
{
	c1-=c2;
	return c1;
} 

Construction& Construction::operator +=(Construction const& other_construction){
	
	if(contenu.size()>other_construction.contenu.size()){
		return *this;
	}
	for(unsigned int i=0;i<contenu.size();i++){
		if(contenu[i].size() > other_construction.contenu[i].size())
		{
		return *this;
	}
	}

	for(unsigned int i=0;i<contenu.size();i++)
	{
		for(unsigned int j=0;j<contenu[i].size();j++)
		{
			for(auto k:other_construction.contenu[i][j])
			{
				contenu[i][j].push_back(k);
			}
		}
	}
	return *this;
}
// External Counterpart
const Construction operator+(Construction c1,Construction const& c2)
{
	c1+=c2;
	return c1;
} 


Construction& Construction::operator ^=(Construction other_construction){
	for(auto i:other_construction.contenu){
		contenu.push_back(i);
	}
	return *this;
}
// External Counterpart
const Construction operator^(Construction c1,Construction const& c2)
{
	c1^=c2;
	return c1;
} 

ostream& Construction::afficher(ostream& sortie) const {
	for(int i=contenu.size()-1;i>-1;i--)
	{
		sortie<<"Couche "<<i<<" :"<<endl;
		for(auto j:contenu[i])
		{
			for(auto k:j){
				sortie<<k<<" ";
			}
			sortie<<endl;
		}
		
	}
	return sortie;
}

ostream& operator<<(ostream& out,const Construction& B){
	B.afficher(out);
	return out;
}




const Construction operator*(unsigned int n, Construction const& a)
{
	Construction b(a);
	
	for(unsigned int i=0;i<n;i++)
	{
		b+=a;
	}
	return b;
}

const Construction operator/(unsigned int n, Construction const& a)
{
	Construction b(a);
	
	for(unsigned int i=0;i<n;i++)
	{
		b^=a;
	}
	return b;
}

const Construction operator%(unsigned int n, Construction const& a)
{
		Construction b(a);
	
	for(unsigned int i=0;i<n;i++)
	{
		b-=a;
	}
	return b;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");


//  unsigned int largeur(4);
//  unsigned int profondeur(3);
//  unsigned int hauteur(3); // sans le toit
	
  // on construit les murs
  
  Construction maison(toitD);
  Construction a(toitM);
  Construction b(toitM);
  Construction c(mur);
  Construction d(mur);

  

  //// on construit le toit
  //Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  //toit ^= profondeur % (vide + toitG + toitD);
  
  Construction e=a^a^a^a;
  cout<<"e ="<<endl;
  cout<<e<<endl;
  Construction f=4/a;
  cout<<"f ="<<endl;
  cout<<f<<endl;
  return 0;
}
