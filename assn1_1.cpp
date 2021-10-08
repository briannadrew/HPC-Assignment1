// Name: assn1_1.cpp
// Author: Brianna Drew
// ID: #0622446
// Date Created: 2021-10-03
// Last Modified: 2021-10-06

// ADAPTED FROM: https://www.geeksforgeeks.org/program-for-gauss-jordan-elimination-method/

// Libraries
#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Print matrix
void PrintMatrix(float arr[10][11], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

// Reduce matrix to reduced row echelon form
int PerformOperation(float arr[10][11], int n)
{
  int i, j, k = 0, c, flag = 0, m = 0;
  float pro = 0;

  // Perform elementary operations
  for (i = 0; i < n; i++)
  {
    if (arr[i][i] == 0)
    {
      c = 1;
      while ((i + c) < n && arr[i + c][i] == 0)
        c++;
      if ((i + c) == n)
      {
        flag = 1;
        break;
      }
      for (j = i, k = 0; k <= n; k++)
        swap(arr[j][k], arr[j+c][k]);
    }
    for (j = 0; j < n; j++)
    {
      // Exclude all i = j
      if (i != j)
      {
        // Convert matrix to reduced row echelon form (diagonal matrix)
        float pro = arr[j][i] / arr[i][i];
        for (k = 0; k <= n; k++)
          arr[j][k] = arr[j][k] - (arr[i][k]) * pro;
      }
    }
  }
  return flag;
}

// Print desired result if unique solution exists, otherwise...
// prints no or infinite solutions depending on input.
void PrintResult(float arr[10][11], int n, int flag)
{
  cout << "Result is: ";

  if (flag == 2)
    cout << "Infinite Solutions Exist" << endl;
  else if (flag == 3)
    cout << "No Solutions Exist" << endl;

  // Print the solution by dividing constants by their
  // respective diagonal elements.
  else {
    for (int i = 0; i < n; i++)
      cout << arr[i][n] / arr[i][i] << " ";
  }
}

// Check whether infinite solutions exist or no solutions exist
int CheckConsistency(float arr[10][11], int n, int flag)
{
  int i, j;
  float sum;

  // flag = 2 for infinite solutions
  // flag = 3 for no solutions
  flag = 3;
  for (i = 0; i < n; i++)
  {
    sum = 0;
    for (j = 0; j < n; j++)
      sum = sum + arr[i][j];
    if (sum == arr[i][j])
      flag = 2;
  }
  return flag;
}

// Driver function
int main() {

  double starttime = clock();
  double onesec = starttime;
  int sltns = 0;

  while(true)
  {
    // Print the number of solutions ran every second
    if (((clock() - onesec) / CLOCKS_PER_SEC) >= 1)
    {
      cout << "************************" << endl;
      cout << " Solutions Ran: " << sltns << endl;
      cout << "************************" << endl << endl << endl << endl;
      onesec = clock();
    }

    // After 10 seconds, exit loop and end program
    if (((clock() - starttime) / CLOCKS_PER_SEC) >= 10)
      break;

    srand (time(0)); // initialize random number generator based on time
    float arr[10][11];

    // traverse and insert values into array
    for(int i = 0; i < 10; i++)
    {
      for(int j = 0; j <= 10; j++)
      {
        arr[i][j] = rand() % 11; // insert random number between 0 and 10 into array
      }
    }

    // Order of matrix(n)
    int n = 10, flag = 0;

    // Perform matrix transformation
    flag = PerformOperation(arr, n);

    if (flag == 1)
      flag = CheckConsistency(arr, n, flag);

    // Print final matrix
    cout << "Final Augmented Matrix is: " << endl;
    PrintMatrix(arr, n);
    cout << endl;

    // Print solutions (if they exist)
    PrintResult(arr, n, flag);
    cout << endl << endl << endl << endl;

    // Finished running solution, increase solution count
    sltns++;
  }
  cout << "*****************************" << endl;
  cout << "Total Solutions Ran: " << sltns << endl; // Final count of runthroughs
  cout << "*****************************" << endl << endl;
  return 0;
}
