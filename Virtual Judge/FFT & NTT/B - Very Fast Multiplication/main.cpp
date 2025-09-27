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
    string a, b;
    cin >> a >> b;
    vector<int> A(a.size()), B(b.size());
    for (int i = 0; i < a.size(); i++) A[a.size() - 1 - i] = a[i] - '0';
    for (int i = 0; i < b.size(); i++) B[b.size() - 1 - i] = b[i] - '0';
    vector<int> C = multiply(A, B);
    for (int i = 0; i < C.size() - 1; i++) {
        if (C[i] >= 10) C[i + 1] += C[i] / 10, C[i] %= 10;
    }
    while (C.back() >= 10) {
        C.push_back(C.back() / 10);
        C.end()[-2] %= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl;
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
