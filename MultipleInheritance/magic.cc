
#include <iostream>
#include <string>
#include <vector>
using namespace std;
enum Color {WHITE,BLUE,BLACK,RED,GREEN};

class PlayingCard {
	protected:
		int price;
	public:
		PlayingCard (int price) : price(price) {}
		virtual ~PlayingCard () {}
		virtual void display() const =0;
		void display_price() const { 
			cout<<" of price "<<price<<endl;
			};
};



class Terrain :public virtual PlayingCard {
	private : 
		Color color;
	public:
	 Terrain(Color color,int price=0) 
		: PlayingCard(price),color(color) 
		{
			cout<<"A new Terrain"<<endl;
		}
	 ~Terrain()  {}
	 void display_attributes() const{
			 cout<<color;
	 }
	 void display() const {
		 cout<<"Terrain of color ";
		 display_attributes();
	 }
};
class Creature :public virtual PlayingCard{
	private :
		string name;
		int dammage_pts;
		int life_points;
	public :
		Creature(int price,string name,int dammage_pts,int life_points) 
			: PlayingCard(price),name(name),dammage_pts(dammage_pts),life_points(life_points)
			 { 
				 cout<<"A new Creature"<<endl;
			 }			
		~Creature(){}
		 void display_attributes() const{
			 cout<<name<<" "<<dammage_pts<<"/"<<life_points;
			 }
		 void display() const {
		 cout<<"Creature ";
		 display_attributes();
		 display_price();
		 }
};
class Spell :public PlayingCard{
	private :
		string name;
		string explanation;
	public:
		Spell(int price,string name,string explanation) : 
			PlayingCard(price),name(name),explanation(explanation) 
			{
				 cout<<"A new Spell"<<endl;
			}
			~Spell() {}
	 void display() const {
		 cout<<"Spell "<<name;
		 display_price();
	 }
};


class Game{	
		private:
			vector<PlayingCard*> p;
		public:
			
			void add(PlayingCard* i)
			{	p.push_back(i);
			} 
			void display() 
			{
				cout<<" I have :"<<endl;
				 for(auto i:p) 
				 {
					  cout<<"+  "; 
					  i->display() ; 
				 }
			}
			void endGame(){
				cout<<" I fold"<<endl;
				 for(auto i:p) 
				 {
					  delete i ; 
				 }
				 p.clear();
			}
};

class TerrainCreature : public Creature, public Terrain{
	public:
		TerrainCreature(int price,string name,int dammage_pts,int life_points,Color color)
			: PlayingCard(price),Creature(price,name,dammage_pts,life_points),Terrain(color) 
			{
				cout<<"A new terrain Creature"<<endl;
				}
		~TerrainCreature() {}
	 void display() const {
		 cout<<"TerrainCreature color ";
		 Terrain::display_attributes();
		 cout<<" ";
		 Creature::display_attributes();
		 cout<<endl;
	 }
};

int main () {
	Game myhand;
	myhand.add(new Terrain(BLUE));
	myhand.add(new Creature(6, "Golem", 4, 6));
	myhand.add(new Spell(1, "Croissance Gigantesque","La créature ciblée gagne +3/+3 jusqu'à la fin du tour"));
	myhand.add(new TerrainCreature(2, "Ondine", 1, 1, BLUE));
	myhand.display();
	myhand.endGame();
	return 0;
};
