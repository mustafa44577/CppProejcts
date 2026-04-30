/*
============================================================
  FILE    : 08_Mini_Project_Algorithms.cpp
  TOPIC   : Mini Project - Algorithm Problems
  STUDENT : Mustafa Javed
  SUBJECT : Programming Fundamentals (PF) - Lab Project
============================================================

  CONTENTS:
    Q1  - Prime Number Checker (function)
    Q2  - Custom Number Series Generator
    Q3  - m to the power n (m^n)
    Q4  - GCD and LCM using Functions
    Q5  - Hollow Diamond Pattern
    Q6  - Array to Number & Number to Array (multiplication)
    Q7  - Armstrong Number Check
    Q8  - Convert String to Lowercase (using switch)
    Q9  - Convert String to Lowercase (using tolower)
    Q10 - Password Validator
    Q11 - Reverse Words in a Sentence
============================================================
*/

#include <iostream>
#include <cmath>
#include <cctype>
#include <string>
using namespace std;

// ============================================================
//          FUNCTION DECLARATIONS
// ============================================================
bool isPrime(int n);
int  findGCD(int a, int b);
int  findLCM(int a, int b);
int  arrayToNumber(int arr[], int size);
void numberToArray(int num, int result[], int &resultSize);
bool isValidPassword(string p);


// ============================================================
//                    MAIN
// ============================================================
int main() {

    // --------------------------------------------------------
    // Q1: Prime Number Checker
    // --------------------------------------------------------
    cout << "--- Q1: Prime Number Checker ---" << endl;
    int n;
    cout << "Enter a number: "; cin >> n;
    cout << n << " is " << (isPrime(n) ? "" : "NOT ") << "a prime number." << endl;


    // --------------------------------------------------------
    // Q2: Custom Number Series Generator
    //     - First 3 terms: 2, 4, 6
    //     - Each next term = average of previous 3
    // --------------------------------------------------------
    cout << "\n--- Q2: Custom Number Series ---" << endl;
    int howMany;
    cout << "How many terms? "; cin >> howMany;

    if (howMany >= 3) {
        float ta = 2, tb = 4, tc = 6;
        cout << ta << "," << tb << "," << tc;
        for (int i = 3; i < howMany; i++) {
            float newN = (ta + tb + tc) / 3;
            cout << "," << newN;
            ta = tb;
            tb = tc;
            tc = newN;
        }
    } else {
        int d = 0;
        for (int j = 1; j <= howMany; j++) {
            d += 2;
            cout << d;
            if (j < howMany) cout << ",";
        }
    }
    cout << endl;


    // --------------------------------------------------------
    // Q3: m to the power n (without pow())
    // --------------------------------------------------------
    cout << "\n--- Q3: m^n (Manual Power) ---" << endl;
    double m;
    int    pn;
    cout << "Enter base m: ";     cin >> m;
    cout << "Enter exponent n: "; cin >> pn;
    double ans = 1;
    for (int i = 0; i < pn; i++) ans *= m;
    cout << m << " ^ " << pn << " = " << ans << endl;


    // --------------------------------------------------------
    // Q4: GCD and LCM
    // --------------------------------------------------------
    cout << "\n--- Q4: GCD and LCM ---" << endl;
    int ga, gb;
    cout << "Enter two numbers: "; cin >> ga >> gb;
    cout << "GCD = " << findGCD(ga, gb) << endl;
    cout << "LCM = " << findLCM(ga, gb) << endl;


    // --------------------------------------------------------
    // Q5: Hollow Diamond Pattern
    // --------------------------------------------------------
    cout << "\n--- Q5: Hollow Diamond ---" << endl;
    int dn = 4;
    // Top half
    for (int i = 0; i < dn; i++) {
        for (int j = 0; j < dn - i - 1; j++) cout << " ";
        cout << "*";
        if (i != 0) {
            for (int j = 0; j < 2 * i - 1; j++) cout << " ";
            cout << "*";
        }
        cout << endl;
    }
    // Bottom half
    for (int i = dn - 2; i >= 0; i--) {
        for (int j = 0; j < dn - i - 1; j++) cout << " ";
        cout << "*";
        if (i != 0) {
            for (int j = 0; j < 2 * i - 1; j++) cout << " ";
            cout << "*";
        }
        cout << endl;
    }


    // --------------------------------------------------------
    // Q6: Array to Number, Multiply Two Arrays as Numbers
    // --------------------------------------------------------
    cout << "\n--- Q6: Array-as-Number Multiplication ---" << endl;
    int A[3], B[3], resArr[12];
    int resSize;
    cout << "Enter 3 digits for A: "; for (int i = 0; i < 3; i++) cin >> A[i];
    cout << "Enter 3 digits for B: "; for (int i = 0; i < 3; i++) cin >> B[i];

    int numA = arrayToNumber(A, 3);
    int numB = arrayToNumber(B, 3);
    int resMul = numA * numB;
    numberToArray(resMul, resArr, resSize);

    cout << numA << " x " << numB << " = ";
    for (int i = 0; i < resSize; i++) cout << resArr[i];
    cout << endl;


    // --------------------------------------------------------
    // Q7: Armstrong Number (e.g. 153 = 1^3 + 5^3 + 3^3)
    // --------------------------------------------------------
    cout << "\n--- Q7: Armstrong Number Check ---" << endl;
    int armNum;
    cout << "Enter a 3-digit number: "; cin >> armNum;
    int hundreds = armNum / 100;
    int tens     = (armNum / 10) % 10;
    int ones     = armNum % 10;
    if (armNum == pow(hundreds, 3) + pow(tens, 3) + pow(ones, 3))
        cout << armNum << " IS an Armstrong number." << endl;
    else
        cout << armNum << " is NOT an Armstrong number." << endl;


    // --------------------------------------------------------
    // Q8: Convert String to Lowercase (tolower)
    // --------------------------------------------------------
    cout << "\n--- Q8: To Lowercase ---" << endl;
    char strArr[100];
    cout << "Type a sentence: "; cin.ignore(); cin.getline(strArr, 100);
    for (int i = 0; strArr[i] != '\0'; i++) {
        strArr[i] = tolower(strArr[i]);
    }
    cout << "Lowercase: " << strArr << endl;


    // --------------------------------------------------------
    // Q9: Password Validator
    //     Rules: 8-16 chars, can't start with special, must have
    //            uppercase + digit + special symbol (@$%&*)
    // --------------------------------------------------------
    cout << "\n--- Q9: Password Validator ---" << endl;
    string password;
    cout << "Enter password: "; cin >> password;
    if (isValidPassword(password))
        cout << "Password is VALID." << endl;


    // --------------------------------------------------------
    // Q10: Reverse Words in a Sentence
    // --------------------------------------------------------
    cout << "\n--- Q10: Reverse Words ---" << endl;
    char sentence[100];
    char words[20][20];
    int si = 0, wj = 0, wk = 0;
    cout << "Enter a sentence: "; cin.ignore(); cin.getline(sentence, 100);

    while (sentence[si] != '\0') {
        if (sentence[si] != ' ') {
            words[wk][wj] = sentence[si];
            wj++;
        } else {
            if (wj > 0) {
                words[wk][wj] = '\0';
                wk++;
                wj = 0;
            }
        }
        si++;
    }
    if (wj > 0) { words[wk][wj] = '\0'; }

    cout << "Reversed words: ";
    for (int x = wk; x >= 0; x--) {
        cout << words[x];
        if (x > 0) cout << " ";
    }
    cout << endl;

    return 0;
}


