//ATM Simulator

#include <iostream>
#include <string>
#include <limits>
#include <iomanip> // For currency formatting

using namespace std;

// Function Prototypes as specified in the question
bool verifyPin(int correctPin);
void displayMenu();
double viewBalance(double balance);
double depositMoney(double balance);
double withdrawMoney(double balance, double daily_withdrawal_limit);
int resetPin(int current_pin);

int main() {
    double balance = 50000.00;
    double daily_withdrawal_limit = 20000.00;
    int current_pin = 4321;
    
    if (verifyPin(current_pin) == false) {
        cout << "\nAccount Locked. Please contact your bank." << endl; 
        return 0; 
    }

    int choice;
    do {
        displayMenu(); 
        
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number: "<<endl;
            cin.clear();
            cin.ignore();
        }

        switch (choice) {
            case 1:
                viewBalance(balance); 
                break;
            case 2:
                balance = depositMoney(balance); 
                break;
            case 3:
                balance = withdrawMoney(balance, daily_withdrawal_limit); 
                break;
            case 4:
                current_pin = resetPin(current_pin); 
                break;
            case 5:
                cout << "Thank you for using our ATM." << endl; 
                break;
            default:
                cout << "Invalid selection. Please try again." << endl;
        }

    } while (choice != 5); 

    return 0;
}

bool verifyPin(int correctPin) {
    int attempts = 0;
    int inputPin;

    while (attempts < 3) {
        cout << "Enter your PIN: ";
        cin >> inputPin;

        if (inputPin == correctPin) {
            return true; 
        } else {
            cout << "Incorrect PIN." << endl;
            attempts++;
        }
    }
    return false;
}

void displayMenu() {
    cout << "\n======== ATM MENU ========" << endl; 
    cout << "1. View Balance" << endl;
    cout << "2. Deposit Cash" << endl;
    cout << "3. Withdraw Cash" << endl;
    cout << "4. Reset PIN" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: "; 
}


double viewBalance(double balance) {
    cout << fixed << setprecision(2);
    cout << "\n---------------------------------" << endl;
    cout << "Current Balance: N " << balance << endl;
    return balance;
}

double depositMoney(double balance) {
    double amount;
    cout << "Enter amount to deposit: N ";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful. New Balance: N " << fixed << setprecision(2) << balance << endl;
    } else {
        cout << "Invalid amount. Deposit must be positive." << endl;
    }
    return balance;
}

double withdrawMoney(double balance, double daily_withdrawal_limit) {
    double amount;
    cout << "Enter amount to withdraw: N ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount." << endl;
        return balance;
    }

    if (amount > balance) {
        cout << "Transaction Failed: Insufficient funds." << endl;
    } 
    else if (amount > daily_withdrawal_limit) {
        cout << "Transaction Failed: Amount exceeds daily withdrawal limit of N " << daily_withdrawal_limit << endl;
    } 
    else {
        balance -= amount;
        cout << "Please take your cash." << endl;
        cout << "New Balance: N " << fixed << setprecision(2) << balance << endl;
    }
    return balance;
}