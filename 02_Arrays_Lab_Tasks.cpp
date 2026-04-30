/*
============================================================
  FILE    : 02_Arrays_Lab_Tasks.cpp
  TOPIC   : Arrays (1D and 2D) - Lab Practice & Assignments
  STUDENT : Mustafa Javed
  SUBJECT : Programming Fundamentals (PF) - Lab Tasks
============================================================

  CONTENTS:
    Q1  - Input & Display Array Elements
    Q2  - Sum of Array Elements
    Q3  - Product of Array Elements
    Q4  - Minimum Value in Array
    Q5  - Maximum Value in Array
    Q6  - Search Element in Array
    Q7  - Reverse an Array
    Q8  - Largest Element
    Q9  - Most Frequent Element
    Q10 - Separate Even and Odd Numbers
    Q11 - Top 3 Largest Elements
    Q12 - Second Largest Element
    Q13 - Second Smallest Element
    Q14 - Find Duplicates
    Q15 - Count Specific Element
    Q16 - Separate Even/Odd Indices
    Q17 - Move Zeros to Front, Ones to Back
    Q18 - Elements with 2+ Significant Digits
    --- 2D MATRIX OPERATIONS ---
    M1  - Matrix Addition (3x3)
    M2  - Matrix Multiplication (3x3)
    M3  - Matrix Transpose (3x3)
    M4  - Column-wise Sum of Matrix
    M5  - Middle Row and Column
============================================================
*/

#include <iostream>
using namespace std;

