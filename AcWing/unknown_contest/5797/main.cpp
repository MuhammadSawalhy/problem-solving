#include <bits/stdc++.h>
using namespace std;

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
int r, c, pr, pc, kr, kc;

bool valid(int x, int y) {
    return x >= 1 && x <= r && y >= 1 && y <= c;
}

string solve() {
    set<pair<int, int>> kpos{{kr, kc}};

    int stalemate = 1e9;

    for (int step = 1; step <= r - pr - 1; step++) {
        set<pair<int, int>> kpos2;

        for (auto [x, y]: kpos) {
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (valid(nx, ny)) kpos2.insert({nx, ny});
            }
        }

        if (kpos2.count({pr + step + 1, pc})) {
            stalemate = min(step, stalemate);
            kpos2.erase({pr + step + 1, pc});
        }

        if (kpos2.count({pr + step, pc})) return "Win in " + to_string(step) + " knight move(s).";
        kpos = kpos2;
    }

    if (stalemate < 1e9) return "Stalemate in " + to_string(stalemate) + " knight move(s).";

    return "Loss in " + to_string(r - pr - 1) + " knight move(s).";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> r >> c >> pr >> pc >> kr >> kc;
        cout << solve() << "\n";
    }

    return 0;
}
