/*
============================================================
  FILE    : 06_Assignments_Conditionals_Loops.cpp
  TOPIC   : Assignments 1-7 (Variables, If/Else, Loops, Arrays)
  STUDENT : Mustafa Javed
  SUBJECT : Programming Fundamentals (PF) - Theory Tasks
============================================================

  CONTENTS:
    --- ASSIGNMENT 1: Basic Arithmetic & Variables ---
    P1  - Food Order Bill Calculator
    P2  - Car Mileage Calculator
    P3  - Hotel Bill Calculator
    P4  - Quadratic Equation Solver (roots)
    P5  - Triangle Area using Heron's Formula
    P6  - Trapezoid Area
    P7  - Volume of Box, Prism, Cylinder, Sphere
    P8  - Distance Between Points + Triangle Area

    --- ASSIGNMENT 2 & 3: Conditionals (if/else, switch) ---
    P1  - Sort 3 Numbers in Ascending Order
    P2  - Age Category (Kid, Teen, Adult)
    P3  - Even or Odd
    P4  - Vowel or Consonant
    P5  - Palindrome String Check
    P6  - Toggle Case (upper <-> lower)
    P7  - Population Statistics (literacy rates)
    P8  - Insurance Premium Calculator
    P9  - Calories Calculator based on Lifestyle
    P10 - Assignment Menu System (switch + loop)

    --- ASSIGNMENT 6 & 7: Arrays (vector) ---
    V1  - Add Elements to Vector
    V2  - Merge Two Vectors
    V3  - Add Elements of Two Vectors
    V4  - Smallest Frequent Element
    V5  - Most Frequent in Vector
    V6  - Reverse a Vector
    V7  - Sort Vector (Bubble Sort)
    V8  - Palindrome Array Check
    V9  - Rotate Array Left
    V10 - Separate Even/Odd Index Elements
============================================================
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


int main() {

    // ========================================================
    //       ASSIGNMENT 1: ARITHMETIC & VARIABLES
    // ========================================================

    // --------------------------------------------------------
    // P1: Food Order Bill Calculator
    // --------------------------------------------------------
    cout << "--- P1: Food Order Bill Calculator ---" << endl;
    int burger = 500, pizza = 400, sharwama = 300, fries = 150, drink = 100;
    int burgerQTY, pizzaQTY, sharwamaQTY, friesQTY, drinkQTY;

    cout << "Prices: Burger=" << burger << " Pizza=" << pizza
         << " Sharwama=" << sharwama << " Fries=" << fries << " Drink=" << drink << endl;
    cout << "Enter quantities (burger pizza sharwama fries drink): ";
    cin  >> burgerQTY >> pizzaQTY >> sharwamaQTY >> friesQTY >> drinkQTY;

    int burgerTotal  = burger  * burgerQTY;
    int pizzaTotal   = pizza   * pizzaQTY;
    int sharwamaTotal= sharwama* sharwamaQTY;
    int friesTotal   = fries   * friesQTY;
    int drinkTotal   = drink   * drinkQTY;
    int subtotal     = burgerTotal + pizzaTotal + sharwamaTotal + friesTotal + drinkTotal;
    double taxSale   = subtotal * 0.16;
    double totalBill = subtotal + taxSale;

    cout << "Subtotal   = " << subtotal   << endl;
    cout << "Tax (16%)  = " << taxSale    << endl;
    cout << "Total Bill = " << totalBill  << endl;

    // --------------------------------------------------------
    // P2: Car Mileage Calculator
    // --------------------------------------------------------
    cout << "\n--- P2: Car Mileage ---" << endl;
    double miles = 324, gas = 17;
    cout << "Distance = " << miles << " miles, Gas = " << gas << " gallons" << endl;
    cout << "Car mileage = " << miles / gas << " mpg" << endl;

    // --------------------------------------------------------
    // P3: Hotel Bill
    // --------------------------------------------------------
    cout << "\n--- P3: Hotel Bill ---" << endl;
    int nightRate, stayed, roomService, telUse;
    cout << "Night rate: ";   cin >> nightRate;
    cout << "Nights stayed: "; cin >> stayed;
    cout << "Room service: ";  cin >> roomService;
    cout << "Telephone: ";    cin >> telUse;
    int hotelBill = (nightRate * stayed) + (roomService + telUse);
    cout << "Total hotel bill = " << hotelBill << endl;

    // --------------------------------------------------------
    // P4: Quadratic Equation Solver
    // --------------------------------------------------------
    cout << "\n--- P4: Quadratic Equation Solver ---" << endl;
    double qa, qb, qc;
    cout << "Enter coefficients a b c: "; cin >> qa >> qb >> qc;
    if (qa == 0) {
        cout << "a cannot be zero!" << endl;
    } else {
        double discriminant = qb * qb - 4 * qa * qc;
        if (discriminant > 0) {
            double d = sqrt(discriminant);
            cout << "Two real roots: " << (-qb + d) / (2 * qa)
                 << " and " << (-qb - d) / (2 * qa) << endl;
        } else if (discriminant == 0) {
            cout << "One real root: " << -qb / (2 * qa) << endl;
        } else {
            double real = -qb / (2 * qa);
            double imag = sqrt(-discriminant) / (2 * qa);
            cout << "Complex roots: " << real << " + " << imag << "i"
                 << " and " << real << " - " << imag << "i" << endl;
        }
    }

    // --------------------------------------------------------
    // P5: Triangle Area (Heron's Formula)
    // --------------------------------------------------------
    cout << "\n--- P5: Triangle Area (Heron's Formula) ---" << endl;
    double s1, s2, s3;
    cout << "Enter 3 sides: "; cin >> s1 >> s2 >> s3;
    double p = (s1 + s2 + s3) / 2;
    double triArea = sqrt(p * (p - s1) * (p - s2) * (p - s3));
    cout << "Triangle area = " << triArea << endl;

    // --------------------------------------------------------
    // P6: Trapezoid Area
    // --------------------------------------------------------
    cout << "\n--- P6: Trapezoid Area ---" << endl;
    int tb1, tb2, theight;
    cout << "Enter base1 base2 height: "; cin >> tb1 >> tb2 >> theight;
    cout << "Trapezoid area = " << (tb1 + tb2) * theight / 2.0 << endl;

    // --------------------------------------------------------
    // P8: Distance Between Two Points + Triangle Area
    // --------------------------------------------------------
    cout << "\n--- P8: Distance Between Points ---" << endl;
    double x1=5, y1=4, x2=10, y2=12, x3=9, y3=8;
    double dAB = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    double dAC = sqrt(pow(x3-x1,2) + pow(y3-y1,2));
    double dBC = sqrt(pow(x3-x2,2) + pow(y3-y2,2));
    double sp  = (dAB + dAC + dBC) / 2;
    double tArea = sqrt(sp * (sp-dAB) * (sp-dAC) * (sp-dBC));
    cout << "AB = " << dAB << ", AC = " << dAC << ", BC = " << dBC << endl;
    cout << "Triangle area = " << tArea << endl;


    // ========================================================
    //    ASSIGNMENT 2 & 3: CONDITIONALS
    // ========================================================

    // --------------------------------------------------------
    // P1: Sort 3 Numbers (Ascending)
    // --------------------------------------------------------
    cout << "\n--- Sort 3 Numbers Ascending ---" << endl;
    int sA, sB, sC;
    cout << "Enter 3 numbers: "; cin >> sA >> sB >> sC;
    if (sA > sB) swap(sA, sB);
    if (sA > sC) swap(sA, sC);
    if (sB > sC) swap(sB, sC);
    cout << "Sorted: " << sA << " " << sB << " " << sC << endl;

    // --------------------------------------------------------
    // P2: Age Category
    // --------------------------------------------------------
    cout << "\n--- Age Category ---" << endl;
    int age;
    cout << "Enter age: "; cin >> age;
    if      (age >= 0  && age <= 12) cout << "Kid"        << endl;
    else if (age >= 13 && age <= 19) cout << "Teenager"   << endl;
    else if (age >= 20 && age <= 30) cout << "Young Adult" << endl;
    else                             cout << "Adult"       << endl;

    // --------------------------------------------------------
    // P3: Even or Odd
    // --------------------------------------------------------
    cout << "\n--- Even or Odd ---" << endl;
    int checkNum;
    cout << "Enter a number: "; cin >> checkNum;
    cout << checkNum << " is " << (checkNum % 2 == 0 ? "even" : "odd") << endl;

    // --------------------------------------------------------
    // P4: Vowel or Consonant
    // --------------------------------------------------------
    cout << "\n--- Vowel or Consonant ---" << endl;
    char alpha;
    cout << "Enter a letter: "; cin >> alpha;
    if (alpha=='a'||alpha=='e'||alpha=='i'||alpha=='o'||alpha=='u'||
        alpha=='A'||alpha=='E'||alpha=='I'||alpha=='O'||alpha=='U')
        cout << alpha << " is a VOWEL"     << endl;
    else
        cout << alpha << " is a CONSONANT" << endl;

    // --------------------------------------------------------
    // P5: Palindrome String Check
    // --------------------------------------------------------
    cout << "\n--- Palindrome Check ---" << endl;
    string palStr;
    cout << "Enter a word: "; cin >> palStr;
    int pn = palStr.length();
    bool isPalin = true;
    for (int i = 0; i < pn / 2; i++) {
        if (palStr[i] != palStr[pn - i - 1]) { isPalin = false; break; }
    }
    cout << palStr << " is " << (isPalin ? "" : "NOT ") << "a palindrome." << endl;

    // --------------------------------------------------------
    // P6: Toggle Case
    // --------------------------------------------------------
    cout << "\n--- Toggle Case ---" << endl;
    char arr[30];
    cout << "Enter a sentence: "; cin.ignore(); cin.getline(arr, 30);
    for (int i = 0; arr[i] != 0; i++) {
        if      (arr[i] >= 'A' && arr[i] <= 'Z') arr[i] += 32;
        else if (arr[i] >= 'a' && arr[i] <= 'z') arr[i] -= 32;
    }
    cout << "Toggled: " << arr << endl;

    // --------------------------------------------------------
    // P9: Calories Calculator
    // --------------------------------------------------------
    cout << "\n--- Calories Calculator ---" << endl;
    float weight;
    char lifestyle;
    float calories = 0;
    cout << "Enter weight (kg): "; cin >> weight;
    cout << "Lifestyle (A=Active, S=Sedentary): "; cin >> lifestyle;
    if      (lifestyle == 'A' || lifestyle == 'a') calories = weight * 15;
    else if (lifestyle == 'S' || lifestyle == 's') calories = weight * 13;
    else { cout << "Invalid lifestyle input." << endl; return 1; }
    cout << "Daily calories needed = " << calories << endl;


    // ========================================================
    //    ASSIGNMENT 6 & 7: ARRAYS (VECTOR)
    // ========================================================

    // --------------------------------------------------------
    // V1: Add Elements to a Vector
    // --------------------------------------------------------
    cout << "\n--- V1: Add Elements to Vector ---" << endl;
    vector<string> cars = {"BMW", "HONDA", "TOYOTA", "FORD"};
    cars.push_back("TESLA");
    cars[0] = "LAMBO";
    for (string car : cars) cout << car << endl;

    // --------------------------------------------------------
    // V2: Merge Two Vectors
    // --------------------------------------------------------
    cout << "\n--- V2: Merge Two Vectors ---" << endl;
    vector<string> cars1 = {"bmw", "honda"};
    vector<string> cars2 = {"audi", "toyota"};
    cars1.insert(cars1.end(), cars2.begin(), cars2.end());
    for (string car : cars1) cout << car << " ";
    cout << endl;

    // --------------------------------------------------------
    // V3: Add Elements of Two Vectors (element-wise)
    // --------------------------------------------------------
    cout << "\n--- V3: Element-wise Addition ---" << endl;
    vector<int> n1 = {10, 20, 30};
    vector<int> n2 = {40, 50, 60};
    cout << "Sum: ";
    for (int i = 0; i < 3; i++) cout << n1[i] + n2[i] << " ";
    cout << endl;

    // --------------------------------------------------------
    // V4: Smallest Element
    // --------------------------------------------------------
    cout << "\n--- V4: Smallest Element ---" << endl;
    vector<int> v4 = {7, 2, 3, 1, 5, 6};
    int minFreq = v4[0];
    for (int val : v4) if (val < minFreq) minFreq = val;
    cout << "Smallest = " << minFreq << endl;

    // --------------------------------------------------------
    // V5: Most Frequent Element
    // --------------------------------------------------------
    cout << "\n--- V5: Most Frequent Element ---" << endl;
    vector<int> v5 = {1, 2, 3, 2};
    int frequent = v5[0], maxCnt = 0;
    int vn = v5.size();
    for (int i = 0; i < vn; i++) {
        int count = 0;
        for (int j = 0; j < vn; j++) if (v5[j] == v5[i]) count++;
        if (count > maxCnt) { maxCnt = count; frequent = v5[i]; }
    }
    cout << "Most frequent = " << frequent << endl;

    // --------------------------------------------------------
    // V6: Reverse a Vector
    // --------------------------------------------------------
    cout << "\n--- V6: Reverse Vector ---" << endl;
    vector<int> v6 = {1, 2, 3, 4, 5};
    int vn6 = v6.size();
    for (int i = 0; i < vn6 / 2; i++) {
        int temp        = v6[i];
        v6[i]           = v6[vn6 - i - 1];
        v6[vn6 - i - 1] = temp;
    }
    for (int val : v6) cout << val << " ";
    cout << endl;

    // --------------------------------------------------------
    // V7: Bubble Sort
    // --------------------------------------------------------
    cout << "\n--- V7: Bubble Sort ---" << endl;
    vector<int> v7 = {3, 1, 0, -4, -5, 3};
    int vn7 = v7.size();
    for (int i = 0; i < vn7; i++)
        for (int j = 0; j < vn7 - i - 1; j++)
            if (v7[j] > v7[j+1]) swap(v7[j], v7[j+1]);
    for (int val : v7) cout << val << " ";
    cout << endl;

    // --------------------------------------------------------
    // V8: Rotate Array Left by 1
    // --------------------------------------------------------
    cout << "\n--- V8: Rotate Left ---" << endl;
    vector<int> v8 = {1, 2, 3, 4, 5};
    int first = v8[0];
    for (int i = 1; i < (int)v8.size(); i++) v8[i-1] = v8[i];
    v8[v8.size()-1] = first;
    for (int val : v8) cout << val << " ";
    cout << endl;

    // --------------------------------------------------------
    // V9: Separate Even/Odd Index Elements
    // --------------------------------------------------------
    cout << "\n--- V9: Even then Odd Indices ---" << endl;
    vector<int> v9 = {3, 2, 4, 5};
    vector<int> result9;
    for (int i = 0; i < (int)v9.size(); i++) if (i % 2 == 0) result9.push_back(v9[i]);
    for (int i = 0; i < (int)v9.size(); i++) if (i % 2 != 0) result9.push_back(v9[i]);
    for (int val : result9) cout << val << " ";
    cout << endl;

    return 0;
}
