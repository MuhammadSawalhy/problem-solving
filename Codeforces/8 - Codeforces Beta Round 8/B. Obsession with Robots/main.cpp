#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    cin >> s;

    int n = s.size();
    int x = 111, y = 111;
    bool vis[222][222]{};
    vis[x][y] = true;
    for (int i = 0; i < n; i++) {
        int xx = x, yy = y;
        if (s[i] == 'U') y++;
        if (s[i] == 'D') y--;
        if (s[i] == 'L') x--;
        if (s[i] == 'R') x++;
        if (vis[x][y]) {
            cout << "BUG\n";
            return 0;
        }
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j], ny = y + dy[j];
            if ((nx != xx || ny != yy) && vis[nx][ny]) {
                cout << "BUG\n";
                return 0;
            }
        }
        vis[x][y] = true;
    }

    cout << "OK\n";

    return 0;
}
