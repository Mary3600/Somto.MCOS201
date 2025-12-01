//Admissions, Scholarship & Hostel Decision

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
int base_tuition = 1500000.0;

int main(){
    srand(time(0));

    string name;
    double waec_avg;
    int jamb_score, age;
    bool first_choice_pau, disciplinary_record;
    int hostel_preference = 0;

    cout<<"What is your full name?"<<endl;
    getline(cin,name);

    cout<<"What is your JAMB score?(0-400)"<<endl;
    cin>>jamb_score;

    cout<<"What's your WAEC average?(0-100)"<<endl;
    cin>>waec_avg;

    cout<<"How old are you?"<<endl;
    cin>>age;

    cout<<"Is PAU your first choice?(1 for 'yes' and 0 for 'no')"<<endl;
    cin>>first_choice_pau;

    cout<<"Do you have any disciplinary record?(1 for 'yes' and 0 for 'no')"<<endl;
    cin>>disciplinary_record;

    string admission_status;

    if(disciplinary_record == true|| age <15){
        admission_status = "rejected";
    }else if(((jamb_score >= 220 && waec_avg >= 60) && first_choice_pau == true)||(jamb_score >=200 && waec_avg >= 70.0)){
        admission_status = "admitted";
    }else{
        admission_status = "pending";
    }

    double scholarship_discount = 0.0;
    double scholarship_percent = 0.0;

    if (admission_status == "admitted") {
        if (jamb_score >= 320) {
            scholarship_percent = 0.30;
        } else if (jamb_score >= 280) {
            scholarship_percent = 0.20;
        } else if (jamb_score >= 240) {
            scholarship_percent = 0.10;
        } else {
            scholarship_percent = 0.0;
        }

        if (waec_avg >= 80 && first_choice_pau == true) {
            scholarship_percent += 0.05;
        }

        if (scholarship_percent > 0.35) {
            scholarship_percent = 0.35;
        }

        scholarship_discount = scholarship_percent * base_tuition;
    }

    cout<<"Which is your preferred accomodation?\n1. Main Hostel\n2. Annex Hostel\n3. Day student"<<endl;
    cin>>hostel_preference;
    
    string hostel_name;
    double hostel_fee = 0.0;

    if (admission_status == "admitted" && disciplinary_record ==0){
        if (hostel_preference == 1) {
            hostel_name = "Main Hostel";
            hostel_fee = 180000.0;
        }else if (hostel_preference == 2) {
            hostel_name = "Annex Hostel";
            hostel_fee = 120000.0;
        }else {
            hostel_name = "Day Student";
            hostel_fee = 0.0;
        }
    }else if(admission_status == "pending"){
        hostel_name = "On hold";
        hostel_fee = 0.0;
    }else if(admission_status == "rejected"){
        hostel_name = "Not apllicable";
        hostel_fee = 0.0;
    }

    int r = (rand() % 100) +1 ;
    double grant =0;
    bool isprime =(r == 2 || r == 3 || r == 5 || r == 7 || r == 11 || r == 13 || r == 17 || r == 19 || r == 23 || r == 29 || r == 31 || r == 37 || r == 41 || r == 43 || r == 47 || r == 53 || r == 59 || r == 61 || r == 67 || r == 71 || r == 73 || r == 79 || r == 83 || r == 89 || r == 97);
    if(isprime = r && admission_status == "admitted"){
        grant = 50000;
    }

    double tuition_after_schorlarship = base_tuition - scholarship_discount;
    double total_payable = tuition_after_schorlarship + hostel_fee - grant;

    if (total_payable < 0){
        total_payable = 0;
    }

    cout<<"Name: "<<name<<endl;
    cout<<"Admission status: "<<admission_status<<endl;
    cout<<"Scholarship: "<<scholarship_percent<<"\tTuition after scholarship: ₦"<<tuition_after_schorlarship<<endl;
    cout<<"Hostel:"<<hostel_name<<"\tHostel Fee: ₦"<<hostel_fee<<endl;
    cout<<"Random draw: "<<r<<"\tMerit grant: ₦"<<grant<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"TOTAL PAYABLE: ₦"<<total_payable<<endl;

    return 0;
}