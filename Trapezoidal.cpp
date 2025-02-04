// #include <bits/stdc++.h>
// using namespace std;
// double funct(double x)
// {
//     return 1.0 / (1 + x);
// }
// void trapezoidal(double l, double r, double n)
// {
//     double sum = .5 * (funct(l) + funct(r));
//     double h=(r-l)/n;
//     for(int i=1;i<n;i++)
//     {
//         sum=sum+funct(l+i*h);
//     }
//     cout<<h*sum<<"\n";
// }
// int main()
// {
//     double l, r, n;
//     cin >> l >> r >> n;
//     trapezoidal(l,r,n);
// }

#include <bits/stdc++.h>
using namespace std;
class Trapezoidal
{
private:
    double n, h;
    vector<double> x, y;
    double func(double x)
    {
        return 1.0 / (1 + x);
    }

public:
    void traproot(double l, double r, double n)
    {
        h = (r - l) / n;
        double sum = 0.5 * (func(l) + func(r));
        for (int i = 1; i < n; i++)
        {
            sum = sum + func(i * h + l);
        }
        cout << "print the result " << sum * h << endl;
    }
};
int main()
{
    Trapezoidal trapezoidal;
    double a, b, n;
    cout << "Enter the value of a b & n" << endl;
    // the more u increase the value of n the ans will be more accurate
    cin >> a >> b >> n;
    trapezoidal.traproot(a, b, n);
}