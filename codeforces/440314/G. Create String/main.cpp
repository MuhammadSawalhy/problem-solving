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

void solve() {
    int n;
    string s, t;
    cin >> s;
    n = s.length();
    vector<int> divs;
    for (int i = 1; i <= 26; i++)
        if (n % i == 0)
            divs.push_back(i);

    vector<int> fr(26);
    for (int i = 0; i < n; i++) fr[s[i] - 'a']++;
    sort(all(fr));
    int mn = 1e9, d;

    debug(s);
    for (auto div: divs) {
        div = n / div;
        int cost = 0;
        vector<int> ff = fr;

        int i = 0, j = 25;

        while (i < 26 && ff[i] < div) i++;
        i--;

        while (i < j) {
            while (ff[i] < div && ff[j] > div) {
                ff[i]++;
                ff[j]--;
                cost++;
            }
            if (ff[i] == div)
                i--;
            if (ff[j] == div)
                j--;
        }

        j = i;
        i = 0;

        while (i < j) {
            while (ff[i] > 0 && ff[j] < div) {
                ff[j]++;
                ff[i]--;
                cost++;
            }
            if (ff[i] == 0)
                i++;
            if (ff[j] == div)
                j--;
        }

        if (cost < mn) {
            mn = cost;
            d = div;
        }
    }

    int i = 0, j = 25;

    vector<pair<int, char>> ff(26);
    vector<vector<int>> ind(26);
    for (int i = 0; i < 26; i++) ff[i].second = 'a' + i;
    for (int i = 0; i < n; i++) {
        ff[s[i] - 'a'].first++;
        ind[s[i] - 'a'].push_back(i);
    }

    sort(all(ff));

    while (i < 26 && ff[i].first < d) i++;
    i--;

    t = s;
    while (i < j) {
        while (ff[i].first < d && ff[j].first > d) {
            // convert char of j to char of i
            ff[i].first++;
            ff[j].first--;
            int k = ind[ff[j].second - 'a'].back();
            ind[ff[j].second - 'a'].pop_back();
            t[k] = ff[i].second;
        }
        if (ff[i].first == d)
            i--;
        if (ff[j].first == d)
            j--;
    }

    j = i;
    i = 0;

    while (i < j) {
        while (ff[i].first > 0 && ff[j].first < d) {
            // convert char of i to char of j
            ff[j].first++;
            ff[i].first--;
            int k = ind[ff[i].second - 'a'].back();
            ind[ff[i].second - 'a'].pop_back();
            t[k] = ff[j].second;
        }
        if (ff[i].first == 0)
            i++;
        if (ff[j].first == d)
            j--;
    }

    cout << mn << endl;
    // cout << t << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
