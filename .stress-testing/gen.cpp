#include <bits/stdc++.h>
using namespace std;

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

void generate() {
    int n = rand_int(2, 20), q = rand_int(1, 5);

    cout << n << ' ' << q << endl;

    while (q--) {
        int l = rand_int(1ll, n - 1);
        int r = rand_int(l + 1, n);
        cout << l << ' ' << r << endl;
    }
}

int main(int argc, char **argv) {
    if (argc > 1) seed(atoi(argv[1]));
    generate();
    return 0;
}