// ============================================================
//              FUNCTION DEFINITIONS
// ============================================================

bool isPrime(int n) {
    if (n < 2)      return false;
    if (n == 2)     return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int findLCM(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return (a * b) / findGCD(a, b);
}

int arrayToNumber(int arr[], int size) {
    int num = 0;
    for (int i = 0; i < size; i++) {
        num = num * 10 + arr[i];
    }
    return num;
}

void numberToArray(int num, int result[], int &resultSize) {
    resultSize = 0;
    while (num > 0) {
        result[resultSize++] = num % 10;
        num /= 10;
    }
    // Reverse to get correct order
    for (int i = 0; i < resultSize / 2; i++) {
        swap(result[i], result[resultSize - i - 1]);
    }
}

bool isValidPassword(string p) {
    if (p.length() < 8 || p.length() > 16) {
        cout << "Invalid: Length must be 8-16 characters." << endl;
        return false;
    }
    char first = p[0];
    if (first == '@' || first == '$' || first == '%' || first == '&' || first == '*') {
        cout << "Invalid: Cannot start with a special symbol." << endl;
        return false;
    }
    bool hasUpper = false, hasDigit = false, hasSymbol = false;
    for (char c : p) {
        if (!isalnum(c) && c != '@' && c != '$' && c != '%' && c != '&' && c != '*') {
            cout << "Invalid: Only A-Z, a-z, 0-9, @, $, %, &, * allowed." << endl;
            return false;
        }
        if (isupper(c)) hasUpper  = true;
        if (isdigit(c)) hasDigit  = true;
        if (c=='@'||c=='$'||c=='%'||c=='&'||c=='*') hasSymbol = true;
    }
    if (!hasUpper)  { cout << "Invalid: Must have at least one uppercase letter." << endl; return false; }
    if (!hasDigit)  { cout << "Invalid: Must have at least one digit."            << endl; return false; }
    if (!hasSymbol) { cout << "Invalid: Must have at least one special symbol."   << endl; return false; }
    return true;
}
