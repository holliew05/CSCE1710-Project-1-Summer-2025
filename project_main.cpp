#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	enum employee_roll{MANAGER=1, DEVELOPER=2, TESTER=3, INTERN=4};
	
	srand(time(NULL));
	
	int employee_num=0;
	string name;
	string role;
	double hours=0.0;
	double base_salary=0.0;
	double bonus=0.0;
	double tax=0.0;
	double net_salary=0.0;
	int ch;
	char loop='Y';
	int i;
	bool validName=false;

	while(loop=='Y' || loop=='y'){
		validName = false;
		while(!validName){
			cout<<"Enter full name (first and last name required): ";
			getline(cin, name);
			validName=true;
			
			int spaceCount=0;
			int lastSpace=-1;

			for(i=0;i<name.length();i++){
				if(!isalpha(name[i]) && !isspace(name[i])){
					cout<<"INVALID: contains invalid characters."<<endl;
					cout<<"Please try again."<<endl;
					validName=false;
					break;
				}
				if (isspace(name[i])){
					spaceCount++;
					lastSpace=i;}
			}
			
			if(validName && (spaceCount==0 || lastSpace==name.length()-1)){
				cout<<"INVALID: Please enter both first and last name."<<endl;
				cout<<"Please try again."<<endl;
				validName=false;
				}
			
			if(validName){
				for(i=0;i<name.length();i++){
					if(isspace(name[i]) && i+1 < name.length()){
						name[i+1]=toupper(name[i+1]);
					}
				}
				name[0]=toupper(name[0]);
				employee_num=employee_num+1;
				cout<<"Welcome "<<name<<"."<<endl;
				cout<<"Hours worked this month: ";cin>>hours;
				if(hours<0){
					cout<<"INVALID: cannot work less than 0 hours. Please try again"<<endl;
					cout<<"Hours worked this month: ";cin>>hours;
				}
	
				cin.ignore(); 
				
				bool valid_choice=false;
		do{
			cout<<"Select job role."<<endl;
				cout<<"1. Manager"<<endl;
				cout<<"2. Developer"<<endl;
				cout<<"3. Tester"<<endl;
				cout<<"4. Intern"<<endl;
				cin>>ch;
				cin.ignore();
				
				
				
				switch(ch){
					case(MANAGER):
					valid_choice=true;
						cout<<"Employee #"<<employee_num<<": "<<name<<endl;
						cout<<"Role: Manager"<<endl;
						base_salary=5000.00;
						cout<<"Base Salary: $"<<base_salary<<endl;
						bonus=rand()%1000+100;
						if(hours>=160){
							bonus=bonus+750;
						}
						cout<<"Bonus: $"<<bonus<<endl;
						tax=(base_salary+bonus)*0.03;
						cout<<"Tax: $"<<fixed<<setprecision(0)<<tax<<endl;
						net_salary=base_salary+bonus-tax;
						cout<<"Net Salary: $"<<net_salary<<endl;
						break;
					case(DEVELOPER):
					valid_choice=true;
						cout<<"Employee #"<<employee_num<<": "<<name<<endl;
						cout<<"Role: Developer"<<endl;
						base_salary=4000.00;
						cout<<"Base Salary: $"<<base_salary<<endl;
						bonus=rand()%800+100;
						if(hours>=160){
							bonus=bonus+500;
						}
						cout<<"Bonus: $"<<bonus<<endl;
						if((base_salary+bonus)>=5000){
							tax=(base_salary+bonus)*0.03;
						}
						else{
							tax=(base_salary+bonus)*0.02;
						}
						cout<<"Tax: $"<<fixed<<setprecision(2)<<tax<<endl;
						net_salary=base_salary+bonus-tax;
						cout<<"Net Salary: $"<<net_salary<<endl;
						break;
					case(TESTER):
					valid_choice=true;
						cout<<"Employee #"<<employee_num<<": "<<name<<endl;
						cout<<"Role: Tester"<<endl;
						base_salary=3000;
						cout<<"Base Salary: $"<<base_salary<<endl;
						bonus=rand()%500+100;
						if(hours>=160){
							bonus=bonus+350;
						}
						cout<<"Bonus: $"<<bonus<<endl;
						tax=(base_salary+bonus)*0.02;
						cout<<"Tax: $"<<fixed<<setprecision(2)<<tax<<endl;
						net_salary=base_salary+bonus-tax;
						cout<<"Net Salary: $"<<net_salary<<endl;
						break;
					case(INTERN):
					valid_choice=true;
						cout<<"Employee #"<<employee_num<<": "<<name<<endl;
						cout<<"Role: Intern"<<endl;
						base_salary=1500.00;
						cout<<"Base Salary: $"<<base_salary<<endl;
						bonus=rand()%250+100;
						if(hours>=160){
							bonus=bonus+150;
						}
						cout<<"Bonus: $"<<bonus<<endl;
						tax=(base_salary+bonus)*0.01;
						cout<<"Tax: $"<<fixed<<setprecision(2)<<tax<<endl;
						net_salary=base_salary+bonus-tax;
						cout<<"Net Salary: $"<<net_salary<<endl;
						break;
					default:
						cout<<"Invalid Option. Please Try Again."<<endl;
						break;
				}
				} while(!valid_choice);
			}
		}
		cout<<"Would you like to enter another employee? (Y or N): ";cin>>loop;
		cin.ignore();
	}
	return 0;
}
