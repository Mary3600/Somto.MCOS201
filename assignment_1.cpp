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
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(0));

    string name;
    string course_name,location_name;
    bool is_PAU_student;
    int course_choice, location, days=0;
    int registration_fee=0, lodging_fee=0;

    cout<< "Welcome to the course registration outline.\n What is your Full Name?"<<endl;
    getline(cin, name);

    cout<<"Are you a PAU student(Kindly type 1 for yes and 0 for no)"<<endl;
    cin>>is_PAU_student;

    cout<<"What course would you like to register for?\n 1. Photography\n 2. Painting\n 3. Fish Farming\n 4. Baking\n 5. Public Speaking"<<endl;
    cin>>course_choice;

    if(course_choice == 1){
       days= 3;
       course_name = "Photography";
       registration_fee = 10000;
    }else if ( course_choice == 2){
        days = 5;
        course_name = "Painting";
        registration_fee = 8000;
    }else if ( course_choice == 3){
        days = 7;
        course_name = "Fish farming";
        registration_fee = 15000;
    }else if ( course_choice == 4){
        days = 5;
        course_name = "Baking";
        registration_fee = 13000;
    }else if ( course_choice == 5){
        days = 2;
        course_name = "Public speaking";
        registration_fee = 5000;
    }else{
        cout<<"Invalid input, terminating"<<endl;
        return 1;
    }

    cout<<"Accomodation is available, where would you like to stay?\n 1. Camp House A \n 2. Camp House B\n 3. Camp House C\n 4. Camp House D\n 5. Camp House E"<<endl;
    cin>>location;

    if(location == 1){
       lodging_fee = 10000;
       location_name = "Camp house A";
    }else if ( location == 2){
        lodging_fee = 2500;
        location_name = "Camp house B";
    }else if ( location == 3){
        lodging_fee = 5000;
        location_name = "Camp house C";
    }else if ( location == 4){
        lodging_fee = 13000;
        location_name = "Camp house D";
    }else if ( location == 5){
        lodging_fee = 5000;
        location_name = "Camp house E";
    }else{
        cout<<"Invalid input, terminating"<<endl;
        return 1;
    }

    float lodging_cost = lodging_fee * days;
    float lodging_discount = 0;
    float final_lodging_cost;
    float registration_discount = 0;
    float final_registration_fee;
    float total;

    if (is_PAU_student && (location ==1 || location ==2)){
        lodging_discount = 0.05 * lodging_cost;
    }

    final_lodging_cost = lodging_cost - lodging_discount ;

    if (days > 5 || registration_fee > 12000 ){
        registration_discount = 0.03 *registration_fee;
    }
    final_registration_fee = registration_fee - registration_discount;
    
    total = final_registration_fee + final_lodging_cost;

    int total_1;
    int promo =0;

    int random_num = (rand() % 100) +1 ;
    if(random_num == 7 || random_num == 77){
        promo = 500; 
    }
    total_1 =total - promo;

    cout<<"Name: "<< name<<"\tPAU Student: "<<(is_PAU_student? "Yes" : "No")<<endl;
    cout<<"Course Name: "<<course_name<<"\tDays "<<days<<endl;
    cout<<"Registration: ₦"<<final_registration_fee<<endl;
    cout<<"Loding: ₦"<<lodging_cost<<" x "<<days<<"= ₦"<<final_lodging_cost<<endl;
    cout<<"Random draw: "<<random_num<<"\tPromo applied ₦"<<promo<<endl;
    cout<<"Total: ₦"<<total_1<<endl;

    return 0;
}