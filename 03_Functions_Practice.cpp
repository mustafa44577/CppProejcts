/*
============================================================
  FILE    : 03_Functions_Practice.cpp
  TOPIC   : Functions - Lab Practice & Assignments
  STUDENT : Mustafa Javed
  SUBJECT : Programming Fundamentals (PF) - Lab Tasks
============================================================

  CONTENTS:
    Q1  - Simple void Function (print name)
    Q2  - Function with Parameters (sum)
    Q3  - Function with Return Value (add two numbers)
    Q4  - Return Larger of Two Numbers
    Q5  - Factorial using Function
    Q6  - Swap Two Numbers (pass by reference)
    Q7  - Calculator using Functions + Switch
    Q8  - Prime Number Checker Function
    Q9  - Even/Odd Checker for 7 Numbers
    Q10 - Rectangle: getLength, getWidth, getArea, displayData
    Q11 - Fibonacci using Function
    Q12 - Function Prototype (declaration before main)
    Q13 - Sum, Sub, Mul, Division Functions
    Q14 - Larger of Two (void function)
    Q15 - Area of Rectangle (function)
    Q16 - Matrix Addition using Function
    Q17 - Sum of All Matrix Elements using Function
============================================================
*/

#include <iostream>
#include <cmath>
using namespace std;

// ============================================================
//                  FUNCTION DECLARATIONS
// ============================================================

void printName();
int add(int a, int b);
int returnLarger(int a, int b);
int factorial(int num);
void swapNumbers(int &a, int &b);
double addCalc(double a, double b);
double subCalc(double a, double b);
double mulCalc(double a, double b);
double divCalc(double a, double b);
bool isPrime(int n);
bool isEven(int number);
double getLength();
double getWidth();
double getArea(double length, double width);
void displayRectangle(double length, double width, double area);
int sumMatrix(int m1[3][3], int m2[3][3]);


// ============================================================
//                       MAIN FUNCTION
// ============================================================

