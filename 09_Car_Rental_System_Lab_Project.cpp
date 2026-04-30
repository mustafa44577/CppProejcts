/*
============================================================
  FILE    : 09_Car_Rental_System_Lab_Project.cpp
  TOPIC   : Lab Project - Car Rental System (Customer Panel)
  STUDENT : Mustafa Javed (f2024266018)
  SUBJECT : Programming Fundamentals (PF) - Lab Project
============================================================

  FEATURES:
    - Add Car (Admin side - numeric ID, letters-only brand)
    - View Available Cars
    - Customer: Request Car for Rent
    - Input validation for Car ID (numeric only, no duplicate)
    - Input validation for Brand (letters only)

  NOTE:
    This is the lab project version with a Customer Panel.
    See 10_Car_Rental_System_Theory_Project.cpp for the full
    theory version with Manager Login and Invoice.
============================================================
*/

#include <iostream>
#include <string>
using namespace std;

// ============================================================
//              GLOBAL ARRAYS (Car Data)
// ============================================================
string carID[100];
string brand[100];
string carModel[100];
bool   isRented[100];
string customerName[100];
string customerContact[100];
double hourlyRate[100];
double rentedAmount[100];
int    carCount = 0;

// Rent Requests
string renterNames[100];
string renterContacts[100];
string requestedCarIDs[100];
int    rentRequestCount = 0;


// ============================================================
//          FUNCTION DECLARATIONS
// ============================================================
void addCar();
void displayAvailableCars();
void rentCar();
void customerPanel();


// ============================================================
//                    MAIN
// ============================================================
int main() {
    int choice;

    cout << "======================================" << endl;
    cout << "     CAR RENTAL SYSTEM                " << endl;
    cout << "======================================" << endl;

    do {
        cout << "\n=== Main Menu ===" << endl;
        cout << "1. Customer Panel" << endl;
        cout << "2. Add a Car (Admin)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: "; cin >> choice;

        switch (choice) {
            case 1:
                customerPanel();
                break;
            case 2:
                addCar();
                break;
            case 3:
                cout << "Exiting system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 3);

    return 0;
}


// ============================================================
//          FUNCTION DEFINITIONS
// ============================================================

// Add a car with validated ID and brand
void addCar() {
    string id, carBrand, model;
    double rate;

    // --- Validate Car ID: must be numeric & unique ---
    bool isValidID = false;
    while (!isValidID) {
        cout << "Enter Car ID (numeric): "; cin >> id;

        bool isNumeric = true;
        for (int i = 0; i < (int)id.length(); i++) {
            if (id[i] < '0' || id[i] > '9') { isNumeric = false; break; }
        }
        bool isDuplicate = false;
        for (int i = 0; i < carCount; i++) {
            if (carID[i] == id) { isDuplicate = true; break; }
        }

        if (!isNumeric)    cout << "Invalid! ID must be numeric only."   << endl;
        else if (isDuplicate) cout << "Error: Car ID already exists."    << endl;
        else               isValidID = true;
    }

    // --- Validate Brand: letters only ---
    bool isValidBrand = false;
    while (!isValidBrand) {
        cout << "Enter Car Brand: "; cin >> carBrand;
        bool isLetters = true;
        for (int i = 0; i < (int)carBrand.length(); i++) {
            if (!((carBrand[i] >= 'A' && carBrand[i] <= 'Z') ||
                  (carBrand[i] >= 'a' && carBrand[i] <= 'z'))) {
                isLetters = false;
                break;
            }
        }
        if (!isLetters) cout << "Invalid! Brand must contain letters only." << endl;
        else            isValidBrand = true;
    }

    cout << "Enter Car Model: ";         cin >> model;
    cout << "Enter Hourly Rental Rate: "; cin >> rate;

    // Store car data
    carID[carCount]        = id;
    brand[carCount]        = carBrand;
    carModel[carCount]     = model;
    isRented[carCount]     = false;
    hourlyRate[carCount]   = rate;
    rentedAmount[carCount] = 0;
    carCount++;

    cout << "Car added successfully!" << endl;
}

// Display all available (not rented) cars
void displayAvailableCars() {
    cout << "\n--- Available Cars ---" << endl;
    bool anyAvailable = false;
    for (int i = 0; i < carCount; i++) {
        if (!isRented[i]) {
            cout << "ID: " << carID[i]
                 << " | Brand: "  << brand[i]
                 << " | Model: "  << carModel[i]
                 << " | Rate: Rs." << hourlyRate[i] << "/hr" << endl;
            anyAvailable = true;
        }
    }
    if (!anyAvailable) cout << "No cars available right now." << endl;
}

// Customer requests to rent a car
void rentCar() {
    string id, customer, contact;
    cout << "Enter Car ID to rent: "; cin >> id;

    for (int i = 0; i < carCount; i++) {
        if (carID[i] == id) {
            if (!isRented[i]) {
                cout << "Enter your name: ";    cin >> customer;
                cout << "Enter your contact: "; cin >> contact;

                renterNames[rentRequestCount]    = customer;
                renterContacts[rentRequestCount] = contact;
                requestedCarIDs[rentRequestCount]= id;
                rentRequestCount++;

                cout << "Rent request submitted! Awaiting admin approval." << endl;
            } else {
                cout << "Sorry, this car is already rented." << endl;
            }
            return;
        }
    }
    cout << "Car ID not found." << endl;
}

// Customer Panel menu
void customerPanel() {
    int choice;
    do {
        cout << "\n====== Customer Panel ======" << endl;
        cout << "1. View Available Cars"         << endl;
        cout << "2. Request a Car for Rent"      << endl;
        cout << "3. Back to Main Menu"           << endl;
        cout << "Enter choice: "; cin >> choice;

        switch (choice) {
            case 1: displayAvailableCars(); break;
            case 2: rentCar();              break;
            case 3: cout << "Returning to main menu." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 3);
}
