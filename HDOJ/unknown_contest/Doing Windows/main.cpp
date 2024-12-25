#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll w, h;
ll ww[4], wh[4];

pair<ll, ll> horizontal(vector<pair<ll, ll>> sizes) {
    ll common_h = 1;
    for (auto [w, h]: sizes) {
        common_h = lcm(common_h, h);
    }
    ll total_w = 0;
    for (auto [w, h]: sizes) {
        total_w += common_h / h * w;
    }
    ll g = gcd(total_w, common_h);
    return {total_w / g, common_h / g};
}

pair<ll, ll> vertical(vector<pair<ll, ll>> sizes) {
    ll common_w = 1;
    for (auto [w, h]: sizes) {
        common_w = lcm(common_w, w);
    }
    ll total_h = 0;
    for (auto [w, h]: sizes) {
        total_h += common_w / w * h;
    }
    ll g = gcd(total_h, common_w);
    return {common_w / g, total_h / g};
}

bool solve(int w, int h, int used) {
    if ((h == 0 || w == 0) && used == 15) return true;
    if (h <= 0 || w <= 0 || used == 15) return false;

    for (int mask = 1; mask < 16; mask++) {
        if (mask & used) continue;
        vector<pair<ll, ll>> sizes;
        for (int i = 0; i < 4; i++) {
            if (mask & (1 << i)) {
                sizes.push_back({ww[i], wh[i]});
            }
        }
        {
            auto [ww, wh] = horizontal(sizes);
            if (w % ww == 0) {
                ll neww = w;
                ll newh = h - wh * w / ww;
                if (solve(neww, newh, mask | used)) return true;
            }
            if (h % wh == 0) {
                ll newh = h;
                ll neww = w - ww * h / wh;
                if (solve(neww, newh, mask | used)) return true;
            }
        }
        {
            auto [ww, wh] = vertical(sizes);
            if (w % ww == 0) {
                ll neww = w;
                ll newh = h - wh * w / ww;
                if (solve(neww, newh, mask | used)) return true;
            }
            if (h % wh == 0) {
                ll newh = h;
                ll neww = w - ww * h / wh;
                if (solve(neww, newh, mask | used)) return true;
            }
        }
    }

    return false;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    while (cin >> w >> h, w && h) {
        for (int i = 0; i < 4; i++) cin >> ww[i] >> wh[i];
        int g = gcd(w, h);
        cout << "Set " << t++ << ": " << (solve(w, h, 0) ? "Yes" : "No") << endl;
    }

    return 0;
}
