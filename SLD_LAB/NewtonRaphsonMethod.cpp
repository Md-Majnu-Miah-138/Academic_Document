#include <bits/stdc++.h>
using namespace std;

class NewtonRaphsonMethod {
private:
    double tolerance;
    int maxIterations;

    double function(double x) {
        return x * x - 8;
    }

    double derivative(double x) {
        return 2 * x;
    }

    double randomInRange(double min, double max) {
        return min + ((double)rand() / (RAND_MAX / (max - min)));
    }

public:
    NewtonRaphsonMethod(double tolerance, int maxIterations)
        : tolerance(tolerance), maxIterations(maxIterations) {}

    double findRoot() {
        srand(time(0));
        double x = randomInRange(-10, 10);
        for (int i = 0; i < maxIterations; i++) {
            double fx = function(x);
            double dfx = derivative(x);
            if (abs(fx) < tolerance)
                return x;
            if (dfx == 0) {
                cerr << "Derivative is zero. No solution found.\n";
                return NAN;
            }
            x = x - fx / dfx;
        }
        cerr << "Maximum iterations reached.\n";
        return x;
    }
};

int main() {
    cout << setprecision(6) ;
    NewtonRaphsonMethod solve(1e-6, 20);
    cout << "Root: " << solve.findRoot() << endl;
}