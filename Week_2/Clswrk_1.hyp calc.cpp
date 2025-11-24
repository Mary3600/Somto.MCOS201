//Hypotenuse calculator
#include <iostream>
#include <cmath> // for sqrt and pow() functions
using namespace std;

int main(){
	float a,b;
	
	cout<<"What is the length of the first side?";
	cin>> a;
	
	cout<<"What is the length of the second side?";
	cin>> b;
	
	float hyp = sqrt((pow(a,2) + pow(b,2)));
	
	cout<<"The hypotenuse of your triangle is: "<<hyp<<endl;
	
	return 0;
}