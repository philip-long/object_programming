#include <iostream>
#include <vector>
using namespace std;
//----------------------------------------------------------------------
class Figure {
public:
	virtual void affiche() const = 0;
	virtual Figure* copie() const = 0;
	virtual ~Figure() { cout << "Une figure de moins." << endl; }
};
//----------------------------------------------------------------------
class Cercle : public Figure {public:
		Cercle(double x = 0.0) : rayon(x) {
		cout << "Construction d'un cercle de rayon " << rayon << endl;
		}
		Cercle(const Cercle& autre) : Figure(autre), rayon(autre.rayon) {
		cout << "Copie d'un cercle de rayon " << rayon << endl;
		}
		~Cercle() { cout << "Destruction d'un cercle" << endl; }
		Figure* copie() const { return new Cercle(*this); }
		void affiche() const {
		cout << "Un cercle de rayon " << rayon << endl;
		}
	private:
		double rayon;
};
//----------------------------------------------------------------------

class Carre : public Figure {
	public:
		Carre(double a = 0.0) : cote(a) {
		cout << "Construction d'un carré de coté " << cote << endl;
		}
		Carre(const Carre& autre) : Figure(autre), cote(autre.cote) {
		cout << "Copie d'un carré de coté " << cote << endl;
		}
		~Carre() { cout << "Destruction d'un carré" << endl; }
		Figure* copie() const { return new Carre(*this); }
		void affiche() const {
		cout << "Un carré de coté " << cote << endl;
		}
	private:
		double cote;
};
//----------------------------------------------------------------------
class Triangle : public Figure {
	public:
		Triangle(double b = 0.0, double h = 0.0) : base(b), hauteur(h) {
		cout << "Construction d'un triangle " << base << "x" << hauteur << endl;
		}
		Triangle(const Triangle& autre)
		: Figure(autre), base(autre.base), hauteur(autre.hauteur)
		{
		cout << "Copie d'un triangle " << base << "x" << hauteur << endl;
		}
		~Triangle() { cout << "Destruction d'un triangle" << endl; }
		Figure* copie() const { return new Triangle(*this); }
		void affiche() const {cout << "Un triangle " << base << "x" << hauteur << endl;
		}
	private:
		double base; double hauteur;
};
//----------------------------------------------------------------------
class Dessin {
public:
	~Dessin() {
	cout << "Le dessins s'efface..." << endl;
	for (unsigned int i(0); i < contenu.size(); ++i) delete contenu[i];
}
void ajouteFigure(const Figure& fig) {
	contenu.push_back(fig.copie());
}
void affiche() const {
	cout << "Je contiens :" << endl;
	for (unsigned int i(0); i < contenu.size(); ++i) {
	contenu[i]->affiche();
	}
}
private:
	vector<Figure*> contenu;
};

void unCercleDePlus(const Dessin& img) {
	Dessin tmp(img);
	tmp.ajouteFigure(Cercle(1));
	cout << "Affichage de 'tmp': " << endl;
	tmp.affiche();
}
int main()
{
	Dessin dessin;
	dessin.ajouteFigure(Triangle(3,4));
	dessin.ajouteFigure(Carre(2));
	dessin.ajouteFigure(Triangle(6,1));
	dessin.ajouteFigure(Cercle(12));
	unCercleDePlus(dessin); // impossible
	cout << endl << "Affichage du dessin : " << endl;
	dessin.affiche();
	return 0;
}
