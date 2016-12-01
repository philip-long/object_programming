#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Employee{	
	protected :
		string surname_;
		string first_name_;
		unsigned int age_;
		string start_date_;
		static constexpr double BONUS_VENDER = 400.0;
		static constexpr double BONUS_REP = 800.0;
	public : 
		Employee (string surname,
				  string first_name,
				  unsigned int age,
				  string start_date)
			: surname_(surname),first_name_(first_name),age_(age), start_date_(start_date)
			 {}
		 virtual ~Employee() { }
		 virtual double calculate_salary () = 0 ;
		 virtual string getName() const ;
};

string Employee::getName() const {
	return "Employee "+first_name_+" "+surname_; 
}

class Commercial :public Employee{
	protected : 
		double salary_bonus;
		double profit;
		
	public: 
		Commercial(string surname,
				  string first_name,
				  unsigned int age,
				  string start_date,
				  double bonus,
				  double profit
				  )
			: Employee(surname,first_name,age,start_date),salary_bonus(bonus),profit(profit) {}
		 double calculate_salary ();
		 ~Commercial(){}
		
};

double Commercial::calculate_salary(){
	
	return (profit*0.2)+salary_bonus;	
}

class Vender : public Commercial{
	private :
	public : 
		Vender(string surname,
				  string first_name,
				  unsigned int age,
				  string start_date,
				  double profit
				  ) : 
				  Commercial(surname,first_name,age,start_date,BONUS_VENDER,profit) {}			
		~Vender(){}
		string getName() const;
				  
};


string Vender::getName() const {
	return "The Salesman "+first_name_+" "+surname_; 
}

class Rep : public Commercial{
	private : 
	
	public : 
		Rep(string surname,
				  string first_name,
				  unsigned int age,
				  string start_date,
				  double profit
				  ) : 
				  Commercial(surname,first_name,age,start_date,BONUS_REP,profit) {}
		~Rep(){}		
		string getName() const;	
		
};

string Rep::getName() const {
	return "The Rep "+first_name_+" "+surname_; 
}

class Technician :public Employee{	
	private : 
		unsigned int units_;
	public : 
			Technician(string surname,
				  string first_name,
				  unsigned int age,
				  string start_date,
				  unsigned int units
				  )
			: Employee(surname,first_name,age,start_date),units_(units) {}
		 double calculate_salary ();
		 ~Technician(){}
		 string getName() const;
};

double Technician::calculate_salary(){
	return units_*5;
}
string Technician::getName() const {
	return "The Technician "+first_name_+" "+surname_; 
}
class Worker :public Employee{
		unsigned int hours_;
	public : 
			Worker(string surname,
				  string first_name,
				  unsigned int age,
				  string start_date,
				  unsigned int hours
				  )
			: Employee(surname,first_name,age,start_date),hours_(hours) {}
		~Worker(){}
		 double calculate_salary ();
		 string getName() const ;

};

string Worker::getName() const {
	return "The Worker "+first_name_+" "+surname_; 
}

double Worker::calculate_salary(){
	return hours_*65.0;
}

class EmployeesAtRisk{
	protected:
		double monthly_bonus;
	public : 
		EmployeesAtRisk(double monthly_bonus=100) : monthly_bonus(monthly_bonus){}
		~EmployeesAtRisk() {}
	
};

class TechnicianRisk : public Technician , public EmployeesAtRisk{
	public : 
	TechnicianRisk(string surname,
				  string first_name,
				  unsigned int age,
				  string  start_date,
				  unsigned int units,
				  double monthly_bonus=100
				  )
			: Technician(surname,first_name,age,start_date,units),EmployeesAtRisk(monthly_bonus) {}
		 double calculate_salary ();
		 ~TechnicianRisk(){}
};

double TechnicianRisk::calculate_salary(){
	return Technician::calculate_salary()+monthly_bonus;
}

class WorkerRisk : public Worker , public EmployeesAtRisk{
		public :
			WorkerRisk(string surname,
				  string first_name,
				  unsigned int age,
				  string start_date,
				  unsigned int hours,
				  double monthly_bonus=100
				  )
			: Worker(surname,first_name,age,start_date,hours),EmployeesAtRisk(monthly_bonus)  {}
		~WorkerRisk(){}
		 double calculate_salary ();
};


double WorkerRisk::calculate_salary(){
	return Worker::calculate_salary()+monthly_bonus;
}

class Staff{
	private:
		vector<Employee*> p;
	public:
		void add_employee(Employee*);
		void display_salary() const;
		double average_salary() const;
		void fire_employees() ;
};

void Staff::add_employee(Employee* e){
	p.push_back(e);
}

void Staff::display_salary() const{
	for(auto i:p){
		cout<<i->getName()<<" earns "<<i->calculate_salary()<<" francs"<<endl;
	}
}


double Staff::average_salary() const{
	double sum=0;
	for(auto i:p){
		sum+=i->calculate_salary();
	}
	return sum/p.size();
}

void Staff::fire_employees() {
	for(auto i:p){
		delete i;
	}
	p.clear();
}

int main(){
	Staff p;
	p.add_employee(new Vender("Pierre", "Business", 45, "1995", 30000));
	p.add_employee(new Rep("Léon", "Vendtout", 25, "2001", 20000));
	p.add_employee(new Technician("Yves", "Bosseur", 28, "1998", 1000));
	p.add_employee(new Worker("Jeanne", "Stocketout", 32, "1998", 45));
	p.add_employee(new TechnicianRisk("Jean", "Flippe", 28, "2000", 1000, 200));
	p.add_employee(new WorkerRisk("Al", "Abordage", 30, "2001", 45, 120));
	
	p.display_salary();
	cout << "Le salaire moyen dans l'entreprise est de "
	<< p.average_salary() << " francs." << endl;
	// libération mémoire
	p.fire_employees();
	return 0;
};
