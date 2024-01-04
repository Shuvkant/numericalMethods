
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#define width 5
#define max 100
void Display(double matrix[max][max], int number_of_equations);

// solution finding
void Result(double matrix[max][max], int number_of_equations)
{
  int n = number_of_equations;
  double y[max];
  y[n - 1] = matrix[n][n + 1] / matrix[n][n];
  for (int i = n - 1; i >= 1; i--)
  {
    y[i - 1] = matrix[i][n + 1];
    for (int j = i + 1; j <= n; j++)
    {
      y[i - 1] = y[i - 1] - matrix[i][j] * y[j - 1];
    }
    y[i - 1] = y[i - 1] / matrix[i][i];
  }
  for (int i = 1; i <= n; i++)
  {
    std::cout << "x" << i << "=" << y[i - 1] << "\n";
  }
}
void Calculate(double matrix[max][max], int number_of_equations)
{
  double ratio;
  for (int i = 1; i <= number_of_equations; i++)
  {
    for (int j = i + 1; j <= number_of_equations; j++)
    {
      ratio = matrix[j][i] / matrix[i][i];
      for (int k = 1; k <= number_of_equations + 1; k++)
      {
        matrix[j][k] = matrix[j][k] - ratio * (matrix[i][k]);
      }
    }
  }
}

int main()
{
  int number_of_equations;
  int n;
  int i, j, k;
  double y[max];
  std::cout << "Enter the number of equations: ";
  std::cin >> number_of_equations;
  n = number_of_equations;
  double matrix[max][max];
  std::cout << "Enter the augmented matrix: " << std::endl;
  for (i = 1; i <= number_of_equations; i++)
  {
    for (j = 1; j <= number_of_equations + 1; j++)
    {
      // std::cout << "A[" << i << "][" << j << "]=";
      std::cin >> matrix[i][j];
    }
  }
  Display(matrix, number_of_equations);
  Calculate(matrix, number_of_equations);
  Display(matrix, number_of_equations);
  Result(matrix, n);
}
void Display(double matrix[max][max], int number_of_equations)
{
  // Displaying the Entered matrix;
  std::cout << "The matrix is:\n";
  for (int i = 1; i <= number_of_equations; i++)
  {
    for (int j = 1; j <= number_of_equations + 1; j++)
    {
      std::cout << matrix[i][j] << "\t\t";
      // std::cin >> a[i][j];
    }
    std::cout << "\n";
  }
}
