/*
============================================================
  FILE    : 04_Pointers.cpp
  TOPIC   : Pointers - Lab Practice
  STUDENT : Mustafa Javed
  SUBJECT : Programming Fundamentals (PF) - Lab Tasks
============================================================

  CONTENTS:
    Q1  - Basic Pointer (address & value)
    Q2  - Double Pointer (**ptr)
    Q3  - Swap using Pointers
    Q4  - Square Value using Pointer (function)
    Q5  - Print Array using Pointer Arithmetic
    Q6  - Access Array Element via Pointer Index
    Q7  - Reverse Array using Pointers
    Q8  - Pointer Traversal of Array (addresses & values)
    Q9  - Swap using Pass by Reference
    Q10 - Dynamic Memory: single variable (new/delete)
    Q11 - Dynamic Array (new[]/delete[])
    Q12 - Pointer to pointer - change value
============================================================
*/

#include <iostream>
using namespace std;

// ============================================================
//              FUNCTION DECLARATIONS
// ============================================================
void swapPointer(int *a, int *b);
void squareValue(int *ptr);
void printArray(int *arr, int size);
void reverseArray(int *arr, int size);
void swapRef(int &a, int &b);


// ============================================================
//                       MAIN
// ============================================================
int main() {

    // --------------------------------------------------------
    // Q1: Basic Pointer - store address, read value
    // --------------------------------------------------------
    cout << "--- Q1: Basic Pointer ---" << endl;
    int x = 5;
    int *ptr = &x;
    cout << "Value of x      = " << x    << endl;
    cout << "Address of x    = " << &x   << endl;
    cout << "ptr holds       = " << ptr  << endl;  // address
    cout << "*ptr (value)    = " << *ptr << endl;  // value

    // change value through pointer
    *ptr = 20;
    cout << "After *ptr = 20, x = " << x << endl;

    // --------------------------------------------------------
    // Q2: Pointer to Pointer (**)
    // --------------------------------------------------------
    cout << "\n--- Q2: Double Pointer (**) ---" << endl;
    int val = 100;
    int *p  = &val;
    int **pp = &p;
    cout << "val    = " << val   << endl;
    cout << "*p     = " << *p    << endl;
    cout << "**pp   = " << **pp  << endl;
    cout << "p      = " << p     << " (address of val)" << endl;
    cout << "*pp    = " << *pp   << " (same as p)"     << endl;

    // --------------------------------------------------------
    // Q3: Swap using Pointers
    // --------------------------------------------------------
    cout << "\n--- Q3: Swap using Pointers ---" << endl;
    int a = 5, b = 6;
    cout << "Before: a = " << a << ", b = " << b << endl;
    swapPointer(&a, &b);
    cout << "After:  a = " << a << ", b = " << b << endl;

    // --------------------------------------------------------
    // Q4: Square Value using Pointer (function)
    // --------------------------------------------------------
    cout << "\n--- Q4: Square using Pointer ---" << endl;
    int num = 5;
    cout << "Before: " << num << endl;
    squareValue(&num);
    cout << "After squareValue(&num): " << num << endl;

    // --------------------------------------------------------
    // Q5: Print Array using Pointer Arithmetic
    // --------------------------------------------------------
    cout << "\n--- Q5: Array via Pointer Arithmetic ---" << endl;
    int arr[] = {10, 20, 30, 40};
    printArray(arr, 4);

    // --------------------------------------------------------
    // Q6: Access Array Element via Pointer Index
    // --------------------------------------------------------
    cout << "\n--- Q6: Access via ptr[index] ---" << endl;
    int arr2[] = {1, 2, 3, 4, 5};
    int *pArr = arr2;
    cout << "pArr[0] = " << pArr[0] << endl;
    cout << "pArr[1] = " << pArr[1] << endl;
    cout << "arr2[1] = " << arr2[1] << " (same)" << endl;

    // --------------------------------------------------------
    // Q7: Reverse Array using Pointers
    // --------------------------------------------------------
    cout << "\n--- Q7: Reverse Array using Pointers ---" << endl;
    int arr3[] = {1, 2, 3, 4, 5};
    reverseArray(arr3, 5);
    cout << "Reversed: ";
    for (int i = 0; i < 5; i++) cout << arr3[i] << " ";
    cout << endl;

    // --------------------------------------------------------
    // Q8: Pointer Traversal - Print Addresses and Values
    // --------------------------------------------------------
    cout << "\n--- Q8: Pointer Traversal ---" << endl;
    int arr4[5] = {1, 2, 3, 4, 5};
    int *ptr4 = arr4;
    cout << "ptr4 (base address) = " << ptr4 << endl;
    cout << "&arr4[0]            = " << &arr4[0] << endl;
    cout << "Values via *(ptr+i):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  *(ptr4 + " << i << ") = " << *(ptr4 + i) << endl;
    }

    // --------------------------------------------------------
    // Q9: Swap using Pass by Reference
    // --------------------------------------------------------
    cout << "\n--- Q9: Swap using Reference ---" << endl;
    int c = 10, d = 20;
    cout << "Before: c = " << c << ", d = " << d << endl;
    swapRef(c, d);
    cout << "After:  c = " << c << ", d = " << d << endl;

    // --------------------------------------------------------
    // Q10: Dynamic Memory - Single Variable
    // --------------------------------------------------------
    cout << "\n--- Q10: Dynamic Memory (new/delete) ---" << endl;
    int *dynPtr = new int;
    *dynPtr = 42;
    cout << "Dynamic value = " << *dynPtr << endl;
    delete dynPtr;  // free memory
    dynPtr = nullptr;
    cout << "Memory freed." << endl;

    // --------------------------------------------------------
    // Q11: Dynamic Array
    // --------------------------------------------------------
    cout << "\n--- Q11: Dynamic Array ---" << endl;
    int size;
    cout << "Enter size of array: "; cin >> size;
    int *dynArr = new int[size];
    for (int i = 0; i < size; i++) dynArr[i] = i + 1;
    cout << "Dynamic array: ";
    for (int i = 0; i < size; i++) cout << dynArr[i] << " ";
    cout << endl;
    delete[] dynArr;
    cout << "Dynamic array memory freed." << endl;

    // --------------------------------------------------------
    // Q12: Change value of a variable through pointer-to-pointer
    // --------------------------------------------------------
    cout << "\n--- Q12: Change Value via **ptr ---" << endl;
    int target = 50;
    int *p12  = &target;
    int **pp12 = &p12;
    **pp12 = 99;
    cout << "target after **pp12 = 99: " << target << endl;

    return 0;
}


// ============================================================
//              FUNCTION DEFINITIONS
// ============================================================

// Q3: Swap using pointers
void swapPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Q4: Square the value at the pointer's address
void squareValue(int *ptr) {
    *ptr = (*ptr) * (*ptr);
}

// Q5: Print array using pointer arithmetic
void printArray(int *arr, int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

// Q7: Reverse array using two pointers
void reverseArray(int *arr, int size) {
    int *start = arr;
    int *end   = arr + size - 1;
    while (start < end) {
        int temp = *start;
        *start   = *end;
        *end     = temp;
        start++;
        end--;
    }
}

// Q9: Swap by reference
void swapRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
