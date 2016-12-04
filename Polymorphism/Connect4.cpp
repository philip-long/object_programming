#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

enum Color {EMPTY=0,RED,YELLOW};

class Game{
	private:
		size_t size;
		vector<vector<Color>> grid;
	public:
		// Initialise grid size
		Game(size_t size) :size(size), grid(size,(vector<Color>(size,EMPTY))) {}
		bool play(size_t column,Color color) ; 
		Color winner() const;
};

bool Game::play(size_t column,Color color){
	
	if(color==EMPTY) return false;
	if(column>size) return false;
	for(auto& i:grid[column]){
		if(i==EMPTY)
		{
			i=color;
			return true;
		}
	}
	return false;
}

Color winner() const{
	Color winning_player(EMPTY);
	for(size_t i=0;i<size;i++){
		for(size_t j=0;j<size;j++){
			piece=grid[i][j];
			// Test in all five unrepeated directions
			
		}
	}
}

class Match{
	private:
	public:
};

class Players{
	private:
		Color color;
		string name;
	public:
		Players(Color color, string name): color(color),name(name) {}
		virtual void play(Game& g) ;
};

int main(){
	
	return 0;
}
