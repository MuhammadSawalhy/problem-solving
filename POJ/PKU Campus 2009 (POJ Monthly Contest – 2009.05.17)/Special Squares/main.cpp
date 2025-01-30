#include <iostream>
using namespace std;

const int N = 2020;
int p[N][N], yy[N], xx[N], v[N][2];

int count(int x1, int y1, int x2, int y2) {
    return p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1];
};

int main(int argc, char **argv) {
    cin.tie(0)->sync_with_stdio(0);

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    for (int i = 0, y; i < n1; i++) cin >> y, yy[y + 1]++;
    for (int i = 0, x; i < n2; i++) cin >> x, xx[x + 1]++;
    for (int i = 0, x, y; i < n3; i++) cin >> x >> y, p[x + 1][y + 1]++;

    for (int x = 1; x <= 1001; x++) {
        for (int y = 1; y <= 1001; y++) {
            p[x][y] += p[x - 1][y] + p[x][y - 1] - p[x - 1][y - 1];
        }
    }

    int ans = 0;

    for (int diff = -N; diff < N; diff++) {
        int i = 0, sz = 0;
        for (int y = 1; y <= 1001; y++) {
            int x = diff + y;
            if (1 <= x && x <= 1001 && yy[y] != 0 && xx[x] != 0) {
                while (i < sz && count(v[i][0], v[i][1], x, y)) i++;
                ans += i;
                v[sz][0] = x;
                v[sz][1] = y;
                sz++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
