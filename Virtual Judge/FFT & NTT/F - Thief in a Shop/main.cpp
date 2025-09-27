#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

using cd = complex<double>;
const double PI = acos(-1);
const int MAX_SIZE = 1 << 21; // Enough for 1e6 elements with some padding

cd fa[MAX_SIZE], fb[MAX_SIZE];
int result[MAX_SIZE];

void fft(cd a[], int n, bool invert) {
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
        for (int i = 0; i < n; i++)
            a[i] /= n;
    }
}

void multiply(int a[], int a_size, int b[], int b_size, int res[], int &res_size) {
    int n = 1;
    while (n < a_size + b_size) 
        n <<= 1;

    // Initialize complex arrays
    for (int i = 0; i < n; i++) {
        fa[i] = (i < a_size) ? cd(a[i]) : cd(0);
        fb[i] = (i < b_size) ? cd(b[i]) : cd(0);
    }

    fft(fa, n, false);
    fft(fb, n, false);
    
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    
    fft(fa, n, true);

    res_size = n;
    for (int i = 0; i < n; i++)
        res[i] = round(fa[i].real());
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    static int a[MAX_SIZE] = {0};
    static int temp[MAX_SIZE] = {0};
    static int res[MAX_SIZE] = {0};

    int a_size = 1e3 + 1;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a[x] = 1;
    }

    int res_size = 1;
    res[0] = 1;

    for (int b = k; b; b >>= 1) {
        if (b & 1) {
            multiply(res, res_size, a, a_size, temp, res_size);
            for (int i = 0; i < res_size; i++) {
                res[i] = !!temp[i];
                if (i >= 1e6 + 1) res[i] = 0; // Truncate to 1e6 elements
            }
            if (res_size > 1e6 + 1) res_size = 1e6 + 1;
        }

        multiply(a, a_size, a, a_size, temp, a_size);
        for (int i = 0; i < a_size; i++) {
            a[i] = !!temp[i];
            if (i >= 1e6 + 1) a[i] = 0; // Truncate to 1e6 elements
        }
        if (a_size > 1e6 + 1) a_size = 1e6 + 1;
    }

    for (int i = 0; i < res_size; i++) {
        if (res[i]) cout << i << ' ';
    }

    return 0;
}
