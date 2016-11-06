#include <iostream>
#include <string>
using namespace std;
class Fleur{
	public:
	 Fleur(string type,string colour): type_(type),colour_(colour){
		 cout<<type<<" fraichement cueillie"<<endl;
	 }
	Fleur(const Fleur& Fleu) : colour_(Fleu.colour_)
	{
		cout<<"Fragile corolle taillée"<<endl;
	}
	~Fleur(){
		cout<<"qu'un simple souffle..."<<endl;
	}
	
	void eclore(){
		cout<<"veine de"<<colour_<<endl;
	}
	
	private: 
		string type_;
		const string colour_;
};
int main ()
{
Fleur f1("Violette", "bleu");
Fleur f2(f1);
cout << "dans un cristal ";
f2.eclore();
cout << "Donne un poème un peu fleur bleue" << endl
<< "ne laissant plus ";
return 0;
}

/*
Violette fraichement cueillie
Fragile corolle taillée
dans un cristal veine de bleu
Donne un poème un peu fleur bleue
ne laissant plus qu'un simple souffle...
qu'un simple souffle...
*/
