#include<bits/stdc++.h>
using namespace std;

class Integration_Trapezoidal {
private:
    vector<double> y, x;
    double a, b, h;
    int n;

    double function (double x) {
        // 1 / x
        return 1.0 / (1 + x * x);
    }

public:
    Integration_Trapezoidal (double l, double r, int size) {
        n = size, a = l, b = r;
        y.resize(n + 1);
        x.resize(n + 1);
        h = (b - a) / (1.0 * n);

        x[0] = l;
        y[0] = function(x[0]);
        for(int i = 1 ; i <= n ; i++) {
            x[i] = x[i - 1] + h;
            y[i] = function (x[i]);
        }
    }
    void solve () {
        double area = 0.0;
        area += (y[0] + y[n]) / 2.0;
        for(int i = 1 ; i < n ; i++)
            area += y[i];
        area *= h;
        cout << "Approximate Integral: " << area << endl;
    }
};

int main () {
    
    double a=0, b=1;
    int n=6;
   // cin >> a >> b >> n;
   
    Integration_Trapezoidal inte(a, b, n);
    inte.solve();
    return 0;
}

/*
input:
a = 0, b = 1, n = 6
equation: 1/(1+x^2)
output:
0.7842

input:
a = 1, b = 2, n = 3
equation: 1/x
output:
0.70
*/