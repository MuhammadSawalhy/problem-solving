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

int gen(int a = 1, int b = 10) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
    if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));

    int t = 1;
    cout << t << endl;
    while (t--) {
        int n = gen(), k = gen();
        cout << n << ' ' << k << endl;
        int l = 0, r = 0;
        int L[n], R[n];
        for (int i = 0; i < n; i++) {
            l = gen(r + 1, (r + 1) * 2), r = gen(l, 2 * l);
            L[i] = l, R[i] = r;
        }

        for (int i = 0; i < n; i++)
            cout << L[i] << ' ';
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << R[i] << ' ';
        cout << endl;
    }

    return 0;
}
