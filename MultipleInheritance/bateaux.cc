#include <iostream>
#include <cmath>
using namespace std;

enum Pavillon { JollyRogers, CompagnieDuSenegal, CompagnieDOstende };

enum Etat { Intact, Endommage, Coule };

int sq(int x)
{
  return x*x;
}

class Coordonnees
{
public:
  Coordonnees(int un_x, int un_y) : x_(un_x), y_(un_y) {}
  int x() const {
    return x_;
  }
  int y() const {
    return y_;
  }
  void operator+=(Coordonnees const& autre); // à définir plus bas
private:
  int x_;
  int y_;
};

class Navire
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
	protected:
		Coordonnees position_;
		const Pavillon pavillon_;
		Etat etat_;
		static constexpr int rayon_rencontre=10;
	public:
		Navire(int x,int y,Pavillon p, Etat etat=Intact) :
			position_(x,y),pavillon_(p),etat_(etat) {}
		Coordonnees position() const;
		void avancer(int de_x,int de_y);
		void renflouer();
		virtual ostream& afficher(ostream& out) const;
		virtual void attaque(Navire& autre)=0;
		virtual void replique(Navire& autre)=0;
		virtual void est_touche()=0;
		virtual void rencontrer(Navire& autre) ;
		~Navire() {}
};
double distance(Coordonnees const& c1,Coordonnees const& c2);
ostream& operator<<(ostream& out,const Coordonnees& c1);
double distance(Navire const& v1,Navire const& v2);
ostream& operator<<(ostream& out,Pavillon p);
ostream& operator<<(ostream& out,Etat p);


Coordonnees Navire::position() const{
	return position_;
}

void Coordonnees::operator+=(Coordonnees const& autre)
{
  // à définir ici
  x_+=autre.x_;
  y_+=autre.y_;

}
void Navire::avancer(int de_x,int de_y) {
	Coordonnees c(de_x,de_y);
	position_+=c;
}
void Navire::renflouer(){
	etat_=Intact;
}

ostream& Navire::afficher(ostream& out) const{
	out<<" en "<<position_<<" battant pavillon "<<pavillon_<<", "<<etat_;
	return out;
}

void Navire::rencontrer(Navire& autre)
{
	if(etat_!=Coule && autre.etat_!=Coule)
	{
	if(distance(*this, autre)<Navire::rayon_rencontre)
	{
		attaque(autre);
		autre.replique(*this);
	}
	} 
}
class Pirate : public virtual Navire{
	private:
	public :			
		Pirate(int x,int y,Pavillon p) :
			Navire(x,y,p) {}
		virtual void attaque(Navire& autre) override
		{
			if(etat_!=Coule)
			{
				cout<<"A l'abordage !"<<endl;
				autre.est_touche();
			}
		}
		virtual void replique(Navire& autre) override
		{
			if(etat_!=Coule)
			{			
				cout<<"Non mais, ils nous attaquent ! On riposte !!"<<endl;
				attaque(autre);
			}			
		}
		virtual void est_touche() override
		{
			if(etat_==Intact){
				etat_=Endommage;
				}
			else if(etat_==Endommage){
				etat_=Coule;
			}
		}

		ostream& afficher(ostream& out) const override{
			cout<<"bateau pirate";
			Navire::afficher(out);
			return out;
		}

};
class Marchand : public virtual Navire{
	public:
		Marchand(int x,int y,Pavillon p, Etat etat=Intact) :
			Navire(x,y,p,etat) {}
		~Marchand(){}
		virtual void attaque(Navire& autre) override
		{
			if(etat_!=Coule)
			{
				cout<<"On vous aura ! (insultes)"<<endl;
			}
		}
		virtual void replique(Navire& autre) override
		{
			if(etat_!=Coule)
			{
				cout<<"Même pas peur !"<<endl;
			}
			else
			{
				cout<<"SOS je coule !"<<endl;
			}			
		}
		virtual void est_touche() override
		{
			etat_=Coule;			
		}
		ostream& afficher(ostream& out) const override{
			out<<"navire marchand";
			Navire::afficher(out);
			return out;
		}
};
class Felon : public Pirate , public Marchand{
	public:
		Felon(int x,int y,Pavillon p) :
				Navire(x,y,p),Pirate(x,y,p),Marchand(x,y,p) {}
	
