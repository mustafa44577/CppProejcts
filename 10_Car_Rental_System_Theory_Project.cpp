/*
============================================================
  FILE    : 10_Car_Rental_System_Theory_Project.cpp
  TOPIC   : Theory Project - Full Car Rental System
  STUDENT : Mustafa Javed
  SUBJECT : Programming Fundamentals (PF) - Theory Project
============================================================

  FEATURES:
    - Manager Login (username + password protected)
    - User Login
    - Display All Available Cars
    - Rent a Car (with invoice)
    - Return a Car (with invoice)
    - Add a New Car (with duplicate check)
    - Logout & Re-login option
    - Dynamic car count (carnums variable)
============================================================
*/

#include <iostream>
#include <string>
using namespace std;

// ============================================================
//          FUNCTION DECLARATIONS
// ============================================================
void login();


// ============================================================
//                    LOGIN FUNCTION
// ============================================================
void login() {
    string managerName, managerPassword, userName, userPassword;
    const string CORRECT_NAME     = "MANAGER";
    const string CORRECT_PASSWORD = "1234";

    cout << "\n========================================" << endl;
    cout << "     WELCOME TO CAR RENTAL SYSTEM       " << endl;
    cout << "========================================" << endl;

    // Manager login loop
    while (true) {
        cout << "\n--- Manager Login ---" << endl;
        cout << "Manager Name: ";     cin >> managerName;
        cout << "Manager Password: "; cin >> managerPassword;

        if (managerName == CORRECT_NAME && managerPassword == CORRECT_PASSWORD) {
            cout << "Manager login successful!" << endl;
            break;
        } else {
            cout << "Login failed! Please try again." << endl;
        }
    }

    // User login (no validation needed for this version)
    cout << "\n--- User Login ---" << endl;
    cout << "Username: "; cin >> userName;
    cout << "Password: "; cin >> userPassword;
    cout << "Login successful! Welcome, " << userName << "!" << endl;
}


