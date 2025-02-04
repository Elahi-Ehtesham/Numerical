#include <bits/stdc++.h>
using namespace std;
class RungeKutta_4th_order
{
private:
    /* data */
    double x0, y, h, x;
    double f(double x, double y)
    {
        return x + y * y; // 0 1 0.1 0.2 output=1.2736
        //  return ((x - y) / 2.0); //0 1 0.2 2
    }

public:
    RungeKutta_4th_order(double xin, double yin, double ini_h, double finx)
    {
        x0 = xin, y = yin;
        h = ini_h, x = finx;
        
    }
    void RungeKutta()
    {
        double k, k1, k2, k3, k4;
        while (x0 + h <= x)
        {
            /* code */
            k1 = h * f(x0, y);
            k2 = h * f(x0 + 0.5 * h, y + 0.5 * k1);
            k3 = h * f(x0 + 0.5 * h, y + 0.5 * k2);
            k4 = h * f(x0 + h, y + k3);
            k = (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
            y += k;
            x0 += h;
            cout << y << "\n";
        }
        cout << y << "\n";
    }
};

int main()
{
    double x0, y, h, x;
    cin >> x0 >> y >> h >> x;
    RungeKutta_4th_order rung(x0, y, h, x);
    rung.RungeKutta();
}
