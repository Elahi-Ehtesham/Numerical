#include <bits/stdc++.h>
using namespace std;

class EulerMethod
{
private:
    /* data */
    double x0, y0, h, x;
    double function(double x, double y)
    {
        // return x * x + y;
        return x + y * y; // 0 1 0.1 0.2 output=1.2736
    }

public:
    EulerMethod(double inx, double iny, double range, double finx)
    {
        x0 = inx, y0 = iny;
        h = range, x = finx;
    }
    void Euler()
    {
        while (x0 + h <= x)
        {
            y0 = y0 + h * function(x0, y0);
            x0 += h;
        }
        cout << y0 << "\n";
    }
};
int main()
{
    double x0, y0, h, x;
    cin >> x0 >> y0 >> h >> x;
    EulerMethod E(x0, y0, h, x);
    E.Euler();
}
