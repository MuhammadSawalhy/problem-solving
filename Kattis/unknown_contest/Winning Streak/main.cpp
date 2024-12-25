#include <iomanip>
#include <iostream>

using namespace std;

int n;
const int N = 3003;
double p, dp[N][N], pow[N];

int main() {

    while (cin >> n >> p) {
        double ans = 0;
        pow[0] = 1;

        for (int i = 1; i <= n; i++) pow[i] = pow[i - 1] * p;
        for (int i = 0; i <= n; i++) dp[0][i] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j + 1 == i) dp[i][j] -= pow[j + 1];
                if (j + 1 < i) dp[i][j] -= dp[i - j - 2][j] * (1 - p) * pow[j + 1];
            }
        }

        for (int j = 1; j <= n; j++)
            ans += j * (dp[n][j] - dp[n][j - 1]);
        cout << fixed << setprecision(6) << ans << endl;
    }

    return 0;
}