int main() {

    // --------------------------------------------------------
    // Q1: Simple void function - print a name
    // --------------------------------------------------------
    cout << "--- Q1: Void Function (Print Name) ---" << endl;
    printName();

    // --------------------------------------------------------
    // Q2: Function with parameters - sum
    // --------------------------------------------------------
    cout << "\n--- Q2: Sum Function ---" << endl;
    cout << "Sum of 5 + 10 = " << add(5, 10) << endl;
    cout << "Sum of 40 + 70 = " << add(40, 70) << endl;

    // --------------------------------------------------------
    // Q3: Return Larger of Two Numbers
    // --------------------------------------------------------
    cout << "\n--- Q3: Return Larger Number ---" << endl;
    cout << "Larger of 10 and 12 = " << returnLarger(10, 12) << endl;

    // --------------------------------------------------------
    // Q4: Factorial
    // --------------------------------------------------------
    cout << "\n--- Q4: Factorial ---" << endl;
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Factorial of " << num << " = " << factorial(num) << endl;

    // --------------------------------------------------------
    // Q5: Swap Numbers (Pass by Reference)
    // --------------------------------------------------------
    cout << "\n--- Q5: Swap (Pass by Reference) ---" << endl;
    int a, b;
    cout << "Enter value of a: "; cin >> a;
    cout << "Enter value of b: "; cin >> b;
    swapNumbers(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    // --------------------------------------------------------
    // Q6: Calculator using Functions + Switch + Loop
    // --------------------------------------------------------
    cout << "\n--- Q6: Calculator (4 operations) ---" << endl;
    double num1, num2;
    char option;
    for (int i = 1; i <= 4; i++) {
        cout << "Calculation " << i << ":" << endl;
        cout << "Enter first number: ";  cin >> num1;
        cout << "Enter second number: "; cin >> num2;
        cout << "Enter operation (+, -, *, /): "; cin >> option;
        switch (option) {
            case '+': cout << "Result = " << addCalc(num1, num2) << endl; break;
            case '-': cout << "Result = " << subCalc(num1, num2) << endl; break;
            case '*': cout << "Result = " << mulCalc(num1, num2) << endl; break;
            case '/': cout << "Result = " << divCalc(num1, num2) << endl; break;
            default:  cout << "Invalid operator!" << endl;
        }
    }

    // --------------------------------------------------------
    // Q7: Prime Number Checker
    // --------------------------------------------------------
    cout << "\n--- Q7: Prime Number Checker ---" << endl;
    int n;
    cout << "Enter a number: "; cin >> n;
    if (isPrime(n))
        cout << n << " is a PRIME number." << endl;
    else
        cout << n << " is NOT a prime number." << endl;

    // --------------------------------------------------------
    // Q8: Even/Odd checker for 7 numbers
    // --------------------------------------------------------
    cout << "\n--- Q8: Even/Odd for 7 Numbers ---" << endl;
    int numbers[7];
    cout << "Enter 7 integers: ";
    for (int i = 0; i < 7; i++) cin >> numbers[i];
    for (int i = 0; i < 7; i++) {
        cout << numbers[i] << " is " << (isEven(numbers[i]) ? "even" : "odd") << endl;
    }

    // --------------------------------------------------------
    // Q9: Rectangle - length, width, area, display
    // --------------------------------------------------------
    cout << "\n--- Q9: Rectangle Calculator ---" << endl;
    double length = getLength();
    double width  = getWidth();
    double area   = getArea(length, width);
    displayRectangle(length, width, area);

    // --------------------------------------------------------
    // Q10: Fibonacci Sequence using Function
    // --------------------------------------------------------
    cout << "\n--- Q10: Fibonacci Sequence ---" << endl;
    int fa = 0, fb = 1;
    cout << "Fibonacci (10 terms): ";
    for (int i = 0; i < 10; i++) {
        cout << fa << " ";
        int next = fa + fb;
        fa = fb;
        fb = next;
    }
    cout << endl;

    // --------------------------------------------------------
    // Q11: Sum two function calls chained
    // --------------------------------------------------------
    cout << "\n--- Q11: Chained Add Function Calls ---" << endl;
    int x1, x2, x3;
    cout << "Enter 3 numbers: "; cin >> x1 >> x2 >> x3;
    int res1  = add(x1, x2);
    int final = add(res1, x3);
    cout << "Sum of all 3 = " << final << endl;

    return 0;
}


// ============================================================
//               FUNCTION DEFINITIONS
// ============================================================

// Q1: Print name
void printName() {
    cout << "My name is Mustafa!" << endl;
}

// Q2: Add two integers
int add(int a, int b) {
    return a + b;
}

// Q3: Return larger of two numbers
int returnLarger(int a, int b) {
    return (a > b) ? a : b;
}

// Q4: Factorial
int factorial(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

// Q5: Swap by reference
void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Q6: Calculator helpers
double addCalc(double a, double b) { return a + b; }
double subCalc(double a, double b) { return a - b; }
double mulCalc(double a, double b) { return a * b; }
double divCalc(double a, double b) { return (b != 0) ? a / b : 0; }

// Q7: Prime checker
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Q8: Even checker
bool isEven(int number) {
    return (number % 2 == 0);
}

// Q9: Rectangle helpers
double getLength() {
    double l;
    cout << "Enter length: "; cin >> l;
    return l;
}
double getWidth() {
    double w;
    cout << "Enter width: "; cin >> w;
    return w;
}
double getArea(double length, double width) {
    return length * width;
}
void displayRectangle(double length, double width, double area) {
    cout << "\n--- Rectangle Details ---" << endl;
    cout << "Length : " << length << endl;
    cout << "Width  : " << width  << endl;
    cout << "Area   : " << area   << endl;
}

// Matrix sum helper (returns total of all elements added from both matrices)
int sumMatrix(int m1[3][3], int m2[3][3]) {
    int total = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            total += m1[i][j] + m2[i][j];
    return total;
}
