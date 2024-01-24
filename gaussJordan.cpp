#include<iostream>
#include<iomanip>

#define SIZE 10

int main() {
    float a[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;

    /* Inputs */
    /* 1. Reading number of unknowns */
    std::cout << "Enter number of unknowns: ";
    std::cin >> n;

    /* 2. Reading Augmented Matrix */
    std::cout << "Enter coefficients of Augmented Matrix:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            std::cout << "a[" << i << "][" << j << "] = ";
            std::cin >> a[i][j];
        }
    }

    /* Applying Gauss Jordan Elimination */
    for (i = 1; i <= n; i++) {
        if (a[i][i] == 0.0) {
            std::cout << "Mathematical Error!";
            exit(0);
        }
        for (j = 1; j <= n; j++) {
            if (i != j) {
                ratio = a[j][i] / a[i][i];
                for (k = 1; k <= n + 1; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    /* Obtaining Solution */
    for (i = 1; i <= n; i++) {
        x[i] = a[i][n + 1] / a[i][i];
    }

    /* Displaying Solution */
    std::cout << "\nSolution:\n";
    for (i = 1; i <= n; i++) {
        std::cout << "x[" << i << "] = " << std::fixed << std::setprecision(3) << x[i] << "\n";
    }

    return 0;
}
