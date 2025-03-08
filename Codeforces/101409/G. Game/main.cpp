#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("game.in");
    ofstream out("game.out");

    int n;
    in >> n;

    for (int i = 0; i < n; ++i) {
        long long k, m;
        in >> k >> m;

        double a = 2 * m - k;
        double b = 4 * m - k;

        out << fixed << setprecision(9) << a / b << endl;
    }

    return 0;
}

