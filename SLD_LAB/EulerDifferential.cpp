#include<bits/stdc++.h>
using namespace std;

class Euler {
private:
    double x0, y, h, x;
    double function (double x, double y) {
        return x + y + x * y;   // x+y+xy
    }

public:
    Euler (double ini_x, double ini_y, double step, double xx) {
        x0 = ini_x, y = ini_y, h = step;
        x = xx;
    }
    void solve () {
        while (x0 < x) {
            y = y + h * function(x0, y);
            x0 = x0 + h;
        }
        cout << y << endl;
    }
};

int main () {
    double x0 = 0, y0 = 1, x = 0.1, h = 0.025;
    // cin >> x0 >> y0 >> h;
    // cin >> x;
    Euler euler(x0, y0, h, x);
    euler.solve();
}

/*
input:
x0 = 0, y0 = 1, h = 0.025, x = 0.1
0 1 0.025 0.1

output:
1.11167
*/