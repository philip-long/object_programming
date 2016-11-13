#include <iostream>
#include <vector>

typedef size_t Degree;
class Polynome{
	private:
		vector<double> p;
	public:
		Degree degree();
		Polynome( 
};

Degree Polynome::degree(){
	return p.size()-1;
}
