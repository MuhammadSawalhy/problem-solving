#include <bits/stdc++.h>
using namespace std;

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

void generate() {
    int n = rand_int(1, 10), q = rand_int(1, 5);

    cout << 1 << endl;
    cout << n << ' ' << q << endl;

    for (int i = 0; i < n; i++) {
        cout << rand_int(0, 7) << " \n"[i == n - 1];
    }

    while (q--) {
        int t = rand_int(1, 3);
        cout << t << ' ';
        if (t == 1) {
            int l = rand_int(1, n), r = rand_int(l, n), x = rand_int(0, 7);
            cout << l << ' ' << r << ' ' << x;
        } else if (t == 2) {
            cout << rand_int(1, n) << ' ' << rand_int(0, 7);
        } else {
            int l = rand_int(1, n), r = rand_int(l, n);
            cout << l << ' ' << r;
        }
        cout << endl;
    }
}

int main(int argc, char **argv) {
    if (argc > 1) seed(atoi(argv[1]));
    generate();
    return 0;
}
