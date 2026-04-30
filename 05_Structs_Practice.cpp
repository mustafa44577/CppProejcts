/*
============================================================
  FILE    : 05_Structs_Practice.cpp
  TOPIC   : Structures (struct) - Lab Practice
  STUDENT : Mustafa Javed
  SUBJECT : Programming Fundamentals (PF) - Lab Tasks
============================================================

  CONTENTS:
    Project - Contact/Address Book System using struct
              - Add Contact
              - Display All Contacts
              - Search Contact by Name
              - Delete Contact by Name
    Q2 - Circle Area using struct
    Q3 - Basic struct example (named fields)
============================================================
*/

#include <iostream>
#include <string>
using namespace std;

// ============================================================
//           ADDRESS BOOK - STRUCT DEFINITION
// ============================================================

const int MAX = 100;

struct Contact {
    string name;
    string phone_number;
    string email;
    string address;
};

// Global array of contacts and count
Contact contacts[MAX];
int total_contacts = 0;


// ============================================================
//              FUNCTION DECLARATIONS
// ============================================================
void addContact();
void displayContacts();
void searchContact(string searchName);
void deleteContact(string deleteName);


// ============================================================
//                       MAIN
// ============================================================
int main() {
    int choice;
    string name;

    cout << "======================================" << endl;
    cout << "       ADDRESS BOOK SYSTEM            " << endl;
    cout << "======================================" << endl;

    while (true) {
        cout << "\n1. Add Contact"    << endl;
        cout << "2. Display All"     << endl;
        cout << "3. Search Contact"  << endl;
        cout << "4. Delete Contact"  << endl;
        cout << "5. Exit"            << endl;
        cout << "Enter your choice: ";
        cin  >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                cout << "Enter name to search: ";
                cin  >> name;
                searchContact(name);
                break;
            case 4:
                cout << "Enter name to delete: ";
                cin  >> name;
                deleteContact(name);
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}


// ============================================================
//              FUNCTION DEFINITIONS
// ============================================================

// Add a new contact
void addContact() {
    if (total_contacts >= MAX) {
        cout << "Address book is full!" << endl;
        return;
    }

    cout << "\n--- Add New Contact ---" << endl;
    cout << "Name: ";
    cin  >> contacts[total_contacts].name;

    // Validate phone number (must be 11 digits)
    while (true) {
        cout << "Phone (11 digits): ";
        cin  >> contacts[total_contacts].phone_number;
        if (contacts[total_contacts].phone_number.length() != 11) {
            cout << "Invalid! Phone number must be exactly 11 digits." << endl;
        } else {
            break;
        }
    }

    cout << "Email: ";
    cin  >> contacts[total_contacts].email;
    cout << "Address: ";
    cin  >> contacts[total_contacts].address;

    total_contacts++;
    cout << "Contact added successfully!" << endl;
}

// Display all contacts
void displayContacts() {
    if (total_contacts == 0) {
        cout << "Address book is empty." << endl;
        return;
    }
    cout << "\n--- All Contacts ---" << endl;
    for (int i = 0; i < total_contacts; i++) {
        cout << "Contact " << i + 1 << ":" << endl;
        cout << "  Name    : " << contacts[i].name         << endl;
        cout << "  Phone   : " << contacts[i].phone_number << endl;
        cout << "  Email   : " << contacts[i].email        << endl;
        cout << "  Address : " << contacts[i].address      << endl;
    }
}

// Search contact by name
void searchContact(string searchName) {
    for (int i = 0; i < total_contacts; i++) {
        if (contacts[i].name == searchName) {
            cout << "\n--- Contact Found ---" << endl;
            cout << "  Name    : " << contacts[i].name         << endl;
            cout << "  Phone   : " << contacts[i].phone_number << endl;
            cout << "  Email   : " << contacts[i].email        << endl;
            cout << "  Address : " << contacts[i].address      << endl;
            return;
        }
    }
    cout << "Contact not found." << endl;
}

// Delete contact by name
void deleteContact(string deleteName) {
    for (int i = 0; i < total_contacts; i++) {
        if (contacts[i].name == deleteName) {
            // Shift all elements left to fill the gap
            for (int j = i; j < total_contacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            total_contacts--;
            cout << "Contact deleted successfully." << endl;
            return;
        }
    }
    cout << "Contact not found." << endl;
}
