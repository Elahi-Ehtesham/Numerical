#include <bits/stdc++.h>
using namespace std;
struct Points
{
    double x, y;
};
class LeastSquareCurve
{
public:
    Points least_square_method(vector<Points> point)
    {
        int n = point.size();
        Points res;
        double x = 0, y = 0, xsq = 0, xy = 0;
        for (auto it : point)
        {
            x += it.x;
            y += it.y;
            xy = xy + (it.x * it.y);
            xsq = xsq + (it.x * it.x);
        }
        res.y = (n * xy - x * y) / (n * xsq - (x * x));
        res.x = y / n - res.y * (x / n);
        return res;
    }
};
int main()
{
    LeastSquareCurve C;
    vector<Points> point;
    double x, y;
    while (cin >> x >> y)
    {
        point.push_back({x, y});
    }
    Points p = C.least_square_method(point);
    cout << p.x;
    if (p.y < 0)
    {
        cout << "-" << abs(p.y) << "x\n";
    }
    else
    {
        cout << "+" << abs(p.y) << "x\n";
    }
}
