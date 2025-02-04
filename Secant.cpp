#include<bits/stdc++.h>

using namespace std;

const double dif = 1e-6;

class Secant{
    public:
    double f(double x){
        return x*x*x*x -x - 10;
      //  return x*x*x*x + x*x - 2;
    }

    double secant(double x1, double x2){
        cout << x1 << " " << x2 << endl;
        double root;
        while (abs(x2 - x1) > dif) {
            root = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
          //  cout << root << endl;
            x1 = x2;
            x2 = root;
        }
        return root;
    }
};

int main()
{
    cout << fixed << setprecision(6);
    srand(time(0));

    Secant sec;
    double x1 = (rand()%201-100)/10.0, x2=(rand()%201-100)/10.0;
    //cin >> x1 >> x2;
    if(x1>x2)
    swap(x1,x2);
    double ans = sec.secant(x1, x2);
    cout << ans << endl;
    double root = rand();

    return 0;
}
