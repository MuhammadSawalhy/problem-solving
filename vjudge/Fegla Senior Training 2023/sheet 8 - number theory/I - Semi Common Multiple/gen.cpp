// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define all(v) v.begin(), v.end()

int gen(int a = 1, int b = 10) { return a + rand() % (b - a + 1); }

string genstr(int len) {
    string s;
    for (int i = 0; i < len; i++) 
        s += 'a' + gen(0, 25);
    return s;
}

int main(int argc, char *argv[]) {
    if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));
    int t = 1;
    // cout << t << endl;
    while (t--) {
        int n, m;
        n = gen(1, 3);
        m = gen(1, 1e9);
        cout << n << ' ' << m << endl;
        while (n--)
            cout << gen(1, 20) * 2 << " ";
        cout << endl;
    }

    return 0;
}
