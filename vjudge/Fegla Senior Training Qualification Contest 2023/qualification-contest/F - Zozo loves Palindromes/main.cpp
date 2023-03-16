// ﷽
#include <algorithm>
#include <array>
#include <assert.h>
#include <iostream>
#include <map>
#include <queue>
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

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

// 991299999199

vector<int> s;

void inc(int i) {
    s[i]++;
    while (i > 0 && s[i] == 10) {
        s[i - 1]++;
        s[i] = 0;
        i--;
    }
}

void fix(int i, int j) {
    if (s[i] == s[j]) return;
    if (s[j] > s[i])
        inc(j - 1);
    s[j] = s[i];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string ss;
    cin >> ss;

    int n = ss.size();

    if (ss == string(n, '9')) {
        ss = '1' + string(n, '0');
        n++;
        for (int i = 0; i < n; i++)
            s.push_back(ss[i] - '0');
    } else {
        for (int i = 0; i < n; i++)
            s.push_back(ss[i] - '0');
        inc(n - 1);
    }

    for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
        fix(i, j);
    }

    for (int i = 0; i < n; i++)
        cout << s[i];
    cout << endl;

    return 0;
}
