// Interet calculator
#include <iostream>
using namespace std;

int main(){
	double account_bal, annual_interest_rate;
	int time = 1;
	
	cout<<"What is your initial account balance?";
	cin>> account_bal;
	
	cout<<"What is the anual interest rate?(percentage)";
	cin>> annual_interest_rate;
	
	double interest = account_bal * annual_interest_rate * time;
	double current_bal = account_bal + interest;
	
	cout<<"Your acount balance after a year="<< current_bal<<endl;	
	return 0;
}