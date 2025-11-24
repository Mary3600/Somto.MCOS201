//swapping problem
#include <iostream>
using namespace std;

int main(){
	int x_1 = 5;
	int y_1 = 6;
	
	int z = y_1;
	int y = x_1;
	int x = z;
	
	cout<<"Original x value ="<<x_1<<endl;
	cout<<"Original y value ="<<y_1<<endl;
	
	cout<<"Swapped x value ="<<x<<endl;
	cout<<"Swapped y value ="<<y<<endl;
	
	return 0;
}