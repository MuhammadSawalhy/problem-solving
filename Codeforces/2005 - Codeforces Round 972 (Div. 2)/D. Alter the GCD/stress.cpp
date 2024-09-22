#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;
int a[N], b[N];
int pa[N], pb[N], sa[N], sb[N];
int n;

ll dp[N][3];

ll solve_one(ll ga, ll gb)
{
	if (ga <= 0 || gb <= 0) return 0; // invalid fixed gcd(s)
	if (b[1] % gb) return 0; // ivanlid gcd of b

	for (int i = 0; i <= n; i++) for (int j = 0; j < 3; j++) dp[i][j] = 0; // intializing

	dp[1][0] = 1; // base case
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k <= j; k++) {
				bool flag = 1;

				if (j == 1) swap(a[i], b[i]); // if swapping

				if (a[i] % ga) flag = 0; // checking sufficiency
				if (b[i] % gb) flag = 0; // checking sufficiency

				if (j == 1) swap(a[i], b[i]); // if swapping

				if (flag) dp[i][j] += dp[i - 1][k];

				/*
					if j is 0, we can use only k=0 (not started swapping yet)
					if j is 1, we can use both k=0 (starging swapping) and k=1 (currently swapping)
					if j is 2, we can use k=0 (no swaps at all), k=1 (finishing swapping), k=2 (already finished swapping)
				*/
			}
		}
	}

	return dp[n][0] + dp[n][1] + dp[n][2];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t; // test cases

	while (t--) {
		cin >> n;

		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];

		sa[n + 1] = sb[n + 1] = 0; // initializing

		for (int i = 1; i <= n; i++) { // calculating the gcd-s of prefixes and suffixes of a and b
			pa[i] = gcd(pa[i - 1], a[i]);
			pb[i] = gcd(pb[i - 1], b[i]);

			sa[n - i + 1] = gcd(sa[n - i + 2], a[n - i + 1]);
			sb[n - i + 1] = gcd(sb[n - i + 2], b[n - i + 1]);
		}

		if (n <= 300) { // slower solution
			int max_gcd = 0, ways = 0;

			for (int i = 1; i <= n; i++) {
				int ga = 0, gb = 0; // current gcd-s of the range

				for (int j = i; j <= n; j++)
				{
					ga = gcd(ga, a[j]);
					gb = gcd(gb, b[j]);

					int ca = gcd(pa[i - 1], gcd(sa[j + 1], gb)); // gcd of a after the operation
					int cb = gcd(pb[i - 1], gcd(sb[j + 1], ga)); // gcd of b after the operation

					if (ca + cb > max_gcd) {
						max_gcd = ca + cb;
						ways = 1;
					}
					else if (ca + cb == max_gcd) ways++;
				}
			}

			cout << max_gcd << ' ' << ways << "\n";

			continue;
		}

		int max_gcd = pa[n] + pb[n];

		for (int i = 2; i <= n; i++) {
			if (pa[i] == pa[i - 1] && pb[i] == pb[i - 1]) continue; // checking sufficiency of the prefix

			int ga = 0, gb = 0; // current gcd-s of the range

			for (int j = i; j <= n; j++) {
				ga = gcd(ga, a[j]); // updating gcd of the range of a
				gb = gcd(gb, b[j]); // updating gcd of the range of b

				int ca = gcd(pa[i - 1], gcd(sa[j + 1], gb)); // gcd of a after the operation
				int cb = gcd(pb[i - 1], gcd(sb[j + 1], ga)); // gcd of b after the operation

				max_gcd = max(max_gcd, ca + cb); // updating the answer
			}
		}

		ll ans = 0;
		for (int ga = 1; ga * ga <= a[1]; ga++) {
			if (a[1] % ga) continue;

			ans += solve_one(ga, max_gcd - ga); // counting for fixed gcd-s
			if (ga * ga == a[1]) continue;
			ans += solve_one(a[1] / ga, max_gcd - a[1] / ga); // counting for fixed gcd-s
		}

		if (pa[n] + pb[n] == max_gcd) ans -= n; // n-1 times updated with j=2 and k=0 and one time with no swaps at all (dp[n][0])
		for (int i = 1; i <= n; i++) {
			if (gcd(pa[i], sb[i + 1]) + gcd(pb[i], sa[i + 1]) == max_gcd) ans++; // checking prefixes
		}

		cout << max_gcd << ' ' << ans << "\n";
	}

	return 0;
}
