#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double f(double x) {
    return pow(x, 3) -  pow(x,2) - 1;
}

int main() {
    double x0, x1, x2, fx2, e = pow(10, -4);
    int i = 0;
    bool flag;

    do {
        flag = false;
        cout << "Enter two initial guesses: ";
        cin >> x0 >> x1;

        if (f(x0) * f(x1) >= 0) {
            cout << "The given values do not enclose a root.";
            flag = true;
        }
    } while (flag);

    cout << setw(9) << "Iteration";
    cout << setw(8) << "x0";
    cout << setw(8) << "x1";
    cout << setw(8) << "x2";
    cout << setw(12) << "fx2" << endl;

    do {
        x2 = (x0 + x1) / 2;
        fx2 = f(x2);

        cout << setw(9) << ++i;
        cout << setw(8) << setprecision(4) << x0;
        cout << setw(8) << setprecision(4) << x1;
        cout << setw(8) << setprecision(4) << x2;
        cout << setw(12) << setprecision(4) << fx2 << endl;

        if (fx2 < 0) {
            x0 = x2;
        } else {
            x1 = x2;
        }
    } while (abs(fx2) > e);

    cout << "The required root is " << x2 << endl;

    return 0;
}