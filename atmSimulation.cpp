#include<iostream>
#include<cstdlib>
using namespace std;

int balance = 1000;

void checkBalance(){
    cout << "Your current Balance is : " << balance << endl;
}

void depositMoney(){
    int amount ;
    cout << "Enter the amount : " << endl;
    cin>> amount;
    if (amount >0){
        balance += amount;
        cout << "You have deposited Rs. "<< amount << "\nYour current balance is : Rs. " << balance << endl;
    }
    else {
        cout << "Invalid amount !!! "<< endl;
    }
    

}

void withdrawMoney(){
    int amount;
    cout << "Enter the amount : "<< endl;
    cin>> amount;
    if (amount > 0 && amount <= balance){
        balance -= amount;
    cout << "Withdrawn amount is Rs. "<< amount << "\n Your current balance : Rs. "<< balance << endl;
    }
    else if (amount > balance) {
        cout << "Insufficient balance !!!" << endl;
    }
    else{
        cout << "Invalid amount !!! "<< endl;
    } 
    
}

void displayMenu(){
    cout << "ATM Menu:" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Logout" << endl;
    cout << "5. Exit" << endl;
}

void pinVerify(){
    int pin = 1234;
    int count =1;
    int PIN;
    while (true){
        cout << "Enter 4 digit atm pin : "<< endl;
        cin >> PIN;
        if (pin == PIN) break;
        else if (count == 3) {
            cout << "Maximum limit of wrong attempt reached!!! \n Try again later. \n Exiting The Program..."<< endl;
            exit(0);
        }
        else {
            cout << "Entered Wrong Pin!!! Retry... "<< endl;
            count ++;
        }
    }
    cout << "Pin verified successfully!!! \n"<< endl;

    int choice;
    do{
        cout << "################### ATM SIMULATION ####################" << endl;
        displayMenu();
        cout << "Enter your choice : "<< endl;
        cin>> choice ;

        switch(choice){
            case 1:
            checkBalance(); break;
            case 2:
            depositMoney(); break;
            case 3: 
            withdrawMoney(); break;
            case 4:
            cout << "Logging out... Thankyou"<< endl;
            pinVerify(); break;
            case 5:
            cout << "Exiting... Thankyou"<< endl; break;
            default : cout << "Invalid choice \n";
        }
    }
    while(choice != 5);
}

int main(){
    pinVerify();
    
    return 0;
}