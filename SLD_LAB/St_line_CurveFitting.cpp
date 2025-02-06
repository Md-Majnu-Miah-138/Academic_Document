#include <bits/stdc++.h>
using namespace std;

class LeastSquares {
private:
    vector<double> x, y;
    double a0 = 0.0, a1 = 0.0;

public:
    LeastSquares(const vector<double>& x_vals, const vector<double>& y_vals) : x(x_vals), y(y_vals) {}

    void fit() {
        int n = x.size();
        double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;

        for (int i = 0; i < n; ++i) {
            sum_x += x[i];
            sum_y += y[i];
            sum_xy += x[i] * y[i];
            sum_x2 += x[i] * x[i];
        }

        double denominator = (n * sum_x2 - sum_x * sum_x);
        if (denominator == 0) {
            cerr << "Error: Division by zero in calculations!" << endl;
            return;
        }

        a1 = (n * sum_xy - sum_x * sum_y) / denominator;
        a0 = (sum_y - a1 * sum_x) / n;
    }

    inline double predict(double x_val) const {
        return a0 + a1 * x_val;
    }

    void displayEquation() const {
        cout << fixed << setprecision(4);
        cout << "The best-fit line: y = " << a0 << " + " << a1 << "x" << endl;
    }
};

int main() {
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {2, 3, 5, 7, 11};

    LeastSquares model(x, y);
    model.fit();
    model.displayEquation();

    double test_x = 6.0;
    cout << "Predicted y for x = " << test_x << " is " << model.predict(test_x) << endl;

    return 0;
}
