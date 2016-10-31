#include <iostream>
using namespace std;

class Paper {
public:
void write(unsigned int age, unsigned int sum) {
	age_= age;
	sum_ = sum;
}
unsigned int read_age() const 
{ 
	return age_; 
}
unsigned int read_sum() const 
{
	 return sum_;
}
private:
	unsigned int age_;
	unsigned int sum_;
};

// --------------------------------------
class Assistant {
public:
	void read(const Paper& card);
	void calculate();
	unsigned int annonce();
private:
	unsigned int age_;
	unsigned int sum_;
	unsigned int result_;
};


// --------------------------------------
class Spectator {
public:
	void arrival();
	void write();
	Paper show(); 
private:
	unsigned int age_;
	unsigned int sum_;
	Paper spec_paper;
};

// --------------------------------------
class Magicien {
public:
	void magic_trick(Assistant& asst, Spectator& spect);
private:
	void calculate(unsigned int assitanat_info);
	void annonce();
	unsigned int age_;
	unsigned int sum_;
};


int main()
{
	Spectator spectator;
	spectator.arrival();
	Magicien magicien;
	Assistant assistant;
	magicien.magic_trick(assistant,spectator); 
return 0;
}

// ----------------------------------------------------------------------
void Assistant::read(const Paper& card)
{
	cout << "[Assistant] (I am reading the card)" << endl;
	age_= card.read_age();
	sum_ = card.read_sum();
}

void Assistant::calculate()
{
	cout << "[Assistant] (I am calculating)" << endl;
	result_ =(((5+(age_*2))*50)+sum_)-365;
}

unsigned int Assistant::annonce()
{
cout << "[Assistant] I am annoucing : " << result_ << " !" << endl;
return result_;
}

void Spectator::arrival()
{
cout << "[Spectator] (I have arrived)" << endl;
cout << "What age am I? ";
cin >> age_;
do {
cout << "How much money do I have (<100) ? ";
cin >> sum_;
} while (sum_ >= 100);
cout << "[Spectator] (I am here)" << endl;
}
void Spectator::write()
{
cout << "[Spectator] (I am writing the paper)" << endl;
spec_paper.write(age_, sum_);
}
Paper Spectator::show()
{
cout << "[Spectator] (I am showing the paper)" << endl;
return spec_paper;
}



void Magicien::magic_trick(Assistant& assitant, Spectator& spectator)
{
cout << "[Magicien] A magic trick" << endl;
spectator.write();
assitant.read(spectator.show());
assitant.calculate();
calculate(assitant.annonce());
annonce();
}
void Magicien::calculate(unsigned int result_received) {
result_received += 115;
age_= result_received / 100;
sum_ = result_received % 100;
}
void Magicien::annonce() {
cout << "[Magicien] " << endl
<< "I see your age is  " << age_ << " ans" << endl
<< "and you have " << sum_ << " francs in your pocket !" << endl;
}

