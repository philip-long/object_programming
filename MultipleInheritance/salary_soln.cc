
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* **********************************************************************
* La classe Employe
*/
class Employe {
	public:
		Employe(string prenom, string nom, unsigned int age, string date)
		: nom(nom), prenom(prenom), age(age), date(date) {}
		virtual ~Employe() {}
		virtual double calculer_salaire() const = 0;
		virtual string get_nom() const;
	protected:
		string nom;
		string prenom;
		unsigned int age;
		string date;
};
string Employe::get_nom() const { return "L'employé " + prenom + ' ' + nom; }
/* **********************************************************************
* La classe Commercial (factorise Vendeur et Représentant)
*/
class Commercial: public Employe {
	public:
		Commercial(string prenom, string nom, unsigned int age, string date,
		double chiffre_affaire)
		: Employe(prenom, nom, age, date), chiffre_affaire(chiffre_affaire)
		{}
		~Commercial() {}
	protected:
		double chiffre_affaire;
};
/* **********************************************************************
* La classe Vendeur
*/
class Vendeur: public Commercial {
	public:
		Vendeur(string prenom, string nom, unsigned int age, string date,
		double chiffre_affaire)
		: Commercial(prenom, nom, age, date, chiffre_affaire)
		{}
		~Vendeur() {}
		double calculer_salaire() const;
		string get_nom() const;
		};
		double Vendeur::calculer_salaire() const {
		return (0.2 * chiffre_affaire) + 400;
}
string Vendeur::get_nom() const { return "Le vendeur " + prenom + ' ' + nom; }
/* **********************************************************************
* La classe Représentant
*/
class Representant: public Commercial {
public:
	Representant(string prenom, string nom, unsigned int age, string date,
	double chiffre_affaire)
	: Commercial(prenom, nom, age, date, chiffre_affaire)
	{}~Representant() {}
	double calculer_salaire() const;
	string get_nom() const;
};
double Representant::calculer_salaire() const {
	return (0.2 * chiffre_affaire) + 800;
}
string Representant::get_nom() const { return "Le représentant " + prenom + ' ' + nom; }

/* **********************************************************************
* La classe Technicien (Production)
*/
class Technicien: public Employe {
	public:
		Technicien(string prenom, string nom, unsigned int age, string date,
		unsigned int unites)
		: Employe(prenom, nom, age, date), unites(unites)
		{}
		~Technicien() {}
		double calculer_salaire() const;
		string get_nom() const;
	protected:
		unsigned int unites;
};
double Technicien::calculer_salaire() const {
	return 5.0 * unites;
}
string Technicien::get_nom() const { return "Le technicien " + prenom + ' ' + nom; }
/* **********************************************************************
* La classe Manutentionnaire
*/
class Manutentionnaire: public Employe {
	public:
		Manutentionnaire(string prenom, string nom, unsigned int age, string date,
		unsigned int heures)
		: Employe(prenom, nom, age, date), heures(heures)
		{}
		~Manutentionnaire() {}
		double calculer_salaire() const;
		string get_nom() const;
		protected:
		unsigned int heures;
	};
	double Manutentionnaire::calculer_salaire() const {
	return 65.0 * heures;
}
string Manutentionnaire::get_nom() const { return "Le manut. " + prenom + ' ' + nom; }
/* **********************************************************************
* La classe d'employés à risque
*/
class ARisque {
	public:
		ARisque(double prime = 100) : prime(prime) {}
		virtual ~ARisque() {}
	protected:
		double prime;
};
/* *********************************************************************** une première sous-classe d'employé à risque
*/
class TechnARisque: public Technicien, public ARisque {
public:
	TechnARisque(string prenom, string nom, unsigned int age, string date,
	unsigned int unites, double prime)
	: Technicien(prenom, nom, age, date, unites), ARisque(prime)
	{}
	double calculer_salaire() const;
};
double TechnARisque::calculer_salaire() const {
return Technicien::calculer_salaire() + prime;
}
/* **********************************************************************
* une autre sous-classe d'employé à risque
*/
class ManutARisque: public Manutentionnaire, public ARisque {
public:
	ManutARisque(string prenom, string nom, unsigned int age, string date,
	unsigned int heures, double prime)
	: Manutentionnaire(prenom, nom, age, date, heures), ARisque(prime)
	{}
	double calculer_salaire() const;
};
double ManutARisque::calculer_salaire() const {
return Manutentionnaire::calculer_salaire() + prime;
}
/* **********************************************************************
* La classe Personnel
*/
class Personnel {
	public:
		void ajouter_employe(Employe* newbie) { staff.push_back(newbie); }
		void licencie();
		void afficher_salaires() const;
		double salaire_moyen() const;
	protected:
		vector<Employe*> staff;
};
void Personnel::licencie() {
	for (unsigned int i(0); i < staff.size(); i++) {
	delete staff[i];
}
	staff.clear();
}
double Personnel::salaire_moyen() const {
	double somme(0.0);
	for (unsigned int i(0); i < staff.size(); i++) {
	somme += staff[i]->calculer_salaire();
	}
	return somme / staff.size();
}
void Personnel::afficher_salaires() const {
for (unsigned int i(0); i < staff.size(); i++) {
	cout << staff[i]->get_nom() << " gagne "
	<< staff[i]->calculer_salaire() << " francs."
	<< endl;
}
}// ======================================================================
int main () {
	Personnel p;
	p.ajouter_employe(new Vendeur("Pierre", "Business", 45, "1995", 30000));
	p.ajouter_employe(new Representant("Léon", "Vendtout", 25, "2001", 20000));
	p.ajouter_employe(new Technicien("Yves", "Bosseur", 28, "1998", 1000));
	p.ajouter_employe(new Manutentionnaire("Jeanne", "Stocketout", 32, "1998", 45));
	p.ajouter_employe(new TechnARisque("Jean", "Flippe", 28, "2000", 1000, 200));
	p.ajouter_employe(new ManutARisque("Al", "Abordage", 30, "2001", 45, 120));
	p.afficher_salaires();
	cout << "Le salaire moyen dans l'entreprise est de "
	<< p.salaire_moyen() << " francs." << endl;
	// libération mémoire
	p.licencie();
}