		virtual void attaque(Navire& autre)
		{
			Pirate::attaque(autre);
		}
		virtual void est_touche()
		{
			Pirate::est_touche();
		}
		virtual void replique(Navire& autre)
		{
			Marchand::replique(autre);
		}
		ostream& afficher(ostream& out) const override{
			out<<"navire félon";
			Navire::afficher(out);
			return out;			
		}
	
};



double distance(Coordonnees const& c1,Coordonnees const& c2)
{
	return sqrt ( ( c1.x()-c2.x() )*( c1.x()-c2.x() ) + ( c1.y()-c2.y() )*( c1.y()-c2.y() ) );
}
double distance(Navire const& v1,Navire const& v2)
{
	Coordonnees c1=v1.position();
	Coordonnees c2=v2.position();
	return distance(c1,c2);
}
ostream& operator<<(ostream& out,const Coordonnees& c1){
	out<<"("<<c1.x()<<", "<<c1.y()<<")";
	return out;
} 
ostream& operator<<(ostream& out,const Navire& n){
	n.afficher(out);
	return out;
} 
ostream& operator<<(ostream& out,Pavillon p){
	
	if(p==JollyRogers)
	{
	out<<"pirate";
	}
	else if(p==CompagnieDuSenegal)
	{
		out<<"français";
	}
	else if(p==CompagnieDOstende)
	{
		out<<"autrichien";
	}
	else{
		out<<"pavillon inconnu";
	}
	return out;
} 
ostream& operator<<(ostream& out,Etat p){
	if(p==Intact)
	{
	out<<"intact";
	}
	else if(p==Endommage)
	{
		out<<"ayant subi des dommages";
	}
	else if(p==Coule)
	{
		out<<"coulé";
	}
	else{
		out<<"état inconnu";
	}
	return out;
}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void rencontre(Navire& ship1, Navire& ship2)
{
  cout << "Avant la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
  cout << "Distance : " << distance(ship1, ship2) << endl;
  ship1.rencontrer(ship2);
  cout << "Apres la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
}

int main()
{
  // Test de la partie 1
  cout << "===== Test de la partie 1 =====" << endl << endl;

  // Un bateau pirate 0,0
  Pirate ship1(0, 0, JollyRogers);
  cout << ship1 << endl;

  // Un bateau marchand en 25,0
  Marchand ship2(25, 0, CompagnieDuSenegal);
  cout << ship2 << endl;

  cout << "Distance : " << distance(ship1, ship2) << endl;

  cout << "Quelques déplacements..." << endl;
  cout << "  en haut à droite :" << endl;
  // Se déplace de 75 unités à droite et 10 en haut
  ship1.avancer(75, 10);
  cout << ship1 << endl;

  cout << "  vers le bas :" << endl;
  ship1.avancer(0, -5);
  cout << ship1 << endl;

  cout << endl << "===== Test de la partie 2 =====" << endl << endl;

  cout << "Bateau pirate et marchand ennemis (trop loins) :" << endl;
  rencontre(ship1, ship2);

  cout << endl << "Bateau pirate et marchand ennemis (proches) :" << endl;
  ship1.avancer(-40, -2);
  ship2.avancer(10, 2);
  rencontre(ship1, ship2);

  cout << endl << "Deux bateaux pirates ennemis intacts (proches) :" << endl;
  Pirate ship3(33, 8, CompagnieDOstende);
  rencontre(ship1, ship3);

  cout << endl << "Bateaux pirates avec dommages, ennemis :" << endl;
  rencontre(ship1, ship3);

  cout << endl << "Bateaux marchands ennemis :" << endl;
  Marchand ship4(21, 7, CompagnieDuSenegal);
  Marchand ship5(27, 2, CompagnieDOstende);
  rencontre(ship4, ship5);

  cout << endl << "Pirate vs Felon :" << endl;
  ship3.renflouer();
  Felon ship6(32, 10, CompagnieDuSenegal);
  rencontre(ship3, ship6);

  cout << endl << "Felon vs Pirate :" << endl;
  rencontre(ship6, ship3);

  return 0;
}
