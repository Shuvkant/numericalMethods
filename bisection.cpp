#include <iostream>
#include <iomanip>
#include <cmath>
#define width 15
#define error 0.0001
using namespace std;

double f(double x)
{
    return pow(x, 3) - 4 * x - 9;
}
int main()
{
    int i = 1;
    double x1, x2, x3, fxn, iterations;
    // Initialization of two inital guessing numbers
    do
    {
        cout << "Enter two initial guess";
        cin >> x1 >> x2;
    } while (f(x1) * f(x2) >= 0);
    // Calculation of mid-point

    cout
        << setw(width) << "iteration";
    cout << setw(width) << "x1";
    cout << setw(width) << "x2";
    cout << setw(width) << "x3";
    cout << setw(width) << "fxn" << endl;

    do
    {

        x3 = (x1 + x2) / 2;
        fxn = f(x3);
        cout
            << setw(width) << i;
        cout << setw(width) << x1;
        cout << setw(width) << x2;
        cout << setw(width) << x3;
        cout << setw(width) << f(x3) << endl;
        if (fxn < 0)
        {
            x1 = x3;
        }
        else
        {
            x2 = x3;
        }
        i++;
        // } while (fabs(f(x3)) > error);
    } while (fabs((x2 - x1)) > error);
}