/*#include <iostream>
using namespace std;

int main(){
    int sum=0, data =0;
    do{
        sum += data;
        cout<<"Enter an integer (input ends if it is 0):";
        cin>>data;
    }
    while(data!=0);
    cout<<"The sum is:"<<sum;
    return 0;
}
    */


 // Strarting the assignment (Course registration)
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    string name;
    bool is_PAU_student;
    int course_choice, location, days;
    int registration_fee, lodging_fee;

    cout<< "Welcome to the course registration outline./n What is your Full Name?"<<endl;
    getline(cin, name);

    cout<<"Are you a PAU student(Kindly type 1 for yes and 0 for no)"<<endl;
    cin>>is_PAU_student;

    cout<<"What course would you like to register for?\n 1. Photography\n 2. Painting\n 3. Fish Farming\n 4. Baking\n 5. Public Speaking"<<endl;
    cin>>course_choice;

    if(course_choice == 1){
       days= 3;
       registration_fee = 10000;
    }else if ( course_choice == 2){
        days = 5;
        registration_fee = 8000;
    }else if ( course_choice == 3){
        days = 7;
        registration_fee = 15000;
    }else if ( course_choice == 4){
        days = 5;
        registration_fee = 13000;
    }else if ( course_choice == 5){
        days = 2;
        registration_fee = 5000;
    }else{
        cout<<"Kidly choice from option 1-5"<<endl;
    }

    cout<<"Accomodation is available, where would you like to stay?\n 1. Camp House A \n 2. Camp House B\n 3. Camp House C\n 4. Camp House D\n 5. Camp House E"<<endl;
    cin>>location;

    if(location == 1){
       lodging_fee = 10000;
    }else if ( location == 2){
        lodging_fee = 8000;
    }else if ( location == 3){
        lodging_fee = 15000;
    }else if ( location == 4){
        lodging_fee = 13000;
    }else if ( location == 5){
        lodging_fee = 5000;
    }else{
        cout<<"Kidly choice from option 1-5"<<endl;
    }

    int lodging_cost;
    int total ;

    if (is_PAU_student && (location ==1 || location ==2)){
        lodging_cost = 0.05 * lodging_fee * days;
    }else{
        lodging_cost = lodging_fee * days;
    }

    if (days > 5 || registration_fee > 12000 ){
        total = (0.03 *registration_fee) + lodging_cost;
    }else{
        total = registration_fee + lodging_cost;
    }

    int total_1;

    int random_num = (rand() % 100) +1 ;
    if(random_num == 7 || random_num == 77){
        total_1 = total - 500; 
    }else{
        total_1 = total;
    }

    cout<<"Name: "<< name<<endl;
    cout<<"Course Name:"<<course_choice<<"\nDays"<<days<<endl;
    
}