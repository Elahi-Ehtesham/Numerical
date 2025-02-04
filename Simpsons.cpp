#include <bits/stdc++.h>
using namespace std;
double fun(double x)
{
    return 1.0 / (1 + x);
}
void simpsons(double l, double r, double n)
{
    double h = (r - l) / n;
    double sum = fun(l) + fun(r);
    for (int i = 1; i < n; i++)
    {
        double x = l + i * h;
        if (i % 2 == 0)
        {
            sum = sum + 2 * fun(x);
        }
        else
        {
            sum = sum + 4 * fun(x);
        }
    }
    cout << (h * sum) / 3.0 << "\n";
}
int main()
{
    double l, r, n;
    cin >> l >> r >> n;
    simpsons(l, r, n);
}