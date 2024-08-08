#include <bits/stdc++.h>
using namespace std;

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

void generate() {
    cout << 1 << endl;

    int n = rand_int(2, 5);

    int r = rand_int(10, 20);
    cout << n << ' ' << r << ' ' << rand_int(20, 120) << endl;

    for (int i = 0; i < n; i++) {
        int x, y;
        do {
            x = rand_int(-10, 10), y = rand_int(-10, 10);
        } while (x * x + y * y >= r * r);
        cout << x << ' ' << y << endl;
    }
}

int main(int argc, char **argv) {
    if (argc > 1) seed(atoi(argv[1]));
    generate();
    return 0;
}
