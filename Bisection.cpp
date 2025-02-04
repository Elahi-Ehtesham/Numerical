
#include <bits/stdc++.h>
using namespace std;
class Bisection
{
private:
    double tolerance;
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
        } while (function(a) * function(b) >= 0);
        if (a > b)
            swap(a, b);
    }

public:
    Bisection(double tol)
    {
        tolerance = tol;
        randomgeneration();
    }
    void bisetionmethod()
    {
        cout << a << " " << b << "\n";
        if (function(a) * function(b) > 0)
        {
            cout << "No solution in this range\n";
            return;
        }
        double c;
        while ((b - a) > tolerance)
        {
            c = (a + b) / 2;
            if (abs(function(c)) < tolerance)
            {
                break;
            }
            else if (function(c) * function(b) < 0)
                a = c;
            else
                b = c;
        }
        cout << "The root is " << c << "\n";
    }
};
int main()
{
    srand(time(0));
    double t = .001;
    Bisection bis(t);
    bis.bisetionmethod();
}
