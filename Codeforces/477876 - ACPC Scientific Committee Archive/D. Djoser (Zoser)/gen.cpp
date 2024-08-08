#include <bits/stdc++.h>
using namespace std;

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rint(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

void generate() {
    int t = rint(1, 5);
    cout << t << endl;

    while (t--) {
        cout << rint(-10, 10) << ' ' << rint(-10, 10) << ' ' << rint(-10, 10) << ' ' << rint(-10, 10) << endl;
    }
}

int main(int argc, char **argv) {
    if (argc > 1) seed(atoi(argv[1]));
    generate();
    return 0;
}
