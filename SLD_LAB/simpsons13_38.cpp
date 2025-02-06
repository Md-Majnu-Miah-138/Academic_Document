#include<bits/stdc++.h>
using namespace std;

class Simpsons {
private:
    vector<double> y, x;
    int n;
    double a, b, h;

    double function (double x) {
        // 1 / x
        return 1.0 / (1 + x * x);
    }

public:
    Simpsons (double l, double r, int size) {
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
    void simpsons_1_3 () {
        if(n & 1) {
            cout << "This rule doesn't apply!\n";
            return;
        }
        double area = y[0] + y[n];
        double odd = 0.0, even = 0.0;
        for(int i = 1 ; i < n ; i++) {
            if(i & 1)
                odd += y[i];
            else
                even += y[i];
        }
        area += 4.0 * odd;
        area += 2.0 * even;
        area *= h / 3.0;
        cout << "Approximate Integral: " << area << endl;
    }
    void simpsons_3_8 () {
        if(n % 3) {
            cout << "This rule doesn't apply!\n";
            return;
        }
        double area = y[0] + y[n];
        double multi3 = 0.0, other = 0.0;
        for(int i = 1 ; i < n ; i++) {
            if(i %3)
                other += y[i];
            else
                multi3 += y[i];
        }
        area += 3.0 * other;
        area += 2.0 * multi3;
        area *= (3.0 * h) / 8.0;
        cout << "Approximate Integral: " << area << endl;
    }
};

int main () {
    int n=6;
    double a=0, b=1;
   // cin >> a >> b >> n;

    Simpsons simp (a, b, n);
    simp.simpsons_1_3();
    simp.simpsons_3_8();
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