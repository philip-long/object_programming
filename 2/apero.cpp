#include <iostream>
using namespace std;

class Apero{
	public:
	Apero(){
		cout<<"L'heure de l'apéro a sonné !"<<endl;
	}
	~Apero(){
		cout<<" A Table"<<endl;
	}
	void bis(){
		cout<<"Encore une"<<endl;
	}
	private:	
};


int main() {
Apero bic;
cout << "Super !" << endl;
bic.bis();
cout << "Non merci." << endl;
return 0;
}



/*
affiche le texte suivant :
L'heure de l'apéro a sonné !
Super !
Encore une ?
Non merci.
À table !*/
