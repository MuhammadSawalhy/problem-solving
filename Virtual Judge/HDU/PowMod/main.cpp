#include <algorithm>
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e7 + 5;
int phi[MAX];
void precompute_phi() {
    for (int i = 0; i < MAX; ++i) phi[i] = i;
    for (int i = 2; i < MAX; ++i) {
        if (phi[i] == i) {
            for (int j = i; j < MAX; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int gcd(int a, int b) {
    while (b) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int compute_k(int n, int m) {
    int total = 0;
    int phi_n = phi[n];
    for (int i = 1; i <= m; ++i) {
        int d = gcd(i, n);
        int term = (1LL * phi[i] * phi_n % MOD) * d / phi[d] % MOD;
        total = (total + term) % MOD;
    }
    return total;
}

int pow_mod(int a, int b, int mod) {
    int res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

int tower(int k, int p) {
    if (p == 1) return 0;
    int phi_p = phi[p];
    int exponent = tower(k, phi_p) + phi_p;
    return pow_mod(k, exponent, p);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute_phi();
    int n, m, p;
    while (cin >> n >> m >> p) {
        int k = compute_k(n, m);
        if (p == 1) {
            cout << "0\n";
        } else {
            cout << tower(k, p) << '\n';
        }
    }
    return 0;
}
