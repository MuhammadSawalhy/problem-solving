#include <bits/stdc++.h>
using namespace std;

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

void generate() {
    string s;
    int n = rand_int(5, 10);
    for (int i = 1; i <= n; i++) s += '0' + rand_int(1, 9);
    cout << s << endl;
    cout << rand_int(1, 20) << endl;
}

int main(int argc, char **argv) {
    if (argc > 1) seed(atoi(argv[1]));
    generate();
    return 0;
}
