#include <bits/stdc++.h>
using namespace std;

class LagrangeInterpolation {
private:
    vector<double> x, y;

public:
    LagrangeInterpolation(vector<double> x, vector<double> y)
        : x(x), y(y) {}

    double interpolate(double xi) {
        int n = x.size();
        double result = 0;
        for (int i = 0; i < n; i++) {
            double term = y[i];
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    term *= 1.0*(xi - x[j]) / (x[i] - x[j]);
                }
            }
            result += term*1.0;
        }
        return result;
    }
};

int main() {
    vector<double> x = {0, 1, 2, 3, 4};
    vector<double> y = {1, 2, 4, 8, 16};
    LagrangeInterpolation solver(x, y);
    double xi = 2.5;
    cout << "Interpolated value at x = " << xi << ": " << solver.interpolate(xi) << endl;
}