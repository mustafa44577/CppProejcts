/*
============================================================
  FILE    : 07_Mid_Exam_Practice.cpp
  TOPIC   : Mid Exam Practice - Mixed Topics
  STUDENT : Mustafa Javed
  SUBJECT : Programming Fundamentals (PF) - Mid Exam
============================================================

  CONTENTS:
    Q1 - Statistics of Positive Integers
         (count, max, min, average, even/odd count, sum of squares)
    Q2 - Factorial using loop + pow()
    Q3 - Math Series using loops (e^x approximation)
    Q4 - Age & License Eligibility (nested if)
============================================================
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    // --------------------------------------------------------
    // Q1: Statistics of Positive Integers (terminate on -1)
    // --------------------------------------------------------
    cout << "--- Q1: Statistics of Positive Integers ---" << endl;
    cout << "Enter positive integers (-1 to stop): ";

    int number;
    cin >> number;

    if (number == -1) {
        cout << "No positive integers entered." << endl;
        return 0;
    }
    if (number < 1) {
        cout << "Only positive integers allowed!" << endl;
        return 1;
    }

    int count = 0, sum = 0, maxNum = number, minNum = number;
    int evenCount = 0, oddCount = 0, sumOfSquares = 0;

    while (number != -1) {
        if (number < 1) {
            cout << "Invalid! Only positive integers. Try again: ";
            cin >> number;
            continue;
        }

        count++;
        sum           += number;
        sumOfSquares  += number * number;

        if (number > maxNum) maxNum = number;
        if (number < minNum) minNum = number;

        if (number % 2 == 0) evenCount++;
        else                 oddCount++;

        cin >> number;
    }

    double average = (double)sum / count;

    cout << "\n--- Results ---" << endl;
    cout << "Total count    : " << count        << endl;
    cout << "Maximum        : " << maxNum       << endl;
    cout << "Minimum        : " << minNum       << endl;
    cout << "Average        : " << average      << endl;
    cout << "Even count     : " << evenCount    << endl;
    cout << "Odd count      : " << oddCount     << endl;
    cout << "Sum of squares : " << sumOfSquares << endl;


    // --------------------------------------------------------
    // Q2: Factorial using loop
    // --------------------------------------------------------
    cout << "\n--- Q2: Factorial ---" << endl;
    int n;
    long long factResult = 1;
    cout << "Enter a number: "; cin >> n;

    if (n < 0) {
        cout << "Factorial undefined for negative numbers." << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            factResult *= i;
        }
        cout << "Factorial of " << n << " = " << factResult << endl;
    }


    // --------------------------------------------------------
    // Q3: e^x series approximation (sum = 1 + x/1! - x^2/2! + ...)
    // --------------------------------------------------------
    cout << "\n--- Q3: Math Series (e^x approximation) ---" << endl;
    double xVal;
    int terms;
    cout << "Enter value of x: "; cin >> xVal;
    cout << "Enter number of terms: "; cin >> terms;

    double seriesSum = 1.0;  // first term is always 1
    double fact2 = 1.0;

    for (int i = 1; i < terms; i++) {
        fact2 *= i;
        double term = pow(xVal, i) / fact2;
        if (i % 2 == 0) seriesSum += term;
        else             seriesSum -= term;
    }
    cout << "Series sum = " << seriesSum << endl;


    // --------------------------------------------------------
    // Q4: Age & Driving License Check (Nested if)
    // --------------------------------------------------------
    cout << "\n--- Q4: Driving Eligibility ---" << endl;
    int driverAge;
    bool hasLicense;
    cout << "Enter your age: "; cin >> driverAge;
    cout << "Do you have a license? (1=Yes, 0=No): "; cin >> hasLicense;

    if (driverAge >= 18) {
        if (hasLicense) {
            cout << "You are ELIGIBLE to drive." << endl;
        } else {
            cout << "You need a driving license first." << endl;
        }
    } else {
        cout << "You are too young to drive (must be 18+)." << endl;
    }

    return 0;
}
