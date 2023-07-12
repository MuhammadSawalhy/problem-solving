// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int gen(int a = 1, int b = 10) { return a + rand() % (b - a + 1); }

int countbits(int n) {
    return __builtin_popcount(n);
}

void interact() {
    int n = gen(), initial = n;
    cout << countbits(n) << endl;

    int x, cnt = 0;
    char t;
    while (true) {
        assert(++cnt <= 30);
        cin >> t >> x;
        if (t == '!') {
            assert(x == initial);
            return;
        } else {
            n -= x;
            assert(n >= 0);
            cout << countbits(n) << endl;
        }
    }
}

int32_t main(int32_t argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));

    int t = 1;
    cout << t << endl;
    while (t--) {
        interact();
    }

    return 0;
}
