#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;
class Book{
	protected:
		string title;
		string author;
		int pages;
		bool bestseller;
	public:
		Book(string title,string author,int pages, bool bestseller)
			:title(title),author(author),pages(pages),bestseller(bestseller) {}
		virtual ~Book(){}
		
		virtual double calculatePrice() const{ 
			if(bestseller)
			{
				return pages*0.3+50.;
			}
			else
			{
				return pages*0.3;
			}
		}
		virtual void display(ostream& out) const{
			out<<"Title: "<<title<<endl;
			out<<"Author: "<<author<<endl;
			out<<"Pages: "<<pages<<endl;
			out<<"Bestseller: ";
			if(bestseller){
			out<<" Yes";
			}
			else{
				out<<"No";				
			}
			out<<endl;
			out<<"Price: "<<calculatePrice()<<endl;
		}

};


class Novel :public Book{
	protected:
		bool biography;
	public:
		Novel(string title,string author,int pages, bool bestseller,bool biography=false):
			Book(title,author,pages,bestseller),biography(biography) {}
		virtual ~Novel(){}
			void display(ostream& out) const;
};

void Novel::display(ostream& out) const{
			Book::display(out);
			out<<"Biography: ";
			if(biography){
			out<<"Yes";
			}
			else{
				out<<"No";				
			}
			out<<endl;
			
		}
		
class CrimeNovel : public Novel{
	public:
		// We can inherite the constructor as there are no new attributes
		using Novel::Novel;
		virtual ~CrimeNovel(){}
		virtual double calculatePrice() const{ 
			double p=Book::calculatePrice() -10;
			if(p>0){
				return p;
			}
			else{
				return 1.0;
			}
			
		}
};
class BeauLivre :public Book{
	private:
		
	public:
		// We can inherite the constructor as there are no new attributes
		using Book::Book;
		virtual double calculatePrice() const{ 
			return (Book::calculatePrice() + 30);
		}
};


class Library{
	private:
	vector<Book*> collection;
	public:
	void add_book(Book *b);
	void display() const;
	void empty();
};

void Library::add_book(Book *b){
	collection.push_back(b);
}

void Library::display () const {
	for(auto i:collection){
		i->display(cout);
	}
}

void Library::empty () {
	for(auto i:collection){
		delete i;
	}
	collection.clear();
}

int main() {
	Book b("Canada","Ford",412,true);
	BeauLivre c("Watchmen","Moore",100,true);
	CrimeNovel d("Lincoln Lawyer","Connelly",300,true,false);
	Novel f("Peter the Great","Massie",765,false,true);
	Novel e("Nobody's fool","Russo",243,false,false);
	b.display(cout);
	c.display(cout);
	d.display(cout);
	e.display(cout);
	f.display(cout);
	
	cout<<"========================="<<endl;
	Library l;
	l.add_book(new CrimeNovel("Le chien des Baskerville", "A.C.Doyle",
	221, false, false));
	l.add_book(new CrimeNovel("Le Parrain ", "A.Cuso", 367, true, false));
	l.add_book(new Novel("Le baron perché", "I. Calvino", 283, false, false));
	l.add_book(new Novel ("Mémoires de Géronimo", "S.M. Barrett", 173, false, true));
	l.add_book(new BeauLivre ("Fleuves d'Europe", "C. Osborne", 150, false));
	l.display();
	l.empty();
return 0;
	
	return 0;
}

