#include <bits/stdc++.h>
using namespace std;

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

void generate() {
    cout << 1 << endl;

    cout << rand_int(-5, 5) << ' ';
    cout << rand_int(-5, 5) << ' ';

    cout << rand_int(-5, 5) << ' ';
    cout << rand_int(-5, 5) << ' ';

    cout << rand_int(-5, 5) << ' ';
    cout << rand_int(-5, 5) << ' ';

    cout << rand_int(-5, 5) << ' ';
    cout << rand_int(-5, 5) << ' ';

    cout << rand_int(0, 1) << ' ';

    cout << endl;
}

int main(int argc, char **argv) {
    if (argc > 1) seed(atoi(argv[1]));
    generate();
    return 0;
}
