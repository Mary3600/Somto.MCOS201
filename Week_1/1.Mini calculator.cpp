//Mini calculator
#include <iostream>
using namespace std;

int main(){
	int x, y;
	
	cout<<"What the first number?";
	cin >> x;
	
	cout<<"What the second number?";
	cin >> y;
	
	int sum = x+y;
	int difference = x-y;
	int product = x*y;
	
	cout<<"The sum of the numbers are,"<< sum << endl;
	cout<<"The difference of the numbers are,"<< difference << endl;
	cout<<"The product of the numbers are,"<< product << endl;
	
	return 0;
}