#include <bits/stdc++.h>
using namespace std;

class FalsePositionMethod {
private:
    double a, b, tolerance;
    int maxIterations;

    double function(double x) {
        return x * x - 8;
    }

    double randomInRange(double min, double max) {
        return min + ((double)rand() / (RAND_MAX / (max - min)));
    }

public:
    FalsePositionMethod(double tolerance, int maxIterations)
        : tolerance(tolerance), maxIterations(maxIterations) {}

    double findRoot() {

        srand(time(0));
        do {
            a = randomInRange(-10, 10);
            b = randomInRange(-10, 10);
        } while (function(a) * function(b) >= 0);

        double c;
        for (int i = 0; i < maxIterations; i++) {
            c = (a * function(b) - b * function(a)) / (function(b) - function(a));
            if (abs(function(c)) < tolerance)
                return c;
            if (function(a) * function(c) < 0)
                b = c;
            else
                a = c;
        }
        cerr << "Maximum iterations reached.\n";
        return c;
    }
};

int main() {
    cout << setprecision(4) ;
    FalsePositionMethod solve(1e-6, 20);
    cout << "Root: " << solve.findRoot() << endl;
}