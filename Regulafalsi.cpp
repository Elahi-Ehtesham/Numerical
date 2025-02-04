#include <bits/stdc++.h>
using namespace std;
class RegulaFalsi
{
    double tolerance;
    int maxit;
    double a, b;
    double function(double x)
    {
        return x * x * x * x - x - 10;
    }
    void randomgeneration()
    {
        do
        {
            a = (rand() % 1001 - 500) / 10.0;
            b = (rand() % 1001 - 500) / 10.0;
        } while (function(a) * function(b) > 0);
        if (a > b)
            swap(a, b);
    }

public:
    RegulaFalsi(double tol, int mit)
    {
        tolerance = tol, maxit = mit;
        randomgeneration();
    }
    void falseposition()
    {
        cout << a << " " << b << "\n";
        double c;
        for (int i = 0; i < maxit; i++)
        {
            c = (a * function(b) - b * function(a)) / (function(b) - function(a));
            if (fabs(function(c)) < tolerance)
            {
                break;
            }
            if (function(c) * function(a) < 0)
                b = c;
            else
                a = c;
        }
        cout << c << "\n";
    }
};
int main()
{
    srand(time(0));
    double tol = .001;
    int it = 100;
    RegulaFalsi falsi(tol, 100);
    falsi.falseposition();
}
