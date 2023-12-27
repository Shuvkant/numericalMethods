#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double f(double x) {
    // return pow(x, 3) -  pow(x,2) - 1;
    return 2*x*x*x+4*x*x-4*x-6;
}

int main() {
    double x0, x1, x2, fx2, e =0.0005;
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
    cout << setw(8) << "fx1";
    cout << setw(8) << "fx2";
    cout << setw(12) << "xn" << endl;

    do {
        x2 = x1-((x1-x0)/(f(x1)-f(x0)))*f(x1);
        


        cout << setw(9) << ++i;
        cout << setw(8) << setprecision(4) << x0;
        cout << setw(8) << setprecision(4) << x1;
        cout << setw(12) << setprecision(4) << f(x1);
        cout << setw(12) << setprecision(4) << f(x2);
        cout << setw(8) << setprecision(4) << x2<<endl;
        x0=x1;
        x1=x2;

    } while (abs(f(x2)) > e);

    cout << "The required root is " << x2 << endl;

    return 0;
}