#include<bits/stdc++.h>
using namespace std;

class NewtonDividedDifference {
private:
    vector<double> x, y;
    vector<vector<double>> dividedDifferenceTable;
    int n;

public:
    // Constructor
    NewtonDividedDifference(vector<double> x_vals, vector<double> y_vals) {
        x = x_vals;
        y = y_vals;
        n = x.size();
        dividedDifferenceTable.resize(n, vector<double>(n, 0));
        buildDividedDifferenceTable();
    }

    // Build divided difference table
    void buildDividedDifferenceTable() {
        for (int i = 0; i < n; i++) {
            dividedDifferenceTable[i][0] = y[i]; // First column is y values
        }

        for (int j = 1; j < n; j++) { // Columns
            for (int i = 0; i < n - j; i++) { // Rows
                dividedDifferenceTable[i][j] = 
                    (dividedDifferenceTable[i + 1][j - 1] - dividedDifferenceTable[i][j - 1]) / 
                    (x[i + j] - x[i]);
            }
        }
    }

    // Print the divided difference table
    void printDividedDifferenceTable() {
        cout << "\nDivided Difference Table:\n";
        for (int i = 0; i < n; i++) {
            cout << setw(5) << x[i] << " |";
            for (int j = 0; j < n - i; j++) {
                cout << setw(12) << dividedDifferenceTable[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Evaluate the interpolation at a given value
    double interpolate(double value) {
        double result = dividedDifferenceTable[0][0]; // First term in formula
        double productTerm = 1.0;

        for (int i = 1; i < n; i++) {
            productTerm *= (value - x[i - 1]); // Compute (x - x0)(x - x1)...
            result += productTerm * dividedDifferenceTable[0][i];
        }

        return result;
    }
};

int main() {
    // Sample data points (x, y)
    vector<double> x = {1, 2, 4, 5}; 
    vector<double> y = {1, 4, 16, 25}; // Example dataset: y = x^2

    NewtonDividedDifference interpolator(x, y);
    interpolator.printDividedDifferenceTable();

    double value = 4.5;
    // cout << "\nEnter the value to interpolate: ";
    // cin >> value;

    double result = interpolator.interpolate(value);
    cout << "Interpolated value at x = " << value << " is " << result << endl;

    return 0;
}
