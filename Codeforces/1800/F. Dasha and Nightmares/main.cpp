// ﷽
#include <algorithm>
#include <array>
#include <assert.h>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define ll long long
#define all(v) v.begin(), v.end()

const int N = 2e5;
int n, words[N][26];
bool valid[N];
vector<int> fr(1 << 26);

ll solve(char missing) {
    for (int i = 0; i < 1 << 26; i++) {
        fr[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (words[i][missing])
            valid[i] = false;
        else
            valid[i] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!valid[i]) continue;
        int key = 0;
        for (char c = 0; c < 26; c++) {
            key ^= (words[i][c] & 1) << c;
        }
        fr[key]++;
    }

    debug((char)('a' + missing));

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (!valid[i]) continue;
        int comp = 0;

        for (int c = 0; c < 26; c++) {
            if (c == missing) continue;
            if (words[i][c] & 1 ^ 1)
                comp ^= 1 << c;
        }

        ans += fr[comp];
    }

    assert(ans % 2 == 0);
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    string w;
    for (int i = 0; i < n; i++) {
        cin >> w;
        for (char c: w)
            words[i][c - 'a']++;
    }

    ll ans = 0;
    for (int c = 0; c < 26; c++) {
        ans += solve(c);
    }

    assert(ans % 2 == 0);
    cout << ans / 2 << endl;
    return 0;
}

