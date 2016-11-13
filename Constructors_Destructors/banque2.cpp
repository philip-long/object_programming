#include <iostream>
#include <string>
#include <vector>

using namespace std;
enum gender{MALE,FEMALE};

class Account{
	public:
		Account(double rate,string name)
				:rate(rate), name(name)
				{
					}
		double bouclerCompte(double balance);
		string Name() const; //getter
	private:
		double const rate;
		string const name;
};
string Account::Name() const{
	return name;
}

double Account::bouclerCompte(double balance) {
  double interest(rate * balance);
  balance=balance + interest;
  return balance;
}


class Client{
	public:
		Client(string name,
			   string town,
			   gender g,
			   double balance_savings,
			   double balance_current
				): name_(name),town_(town),gender_(g),balance_savings(balance_savings),balance_current(balance_current)
			   {			   					  				     
			   }			   
		double Balance_Savings() const{
			return balance_savings;
			} 
		double Balance_Current() const{
			return balance_current;
		}
		gender Gender() const{
			return gender_;
		}
		string Name() const{
			return name_;
		}
		string Town() const{
			return town_;
		}
		void Town(string p) {
			town_=p;
		}
		void Balance_Savings(double b){
			cout<<"Setting new savings balance = "<<b<<endl;
			balance_savings=b;
		}
		void Balance_Current(double b){
			cout<<"Setting new current balance"<<endl;
			balance_current=b;
		}
	private:
		string name_;
		string town_;
		gender gender_; 
		double balance_savings;
		double balance_current;
};



class Bank{
	private:
		vector<Client*> vec_clients;
		Account current;
		Account savings;
		
	public:
		Bank(const Account& savings, const Account& current) : current(current),savings(savings)
		{

		}
		void addClient(Client& c){
			vec_clients.push_back(&c);
		}
		
		void printData() const{
				
			for(auto c:vec_clients)
			{
				if(c->Gender()==gender::MALE){
					cout<<"Client ";
				} 
				else
				{
					cout<<"Cliente ";
				}
				cout<<c->Name()<<" from "<<c->Town()<<endl;
				cout<<current.Name()<<" "<<c->Balance_Current()<< " francs"<<endl;
				cout<<savings.Name()<<" "<<c->Balance_Savings()<< " francs"<<endl;
			}
			
		}
			void updateAccounts() 
			{	
				for(auto& c:vec_clients)
				{					
					c->Balance_Current(current.bouclerCompte(c->Balance_Current()));
					c->Balance_Savings(savings.bouclerCompte(c->Balance_Savings()));
				}
			}
};

int main()
{
	Account savings(0.02,"Savings ");
	Account current(0.01,"Current ");
	Client pedro("Pedro",
				 "Geneve",
				  gender::MALE,
				  1000.,
				  2000.);
	Client alexandra("Alexandra",
				 "Lausanne",
				  gender::FEMALE,
				  3000.,
				  4000.);
	
	Bank bank(savings,current);	
	bank.addClient(pedro);
	bank.addClient(alexandra);
	cout << "Données avant le bouclement des comptes :" << endl;
	bank.printData();	
	cout << "Données apres le bouclement des comptes :" << endl;	
	bank.updateAccounts();
	cout<<" Accounts updated"<<endl;
	bank.printData();	
  return 0;
}
