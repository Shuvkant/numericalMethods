// Newton-Raphson Method
#include <iostream>
#include <iomanip>
#include <cmath>
#define error 0.0001
#define width 15
using namespace std;
double f(double x)
{
    return 3 * x - exp(-x);
}
double g(double x)
{
    return 3 + exp(-x);
}
int main()
{
    int i = 1;
    double x0, x1;
    double h;
    cout << "Enter the initial value: ";
    cin >> x0;
    cout << setw(width) << "Iteration";
    cout << setw(width) << "x0";
    cout << setw(width) << "f(x0)";
    cout << setw(width) << "g(x0)";
    cout << setw(width) << "x1" << endl;
    do
    {
        h = f(x0) / g(x0);
        x1 = x0 - h;

        cout << setw(width) << i;
        cout << setw(width) << setprecision(5) << x0;
        cout << setw(width) << setprecision(5) << f(x0);
        cout << setw(width) << setprecision(5) << g(x0);
        cout << setw(width) << setprecision(5) << x1 << endl;
        i++;
        // if (fabs(h) < e)
        // {
        //     cout << "After " << setw(3) << i << " iterations, root=" << setw(5) << setprecision(6) << x1;
        //     return 0;
        // }
        // i++;
        x0 = x1;
    } while (fabs(h) >= error);
    cout << "AFter " << setw(3) << i - 1 << " iterations, root = " << setw(8) << setprecision(6) << x1;
    return 0;
}