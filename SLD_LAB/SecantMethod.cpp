#include <bits/stdc++.h>
using namespace std;

class SecantMethod {
private:
    double tolerance;
    int maxIterations;

    double function(double x) {
        return x * x - 8;
    }

    double randomInRange(double min, double max) {
        return min + ((double)rand() / (RAND_MAX / (max - min)));
    }

public:
    SecantMethod(double tolerance, int maxIterations)
        : tolerance(tolerance), maxIterations(maxIterations) {}

    double findRoot() {

        srand(time(0));
        double x0 = randomInRange(-10, 10);
        double x1 = randomInRange(-10, 10);

        for (int i = 0; i < maxIterations; i++) {
            double f0 = function(x0);
            double f1 = function(x1);
            if (abs(f1) < tolerance)
                return x1;
            if (f1 - f0 == 0) {
                cerr << "Division by zero error. No solution found.\n";
                return NAN;
            }
            double x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
            x0 = x1;
            x1 = x2;
        }
        cerr << "Maximum iterations reached.\n";
        return x1;
    }
};

int main() {
    cout << setprecision(4) ;
    SecantMethod solve(1e-6, 20);
    cout << "Root: " << solve.findRoot() << endl;
}