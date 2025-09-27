#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> &a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd &x: a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const &a, vector<int> const &b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    const int sh = 5e4;
    vector<int> fr(1e5 + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fr[a[i] + sh]++;
    }

    auto fr2 = fr;
    auto res = multiply(fr2, fr2);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += res[a[i] + sh + sh];
    }

    cerr << ans << endl;
    // a[i] = a[j]
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i]) {
            int x = fr[a[i] / 2 + sh];
            ans -= x;
        }
    }
    cerr << ans << endl;

    int zeros = fr[sh];

    // i = k, or j = k
    // only when either a[i] = 0 or a[j] = 0, but not both
    ans -= (n - zeros) * zeros * 2;
    cerr << ans << endl;

    // i = j != k, a[i] = a[j] = a[k] = 0
    ans -= zeros * (zeros - 1);
    cerr << ans << endl;

    // i != j = k, a[i] = a[j] = a[k] = 0
    ans -= zeros * (zeros - 1);
    cerr << ans << endl;

    // j != i = k, a[i] = a[j] = a[k] = 0
    ans -= zeros * (zeros - 1);
    cerr << ans << endl;

    // i = j = k, a[i] = a[j] = a[k]
    ans -= zeros;

    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