// ============================================================
//                    MAIN
// ============================================================
int main() {
    login();

    // Car database arrays
    string car[100]   = {"BMW", "HONDA", "TOYOTA", "MERCEDES"};
    int    model[100] = {2003, 2004, 2006, 2007};
    string color[100] = {"RED", "BLUE", "GREEN", "YELLOW"};
    int    carnums    = 4;  // current number of cars

    int    userChoice, userCarChoice;
    int    days, amountAdvanced, rent;
    double totalPayment;

    cout << "\n======= MENU =======" << endl;
    cout << "1. Display All Cars"    << endl;
    cout << "2. Rent a Car"          << endl;
    cout << "3. Return a Car"        << endl;
    cout << "4. Add a New Car"       << endl;
    cout << "5. Exit / Re-login"     << endl;

    while (true) {
        cout << "\nEnter choice (1-5): "; cin >> userChoice;

        switch (userChoice) {

            // --------------------------------------------------
            // Case 1: Display All Available Cars
            // --------------------------------------------------
            case 1:
                cout << "\n--- Available Cars ---" << endl;
                for (int i = 0; i < carnums; i++) {
                    cout << i << ". " << car[i]
                         << " | Model: " << model[i]
                         << " | Color: " << color[i] << endl;
                }
                break;

            // --------------------------------------------------
            // Case 2: Rent a Car
            // --------------------------------------------------
            case 2:
                cout << "\n--- Rent a Car ---" << endl;
                for (int i = 0; i < carnums; i++) {
                    cout << i << ". " << car[i] << endl;
                }
                cout << "Select car (0-" << carnums - 1 << "): "; cin >> userCarChoice;

                if (userCarChoice >= 0 && userCarChoice < carnums) {
                    cout << "Car: "   << car[userCarChoice]   << endl;
                    cout << "Model: " << model[userCarChoice] << endl;
                    cout << "Color: " << color[userCarChoice] << endl;

                    cout << "Days needed: ";          cin >> days;
                    cout << "Advance payment (Rs.): "; cin >> amountAdvanced;
                    cout << "Rent per day (Rs.): ";   cin >> rent;

                    totalPayment = (days * rent) - amountAdvanced;

                    cout << "\n----- INVOICE -----"           << endl;
                    cout << "Car Name   : " << car[userCarChoice]   << endl;
                    cout << "Model Year : " << model[userCarChoice] << endl;
                    cout << "Color      : " << color[userCarChoice] << endl;
                    cout << "Days       : " << days                 << endl;
                    cout << "Rent/Day   : " << rent                 << endl;
                    cout << "Advance    : " << amountAdvanced       << endl;
                    cout << "Total Due  : Rs." << totalPayment      << endl;
                    cout << "-------------------"                   << endl;
                } else {
                    cout << "Invalid selection!" << endl;
                }
                break;

            // --------------------------------------------------
            // Case 3: Return a Car
            // --------------------------------------------------
            case 3:
                cout << "\n--- Return a Car ---" << endl;
                for (int i = 0; i < carnums; i++) {
                    cout << i << ". " << car[i] << endl;
                }
                cout << "Select car to return (0-" << carnums - 1 << "): "; cin >> userCarChoice;

                if (userCarChoice >= 0 && userCarChoice < carnums) {
                    cout << "Car: "   << car[userCarChoice]   << endl;
                    cout << "Model: " << model[userCarChoice] << endl;
                    cout << "Color: " << color[userCarChoice] << endl;

                    cout << "Days rented: ";  cin >> days;
                    cout << "Rent per day: "; cin >> rent;

                    cout << "\n--- Car Returned Successfully ---" << endl;
                    cout << "\n----- INVOICE -----"              << endl;
                    cout << "Car Name   : " << car[userCarChoice]   << endl;
                    cout << "Model Year : " << model[userCarChoice] << endl;
                    cout << "Color      : " << color[userCarChoice] << endl;
                    cout << "Days       : " << days                 << endl;
                    cout << "Rent/Day   : " << rent                 << endl;
                    cout << "Total Paid : Rs." << rent * days       << endl;
                    cout << "-------------------"                   << endl;
                } else {
                    cout << "Invalid selection!" << endl;
                }
                break;

            // --------------------------------------------------
            // Case 4: Add a New Car
            // --------------------------------------------------
            case 4: {
                string newCar, newColor;
                int    newModel, addFee;
                bool   carExists = false;

                cout << "\n--- Add New Car ---" << endl;
                cout << "Car Name: ";  cin >> newCar;
                cout << "Model Year: "; cin >> newModel;
                cout << "Color: ";    cin >> newColor;

                // Check for duplicate
                for (int i = 0; i < carnums; i++) {
                    if (car[i] == newCar && model[i] == newModel && color[i] == newColor) {
                        carExists = true;
                        break;
                    }
                }
                if (carExists) {
                    cout << "This car already exists in the system!" << endl;
                    break;
                }

                cout << "Rent per day: "; cin >> rent;
                cout << "Addition fee: "; cin >> addFee;

                if (carnums < 100) {
                    car[carnums]   = newCar;
                    model[carnums] = newModel;
                    color[carnums] = newColor;
                    carnums++;

                    cout << "\n--- New Car Added ---"   << endl;
                    cout << "----- INVOICE -----"       << endl;
                    cout << "Car Name   : " << newCar   << endl;
                    cout << "Model Year : " << newModel  << endl;
                    cout << "Color      : " << newColor  << endl;
                    cout << "Rent/Day   : " << rent      << endl;
                    cout << "Add Fee    : Rs." << addFee << endl;
                    cout << "-------------------"        << endl;
                } else {
                    cout << "Cannot add more cars. Array is full!" << endl;
                }
                break;
            }

            // --------------------------------------------------
            // Case 5: Exit / Re-login
            // --------------------------------------------------
            case 5:
                cout << "Logging out..." << endl;
                login();
                break;

            default:
                cout << "Invalid option! Please try again." << endl;
                break;
        }
    }

    return 0;
}
