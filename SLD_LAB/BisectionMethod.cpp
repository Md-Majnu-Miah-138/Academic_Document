#include <bits/stdc++.h>
using namespace std;

class BisectionMethod {
private:
    double a, b, tolerance;
    int maxIterations;

    double function(double x) {
        return x * x - 8;
    }

    double randomInRange(double min, double max) {
        return min + (((double)rand() / RAND_MAX) * (max - min));
    }

public:
    BisectionMethod(double tolerance, int maxIterations)
        : tolerance(tolerance), maxIterations(maxIterations) {}

    double findRoot() {
         srand(time(0)); 

        do {
            a = randomInRange(-10, 10); 
            b = randomInRange(-10, 10); 
        } while (function(a) * function(b) >= 0); 
        double mid;
        for (int i = 0; i < maxIterations; i++) {
            mid = (a + b) / 2.0;
            if (abs(function(mid)) < tolerance)
                return mid;
            if (function(a) * function(mid) < 0)
                b = mid;
            else
                a = mid;
        }
        cerr << "Maximum iterations reached.\n";
        return mid;
    }
};

int main() {
    cout << setprecision(4) ;
    BisectionMethod solve(1e-6, 20);
    cout << "Root: " << solve.findRoot() << endl;
}