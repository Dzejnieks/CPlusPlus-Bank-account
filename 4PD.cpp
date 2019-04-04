//============================================================================
// Name        : 4PD.cpp
// Author      : Aksels Skvorcovs
// Version     :
// Copyright   : 
// Description : 13. uzdevums

//Izveidot klasi "Bankas konts", kurā tiek glabāti divi skaitļi - summa un procentu likme gadā. Klasei izveidot šādas
//metodes: (1) konstruktors, ar kuru tiek padotas sākotnējās vērtības, (2) destruktors, kurš paziņo par objekta likvidēšanu,
//(3) metode "Papildināt kontu", kas papildina kontu ar noteiktu summu, (4) metode "Izņemt naudu", kas samazina konta
//atlikumu, (5) metode "Mainīt procentus", kas uzstāda jauno procentu likmi, (6) metode "Pārrēķināt summu" ar uzrādītu
//periodu dienās, kas izrēķina ienākumu no procentiem noteiktā laika periodā un papildina kontu ar šo summu (tiek
//uzskatīts, ka visos mēnešos ir pa 30 dienām), (4) metode "Drukāt", kas izdrukā konta atlikumu.

//============================================================================

#include <iostream>
using namespace std;
class Account{
private:
	double balance=0;
	double percent=0.02;
public:
	Account(int b){
		this->balance = b;
		cout<<"Created: Bank account, with its balance being "<<balance<<endl;
		cout<<"Accounts deposit percent set to "<<percent<<endl;
	}
	void deposit(int d){
		this->balance +=d;
		cout<<"Bank account update: Deposit made "<<d<<endl<<"Balance update: "<<balance<<endl;
	}
	void withdraw(int w){
		this->balance -=w;
		cout<<"Bank account update: Withdraw made "<<w<<endl<<"Balance update: "<<balance<<endl;
	}
	void monthly(){
		this->balance+=this->balance*this->percent;
		//cout<<"Bank account update: Percent added to balance. New balance: "<< this->balance <<". Percent= "<<this->percent<<endl;
	}
	void skip(int s){
		for(int x=0;x<=s;x++){
			this->monthly();
		}
		cout<<"Bank account update: Time skipped, percent added. New balance: "<< this->balance<<". Percent= "<<this->percent<<endl;
	}
	void change_percent(double c){
		this->percent = c;
		cout<<"Bank account update: Percent changed. New percent = "<<this->percent<<endl;
	}
	void print_balance(){
		cout<<"Bank account's balance is "<<this->balance<<endl;
	}

};
int main() {
	Account konts(300);
	int t;
	do{
	cout<<"Insert 1 to make a deposit"<<endl<<
			"Insert 2 to make a withdraw"<<endl<<
			"Insert 3 to skip months"<<endl<<
			"Insert 4 to see your account's balance"<<endl;
	int x;
	cin>>x;
	switch(x){
	case 1 :
		double d;
		cout<<"Enter the number to deposit";
		cin>>d;
		konts.deposit(d);
		break;
	case 2 :
		double w;
		cout<<"Enter the number to withdraw";
		cin>>w;
		konts.withdraw(w);
		break;
	case 3 :
		int s;
		cout<<"Enter how many months you want to skip";
		cin>>s;
		konts.skip(s);
		break;
	case 4 :
		konts.print_balance();
		break;
	default :
	cout<<"Error";
	break;
	}
	cout<<"Do you want to quit? Insert 1 to continue, or 2 to quit";
	cin>>t;
	}while(t==1);

}
