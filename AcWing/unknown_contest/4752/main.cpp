#include <bits/stdc++.h>
using namespace std;

int N, M, P;
string alpha, words[10];

struct Aho {
    vector<unordered_map<char, int>> child;
    vector<bool> isend;
    vector<int> fail;

    Aho() { add_node(); }

    int add_node() {
        isend.push_back({}), fail.push_back({}), child.push_back({});
        return child.size() - 1;
    }

    int insert(const string &s) {
        int cur = 0;
        for (char c: s) {
            if (child[cur][c] == 0)
                child[cur][c] = add_node();
            cur = child[cur][c];
        }
        isend[cur] = true;
        return cur;
    }

    int go(int cur, char nxt) {
        while (cur && !child[cur][nxt]) cur = fail[cur];
        return child[cur][nxt];
    }

    // calculate fail links
    void build() {
        queue<int> q;
        for (char i: alpha)
            if (child[0][i]) q.push(child[0][i]);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (char nxt: alpha) {
                if (!child[cur][nxt]) continue;
                fail[child[cur][nxt]] = go(fail[cur], nxt);
                q.push(child[cur][nxt]);
            }
        }
    }
};

int brute(string s) {
    for (int i = 0; i < P; ++i) {
        if (s.find(words[i]) != string::npos) {
            return 0;
        }
    }
    if (s.size() == M) {
        return 1;
    }

    int ans = 0;

    for (auto c : alpha) {
        ans += brute(s + c);
    }

    return ans;
}

int main() {
    cin >> N >> M >> P;
    cin >> alpha;
    for (int i = 0; i < P; ++i) cin >> words[i];

    Aho ac;
    for (int i = 0; i < P; ++i)
        ac.insert(words[i]);
    ac.build();

    vector<vector<long long>> dp(M + 1, vector<long long>(ac.child.size(), 0));
    dp[0][0] = 1;

    cerr << ac.child.size() << endl;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < ac.child.size(); ++j) {
            if (dp[i][j] == 0) continue;
            for (char c: alpha) {
                int next = ac.child[j][c];
                if (!ac.isend[next]) {
                    dp[i + 1][next] += dp[i][j];
                }
            }
        }
    }

    long long result = 0;
    for (int j = 0; j < ac.child.size(); ++j)
        result += dp[M][j];

    int res = brute("");
    cout << res << endl;
    return 0;
}
