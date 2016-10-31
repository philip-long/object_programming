#include <iostream>
#include <cmath>

/*
 * 
 * 
 * 
 * */


using namespace std;
struct spectator_details{
	int age;
	int sum;
};

class Paper{
	private :	
		spectator_details paper_details_;
	public :
	void write_paper(int age, int sum);
	void read_paper(spectator_details& paper_details) const;	
};

void Paper::write_paper(int age,int sum)
{
	cout<<"I am writing details on paper";
	paper_details_.age=age;
	paper_details_.sum=sum;
}
void Paper::read_paper(spectator_details& paper_details) const{
	cout<<"I am reading details from paper";
	paper_details=paper_details_;
}

class Spectator{
	private:
		spectator_details paper_details_;
	public :
		void askAge(); // ask age
		void askSum(); // ask sum
		void writeDetails(spectator_details& paper_details) const;
};

void Spectator::askAge()
{
	paper_details_.age=-1;
	do 
	{	
	cout<<"Spectator: What age am I? "; cin>>paper_details_.age;
	}
	while(paper_details_.age<=0);
}

void Spectator::askSum()
{
	paper_details_.sum=-1;
	do 
	{	
	cout<<"Spectator: How much money do I have in my pocket? "; cin>>paper_details_.sum;
	}
	while(paper_details_.sum<0 || paper_details_.sum>99);
}
void Spectator::writeDetails(spectator_details& paper_details) const
{	
	cout<<" Spectator: I am writing my details"<<endl;
	paper_details=paper_details_;
}

class Assitant{
	private:
		spectator_details paper_details_;
		int calculateDetails() const;
		int announce_;
	public:
	void readDetails(spectator_details paper_details);
	int annouceDetails() const;
};

void Assitant::readDetails(spectator_details paper_details){
	cout<<"Assitant: I am reading details from paper"<<endl;
	paper_details_=paper_details;
	announce_=calculateDetails();	
}
int Assitant::calculateDetails() const
{
	cout<< "Assitant: I am calculating"<<endl;
	return (((5+(paper_details_.age*2))*50)+paper_details_.sum)-365;
}

int Assitant::annouceDetails() const
{
	cout<<"Assitant: I annouce"<< announce_<<endl;
	return announce_;
}

class Magician{
	public:
	int findDetails(int annouce);
};

int Magician::findDetails(int annouce)
{
	int code=annouce+115;
	
	cout<<"I see you are "<<code<<" years old and have "<<code<<" francs in your pocket"<<endl;
	return code;
}





int main(){
	spectator_details public_specs;
	Spectator spec;
	Assitant assitant;
	Magician magician;
	spec.askAge();
	spec.askSum();
	spec.writeDetails(public_specs);
	assitant.readDetails(public_specs);
	magician.findDetails(assitant.annouceDetails());
	}
