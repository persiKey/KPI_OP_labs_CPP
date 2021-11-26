#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::pow;

void init(double &a, double &b);
double min(const double x, const double y);
void display(const double u, const double v, const double w);

int main()
{
    double A, B;
    init(A,B);
    double U, V, W;
    U = min(A,B);
    V = min(A*B, A+B);
    W = min(U + pow(V,2), M_PI);
    display(U, V, W);

    system("pause");
    return 0;
}

void init(double &a, double &b)
{
    cout << "\nInput:\n";
    cout << "\tA = "; cin >> a;
    cout << "\tB = "; cin >> b;
}

double min(const double x, const double y)
{
    return x < y ? x : y;
}
void display(const double u, const double v, const double w)
{
    cout << "\nResult:";
    cout << "\n\tU = " << u;
    cout << "\n\tV = " << v;
    cout << "\n\tW = " << w << '\n';
}