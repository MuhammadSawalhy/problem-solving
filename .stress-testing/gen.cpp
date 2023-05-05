// ﷽
#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define all(v) v.begin(), v.end()

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int main(int argc, char *argv[]) {
    if (argc > 1) seed(atoi(argv[1]));

    int t = 1;
    cout << t << endl;
    while (t--) {
        int n = rand_int(1, 10);
        cout << n << endl;
        while (n--)
            cout << rand_int(1, 10) << ' ';
        cout << endl;
    }

    return 0;
}
