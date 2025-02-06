#include <bits/stdc++.h>
using namespace std;

class ForwardInterpolation {
private:
    vector<double> x, y;
    vector<vector<double>> diffTable;
    vector<long double> factorials;

    // Function to precompute factorial values
    void precomputeFactorials(int n) {
        factorials.resize(n + 1);
        factorials[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorials[i] = factorials[i - 1] * i;
        }
    }

    // Function to build the forward difference table
    void buildDiffTable() {
        int n = x.size();
        diffTable.resize(n, vector<double>(n, 0.0));

        for (int i = 0; i < n; i++) 
            diffTable[i][0] = y[i];

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n - j; i++) {
                diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
            }
        }
    }

public:
    ForwardInterpolation(const vector<double>& xx, const vector<double>& yy) 
        : x(xx), y(yy) {
        buildDiffTable();
        precomputeFactorials(x.size());
    }

    // Function to display the forward difference table
    void displayDiffTable() {
        cout << "Forward Difference Table:\n";
        int n = x.size();
        for (int i = 0; i < n; i++) {
            cout << setw(5) << x[i] << " |";
            for (int j = 0; j < n - i; j++) {
                cout << setw(10) << diffTable[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Function to perform forward interpolation
    long double interpolate(double value) {
        int n = x.size();
        double h = x[1] - x[0];
        double p = (value - x[0]) / h;
        long double result = y[0];
        long double pTerm = 1;

        for (int i = 1; i < n; i++) {
            pTerm *= (p - (i - 1));  // Compute p * (p-1) * (p-2)...
            result += (pTerm * diffTable[0][i]) / factorials[i];
        }

        return result;
    }
};

int main() {
    vector<double> x = {1, 3, 5, 7};
    vector<double> y = {24, 120, 336, 720};
    double value = 4;

    ForwardInterpolation interpolator(x, y);
    interpolator.displayDiffTable();

    long double result = interpolator.interpolate(value);
    cout << "Interpolated value at x = " << value << " is " << result << endl;

    return 0;
}