#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class NewtonBackwardInterpolation {
private:
    vector<double> x, y;
    vector<vector<double>> differenceTable;
    int n;

public:
    NewtonBackwardInterpolation(vector<double> x_vals, vector<double> y_vals) {
        x = x_vals;
        y = y_vals;
        n = x.size();
        differenceTable.resize(n, vector<double>(n, 0));
        buildDifferenceTable();
    }

    void buildDifferenceTable() {
        // Fill the first column with y values
        for (int i = 0; i < n; i++) {
            differenceTable[i][0] = y[i];
        }

        // Compute backward differences
        for (int j = 1; j < n; j++) {
            for (int i = n - 1; i >= j; i--) {
                differenceTable[i][j] = differenceTable[i][j - 1] - differenceTable[i - 1][j - 1];
            }
        }
    }

    void printDifferenceTable() {
        cout << "\nBackward Difference Table:\n";
        for (int i = 0; i < n; i++) {
            cout << setw(5) << x[i] << " |";
            for (int j = 0; j <= i; j++) {
                cout << setw(10) << differenceTable[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to calculate factorial
    int factorial(int num) {
        int fact = 1;
        for (int i = 2; i <= num; i++) {
            fact *= i;
        }
        return fact;
    }

    // Function to compute u * (u+1) * (u+2) ... / factorial
    double computeUTerm(double u, int term) {
        double uTerm = 1;
        for (int i = 0; i < term; i++) {
            uTerm *= (u + i);
        }
        return uTerm / factorial(term);
    }

    double interpolate(double value) {
        double h = x[1] - x[0]; // Step size
        double u = (value - x[n - 1]) / h; // u = (x - x_n) / h
        double result = differenceTable[n - 1][0]; // Initialize with y_n

        // Compute interpolation using Newton's Backward formula
        for (int i = 1; i < n; i++) {
            result += computeUTerm(u, i) * differenceTable[n - 1][i];
        }
        return result;
    }
};

int main() {
    // Sample data points
    vector<double> x = {0, 1, 2, 3, 4}; 
    vector<double> y = {1, 2, 4, 8, 16}; // Example dataset: y = 2^x

    NewtonBackwardInterpolation interpolator(x, y);
    interpolator.printDifferenceTable();

    double value = 3.5;
   // cout << "\nEnter the value to interpolate: ";
   // cin >> value;

    double result = interpolator.interpolate(value);
    cout << "Interpolated value at x = " << value << " is " << result << endl;

    return 0;
}
