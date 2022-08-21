#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>

int n, k;
int nums[10001];
int memo[10001][100];

bool is(int i, int sum) {
    sum = (sum % k + k) % k;
    if (i == n)
        return sum % k == 0;
    int &s = memo[i][sum];
    s--;
    if (s != -1) return s;
    s = is(i + 1, sum + nums[i]) || is(i + 1, sum - nums[i]);
    s++;
    return s - 1;
}

void solve() {
    cin >> n >> k;
    memset(memo, 0, sizeof(memo));
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    if (is(0, 0))
        cout << "Divisible" << endl;
    else
        cout << "Not divisible" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("/home/ms/myp/problem-solving/input", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
