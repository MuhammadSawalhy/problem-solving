#include <bits/stdc++.h>
using namespace std;

void NO() {
    puts("0");
    exit(0);
}

int main() {
    long long N, M;
    cin >> N >> M;
    vector<long long> A(N);
    for (auto &a: A)
        cin >> a, a /= 2;
    long long lcm = 1;
    for (auto a: A) {
        lcm = lcm * a / __gcd(lcm, a);
        if (lcm > M) {
            NO();
        }
    }
    for (auto a: A) {
        if (lcm / a % 2 == 0) {
            NO();
        }
    }
    cout << 1 + (M - lcm) / (lcm * 2) << endl;
}