int main() {

    // --------------------------------------------------------
    // Q1: Input and Display Array of 10 Elements
    // --------------------------------------------------------
    cout << "--- Q1: Input & Display 10 Elements ---" << endl;
    int array[10];
    cout << "Enter 10 elements: " << endl;
    for (int i = 0; i < 10; i++) {
        cin >> array[i];
    }
    cout << "Array: ";
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // --------------------------------------------------------
    // Q2: Sum of Array Elements
    // --------------------------------------------------------
    cout << "\n--- Q2: Sum of Array ---" << endl;
    int num[4] = {2, 3, 4, 5};
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += num[i];
    }
    cout << "Sum = " << sum << endl;

    // --------------------------------------------------------
    // Q3: Product of Array Elements
    // --------------------------------------------------------
    cout << "\n--- Q3: Product of Array ---" << endl;
    int nums[4] = {1, 2, 4, 5};
    int product = 1;
    for (int i = 0; i < 4; i++) {
        product *= nums[i];
    }
    cout << "Product = " << product << endl;

    // --------------------------------------------------------
    // Q4: Minimum Value in Array
    // --------------------------------------------------------
    cout << "\n--- Q4: Minimum Value ---" << endl;
    int arr4[5] = {6, 2, 3, 4, 5};
    int minVal = arr4[0];
    for (int i = 0; i < 5; i++) {
        if (arr4[i] < minVal)
            minVal = arr4[i];
    }
    cout << "Minimum = " << minVal << endl;

    // --------------------------------------------------------
    // Q5: Maximum Value in Array
    // --------------------------------------------------------
    cout << "\n--- Q5: Maximum Value ---" << endl;
    int arr5[5] = {1, 2, 3, 4, 5};
    int maxVal = arr5[0];
    for (int i = 0; i < 5; i++) {
        if (arr5[i] > maxVal)
            maxVal = arr5[i];
    }
    cout << "Maximum = " << maxVal << endl;

    // --------------------------------------------------------
    // Q6: Search Element in Array
    // --------------------------------------------------------
    cout << "\n--- Q6: Search Element ---" << endl;
    int arr6[5] = {10, 20, 30, 40, 50};
    int target;
    bool found = false;
    cout << "Enter number to search: ";
    cin >> target;
    for (int i = 0; i < 5; i++) {
        if (arr6[i] == target) {
            found = true;
            break;
        }
    }
    cout << (found ? "Found in array!" : "Not found.") << endl;

    // --------------------------------------------------------
    // Q7: Reverse an Array
    // --------------------------------------------------------
    cout << "\n--- Q7: Reverse Array ---" << endl;
    int arr7[5] = {1, 2, 3, 4, 5};
    int left = 0, right = 4;
    while (left < right) {
        int temp = arr7[left];
        arr7[left] = arr7[right];
        arr7[right] = temp;
        left++;
        right--;
    }
    cout << "Reversed: ";
    for (int i = 0; i < 5; i++) cout << arr7[i] << " ";
    cout << endl;

    // --------------------------------------------------------
    // Q8: Largest Element
    // --------------------------------------------------------
    cout << "\n--- Q8: Largest Element ---" << endl;
    int arr8[5] = {1, 2, 6, 3, 3};
    int largest = arr8[0];
    for (int i = 0; i < 5; i++) {
        if (arr8[i] > largest)
            largest = arr8[i];
    }
    cout << "Largest = " << largest << endl;

    // --------------------------------------------------------
    // Q9: Most Frequent Element
    // --------------------------------------------------------
    cout << "\n--- Q9: Most Frequent Element ---" << endl;
    int arr9[9] = {1, 2, 3, 2, 4, 5, 2, 6, 7};
    int mostFrequent = arr9[0], maxCount = 0;
    for (int i = 0; i < 9; i++) {
        int count = 0;
        for (int j = 0; j < 9; j++) {
            if (arr9[i] == arr9[j]) count++;
        }
        if (count > maxCount) {
            maxCount = count;
            mostFrequent = arr9[i];
        }
    }
    cout << "Most frequent = " << mostFrequent << endl;

    // --------------------------------------------------------
    // Q10: Separate Even and Odd Numbers
    // --------------------------------------------------------
    cout << "\n--- Q10: Separate Even & Odd ---" << endl;
    int arr10[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int even[9], odd[9];
    int evenIndex = 0, oddIndex = 0;
    for (int i = 0; i < 9; i++) {
        if (arr10[i] % 2 == 0)
            even[evenIndex++] = arr10[i];
        else
            odd[oddIndex++] = arr10[i];
    }
    cout << "Even: ";
    for (int i = 0; i < evenIndex; i++) cout << even[i] << " ";
    cout << "\nOdd:  ";
    for (int i = 0; i < oddIndex; i++) cout << odd[i] << " ";
    cout << endl;

    // --------------------------------------------------------
    // Q11: Top 3 Largest Elements
    // --------------------------------------------------------
    cout << "\n--- Q11: Top 3 Largest ---" << endl;
    int arr11[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int l1 = 0, l2 = 0, l3 = 0;
    for (int i = 0; i < 9; i++) {
        if (arr11[i] > l1)      { l3 = l2; l2 = l1; l1 = arr11[i]; }
        else if (arr11[i] > l2) { l3 = l2; l2 = arr11[i]; }
        else if (arr11[i] > l3) { l3 = arr11[i]; }
    }
    cout << "Top 3: " << l1 << " " << l2 << " " << l3 << endl;

    // --------------------------------------------------------
    // Q12: Second Largest Element
    // --------------------------------------------------------
    cout << "\n--- Q12: Second Largest ---" << endl;
    int arr12[5] = {1, 2, 3, 4, 5};
    int largest2 = arr12[0], secondLargest = 0;
    for (int i = 0; i < 5; i++) {
        if (arr12[i] > largest2) {
            secondLargest = largest2;
            largest2 = arr12[i];
        } else if (arr12[i] > secondLargest) {
            secondLargest = arr12[i];
        }
    }
    cout << "Second Largest = " << secondLargest << endl;

    // --------------------------------------------------------
    // Q13: Second Smallest Element
    // --------------------------------------------------------
    cout << "\n--- Q13: Second Smallest ---" << endl;
    int arr13[5] = {1, 2, 3, 4, 5};
    int smallest = arr13[0], secondSmallest = arr13[1];
    if (secondSmallest < smallest) { int t = smallest; smallest = secondSmallest; secondSmallest = t; }
    for (int i = 2; i < 5; i++) {
        if (arr13[i] < smallest) { secondSmallest = smallest; smallest = arr13[i]; }
        else if (arr13[i] < secondSmallest) { secondSmallest = arr13[i]; }
    }
    cout << "Second Smallest = " << secondSmallest << endl;

    // --------------------------------------------------------
    // Q14: Find Duplicate Elements
    // --------------------------------------------------------
    cout << "\n--- Q14: Duplicate Elements ---" << endl;
    int arr14[7] = {1, 2, 3, 4, 2, 5, 1};
    cout << "Duplicates: ";
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            if (arr14[i] == arr14[j]) {
                cout << arr14[i] << " ";
                break;
            }
        }
    }
    cout << endl;

    // --------------------------------------------------------
    // Q15: Count Occurrences of a Specific Element
    // --------------------------------------------------------
    cout << "\n--- Q15: Count Occurrences of 4 ---" << endl;
    int arr15[8] = {1, 2, 2, 3, 4, 4, 4, 5};
    int target15 = 4, count15 = 0;
    for (int i = 0; i < 8; i++) {
        if (arr15[i] == target15) count15++;
    }
    cout << "Count of " << target15 << " = " << count15 << endl;

    // --------------------------------------------------------
    // Q16: Separate Even-Index and Odd-Index Elements
    // --------------------------------------------------------
    cout << "\n--- Q16: Even-Index then Odd-Index ---" << endl;
    int arr16[5] = {1, 2, 3, 4, 5};
    cout << "Even-index: ";
    for (int i = 0; i < 5; i++) { if (i % 2 == 0) cout << arr16[i] << " "; }
    cout << "\nOdd-index:  ";
    for (int i = 0; i < 5; i++) { if (i % 2 != 0) cout << arr16[i] << " "; }
    cout << endl;

    // --------------------------------------------------------
    // Q17: Move Zeros to Front, Ones to Back
    // --------------------------------------------------------
    cout << "\n--- Q17: Zeros First, Ones Last ---" << endl;
    int arr17[6] = {0, 1, 0, 1, 1, 0};
    int zeroCount = 0;
    for (int i = 0; i < 6; i++) { if (arr17[i] == 0) zeroCount++; }
    for (int i = 0; i < zeroCount; i++) cout << "0 ";
    for (int i = 0; i < 6 - zeroCount; i++) cout << "1 ";
    cout << endl;

    // --------------------------------------------------------
    // Q18: Elements with At Least 2 Significant Digits (>= 10)
    // --------------------------------------------------------
    cout << "\n--- Q18: Elements with 2+ Digits ---" << endl;
    int arr18[5] = {5, 12, 3, 100, 7};
    cout << "Two-digit+ elements: ";
    for (int i = 0; i < 5; i++) {
        int n = arr18[i], digitCount = 0;
        while (n > 0) { n /= 10; digitCount++; }
        if (digitCount >= 2) cout << arr18[i] << " ";
    }
    cout << endl;

    // ========================================================
    //                    2D MATRIX OPERATIONS
    // ========================================================

    // --------------------------------------------------------
    // M1: Matrix Addition (3x3)
    // --------------------------------------------------------
    cout << "\n--- M1: Matrix Addition (3x3) ---" << endl;
    int A[3][3], B[3][3], result[3][3];
    cout << "Enter elements of Matrix A:" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) { cout << "A[" << i << "][" << j << "]: "; cin >> A[i][j]; }
    cout << "Enter elements of Matrix B:" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) { cout << "B[" << i << "][" << j << "]: "; cin >> B[i][j]; }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            result[i][j] = A[i][j] + B[i][j];
    cout << "A + B = " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << result[i][j] << " ";
        cout << endl;
    }

    // --------------------------------------------------------
    // M2: Matrix Multiplication (3x3)
    // --------------------------------------------------------
    cout << "\n--- M2: Matrix Multiplication (3x3) ---" << endl;
    int a[3][3], b[3][3], mul[3][3] = {0};
    cout << "Enter Matrix A:" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cin >> a[i][j];
    cout << "Enter Matrix B:" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cin >> b[i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                mul[i][j] += a[i][k] * b[k][j];
    cout << "A x B = " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << mul[i][j] << " ";
        cout << endl;
    }

    // --------------------------------------------------------
    // M3: Matrix Transpose (3x3)
    // --------------------------------------------------------
    cout << "\n--- M3: Matrix Transpose (3x3) ---" << endl;
    int mat[3][3], trans[3][3];
    cout << "Enter 3x3 Matrix:" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cin >> mat[i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            trans[j][i] = mat[i][j];
    cout << "Transpose:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << trans[i][j] << " ";
        cout << endl;
    }

    // --------------------------------------------------------
    // M4: Column-wise Sum
    // --------------------------------------------------------
    cout << "\n--- M4: Column-wise Sum ---" << endl;
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Column sums: ";
    for (int j = 0; j < 3; j++) {
        cout << matrix[0][j] + matrix[1][j] + matrix[2][j] << " ";
    }
    cout << endl;

    // --------------------------------------------------------
    // M5: Print Middle Row and Middle Column of 3x3
    // --------------------------------------------------------
    cout << "\n--- M5: Middle Row & Column ---" << endl;
    int grid[3][3];
    cout << "Enter 3x3 Matrix:" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) { cout << "grid[" << i << "][" << j << "]: "; cin >> grid[i][j]; }
    cout << "Middle Row:    " << grid[1][0] << " " << grid[1][1] << " " << grid[1][2] << endl;
    cout << "Middle Column: " << grid[0][1] << " " << grid[1][1] << " " << grid[2][1] << endl;

    return 0;
}
