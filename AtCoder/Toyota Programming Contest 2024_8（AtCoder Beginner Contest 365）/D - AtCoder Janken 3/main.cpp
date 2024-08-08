#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int moveToIndex(char move) {
    if (move == 'R') return 0;
    if (move == 'P') return 1;
    if (move == 'S') return 2;
    return -1;
}

char indexToMove(int index) {
    if (index == 0) return 'R';
    if (index == 1) return 'P';
    if (index == 2) return 'S';
    return ' ';
}

int state(char x, char y) {
    if (x == 'S' && y == 'P') return true;
    if (x == 'P' && y == 'R') return true;
    if (x == 'R' && y == 'S') return true;
    if (x == y) return 0;
    return -1e9;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    vector<vector<int>> dp(N, vector<int>(3, 0));

    // Initial values for the first game
    for (int j = 0; j < 3; ++j) {
        char move = indexToMove(j);
        dp[0][j] = state(move, S[0]);
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j != k) {
                    char move = indexToMove(k);
                    dp[i][k] = max(dp[i][k], dp[i - 1][j] + state(move, S[i]));
                }
            }
        }
    }

    int result = max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
    cout << result << endl;

    return 0;
}
