/*
============================================================
  FILE    : 01_Nested_Loops_Star_Patterns.cpp
  TOPIC   : Nested Loops - Star & Number Patterns
  STUDENT : Mustafa Javed
  SUBJECT : Programming Fundamentals (PF) - Lab Tasks
============================================================

  CONTENTS:
    Pattern  1  - Right Triangle (Stars)
    Pattern  2  - Inverted Right Triangle (Stars)
    Pattern  3  - Right Triangle (Stars, Right-aligned)
    Pattern  4  - Right Triangle (Numbers ascending)
    Pattern  5  - Right Triangle (Numbers descending)
    Pattern  6  - Square Grid
    Pattern  7  - Row-Repeating Numbers
    Pattern  8  - Checkerboard (* and +)
    Pattern  9  - Column-Repeating Numbers
    Pattern 10  - Reverse Descending Numbers
    Pattern 11  - Diamond (Full)
    Pattern 12  - Diamond (Hollow)
    Pattern 13  - Pyramid (Stars)
    Pattern 14  - Reverse Pyramid (Stars)
    Pattern 15  - Plus/Cross Shape
============================================================
*/

#include <iostream>
using namespace std;

int main() {

    // --------------------------------------------------------
    // Pattern 1: Right Triangle (Stars)
    // Output:
    // *
    // **
    // ***
    // ****
    // *****
    // --------------------------------------------------------
    cout << "--- Pattern 1: Right Triangle (Stars) ---" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // --------------------------------------------------------
    // Pattern 2: Inverted Right Triangle (Stars)
    // Output:
    // *****
    // ****
    // ***
    // **
    // *
    // --------------------------------------------------------
    cout << "\n--- Pattern 2: Inverted Right Triangle (Stars) ---" << endl;
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // --------------------------------------------------------
    // Pattern 3: Right Triangle Stars (Right-aligned)
    // Output:
    //     *
    //    **
    //   ***
    //  ****
    // *****
    // --------------------------------------------------------
    cout << "\n--- Pattern 3: Right-Aligned Triangle ---" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int space = 5; space >= i; space--) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // --------------------------------------------------------
    // Pattern 4: Right Triangle (Numbers 1..i per row)
    // Output:
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4
    // 1 2 3 4 5
    // --------------------------------------------------------
    cout << "\n--- Pattern 4: Right Triangle (Row Numbers) ---" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    // --------------------------------------------------------
    // Pattern 5: Inverted Triangle (Numbers)
    // Output:
    // 1 2 3 4 5
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1
    // --------------------------------------------------------
    cout << "\n--- Pattern 5: Inverted Triangle (Row Numbers) ---" << endl;
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    // --------------------------------------------------------
    // Pattern 6: 5x5 Square of Stars
    // --------------------------------------------------------
    cout << "\n--- Pattern 6: Square Grid of Stars ---" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    // --------------------------------------------------------
    // Pattern 7: Row Number Repeated Per Row
    // Output:
    // 1 1 1 1 1
    // 2 2 2 2 2
    // etc.
    // --------------------------------------------------------
    cout << "\n--- Pattern 7: Row Number Repeated ---" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cout << i << " ";
        }
        cout << endl;
    }

    // --------------------------------------------------------
    // Pattern 8: Checkerboard (* and +)
    // --------------------------------------------------------
    cout << "\n--- Pattern 8: Checkerboard (* and +) ---" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i + j) % 2 == 0)
                cout << "* ";
            else
                cout << "+ ";
        }
        cout << endl;
    }

    // --------------------------------------------------------
    // Pattern 9: Column Numbers Repeated
    // Output:
    // 1 1 1 1 1
    // 1 2 2 2 2  <- each col j up to i
    // --------------------------------------------------------
    cout << "\n--- Pattern 9: Column-Repeating Numbers ---" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }

    // --------------------------------------------------------
    // Pattern 10: Reverse Descending Numbers
    // Output:
    // 10 9 8 7
    // 6  5 4
    // 3  2
    // 1
    // --------------------------------------------------------
    cout << "\n--- Pattern 10: Reverse Descending Numbers ---" << endl;
    int number = 10;
    for (int i = 4; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << number << " ";
            number--;
        }
        cout << endl;
    }

    // --------------------------------------------------------
    // Pattern 11: Full Diamond
    // Output:
    //     *
    //    ***
    //   *****
    //  *******
    //   *****
    //    ***
    //     *
    // --------------------------------------------------------
    cout << "\n--- Pattern 11: Full Diamond ---" << endl;
    int rows = 5;
    for (int i = 1; i <= rows; i++) {
        for (int space = rows; space >= i; space--) cout << " ";
        for (int j = 1; j <= (2 * i - 1); j++) cout << "*";
        cout << endl;
    }
    for (int i = rows - 1; i >= 1; i--) {
        for (int space = rows; space >= i; space--) cout << " ";
        for (int j = 1; j <= (2 * i - 1); j++) cout << "*";
        cout << endl;
    }

    // --------------------------------------------------------
    // Pattern 12: Pyramid (Stars, center-aligned)
    // --------------------------------------------------------
    cout << "\n--- Pattern 12: Pyramid ---" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 5; j > i; j--) cout << "  ";
        for (int k = 1; k <= i; k++) cout << "* ";
        cout << endl;
    }

    // --------------------------------------------------------
    // Pattern 13: Reverse Pyramid
    // --------------------------------------------------------
    cout << "\n--- Pattern 13: Reverse Pyramid ---" << endl;
    for (int i = 5; i >= 1; i--) {
        for (int j = 0; j <= 5 - i; j++) cout << "  ";
        for (int k = 1; k <= i; k++) cout << "* ";
        cout << endl;
    }

    // --------------------------------------------------------
    // Pattern 14: Continuous Number Triangle
    // Output:
    // 1
    // 2 3
    // 4 5 6
    // etc.
    // --------------------------------------------------------
    cout << "\n--- Pattern 14: Continuous Number Triangle ---" << endl;
    int num = 1;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }

    // --------------------------------------------------------
    // Pattern 15: Continuous Alphabet Triangle
    // Output:
    // A
    // B C
    // D E F
    // --------------------------------------------------------
    cout << "\n--- Pattern 15: Alphabet Triangle ---" << endl;
    char cha = 'A';
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << cha << " ";
            cha++;
        }
        cout << endl;
    }

    return 0;
}

#this is for checking git is working or not