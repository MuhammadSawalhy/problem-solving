#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


void solve() {
    string s;
    cin >> s;

    int a, b, ab, ba;
    cin >> a >> b >> ab >> ba;

    vector<int> A, B, AB, BA;
    int n = s.size();

    debug(s);
    debug(a, b, ab, ba);

    for (int i = 0, j = 0; i < n;) {
        j = i + 1;
        while (j < n && (s[i] == s[j] && (j - i) % 2 == 0 || s[i] != s[j] && (j - i) % 2 == 1)) j++;

        if ((j - i) % 2 == 0) {
            if (s[i] == 'A') AB.push_back(j - i);
            if (s[i] == 'B') BA.push_back(j - i);
        } else {
            if (s[i] == 'A') A.push_back(j - i);
            if (s[i] == 'B') B.push_back(j - i);
        }

        i = j;
    }

    debug(A);
    debug(B);
    debug(AB);
    debug(BA);

    sort(AB.rbegin(), AB.rend());
    sort(BA.rbegin(), BA.rend());

    int aa = 0, bb = 0, abb = 0, baa = 0;

    for (int i = 0; i < AB.size(); i++) {
        abb += AB[i] / 2;
    }

    for (int i = 0; i < BA.size(); i++) {
        baa += BA[i] / 2;
    }

    for (int i = 0; abb > ab && i < AB.size(); i++) {
        aa++, bb++;
        abb--;
        int d = min(abb - ab, AB[i] / 2 - 1);
        abb -= d;
        baa += d;
    }

    for (int i = 0; baa > ba && i < BA.size(); i++) {
        aa++, bb++;
        baa--;
        int d = min(baa - ba, BA[i] / 2 - 1);
        baa -= d;
        abb += d;
    }

    debug(aa, bb, abb, baa);

    aa += A.size();
    bb += B.size();

    for (int i = 0; i < A.size(); i++) {
        int d = max(0ll, min(ab - abb, A[i] / 2));
        abb += d;
        baa += A[i] / 2 - d;
    }

    for (int i = 0; i < B.size(); i++) {
        int d = max(0ll, min(ab - abb, B[i] / 2));
        abb += d;
        baa += B[i] / 2 - d;
    }

    int d = max(0ll, abb - ab);
    aa += d;
    bb += d;
    abb -= d;

    d = max(0ll, baa - ba);
    aa += d;
    bb += d;
    baa -= d;

    debug(aa, bb, abb, baa);

    if (aa > a || bb > b) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
