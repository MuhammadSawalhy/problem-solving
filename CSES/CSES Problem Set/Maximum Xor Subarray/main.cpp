// ﷽
// https://cses.fi/problemset/task/1655
// CSES -> CSES Problem Set -> Maximum Xor Subarray

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

string s;
auto x = begin(s);

template<int MAX_SIZE = 26>
struct Trie {
    Trie *child[MAX_SIZE];
    int value;
    bool is_leaf = false;
    int count = 0; // how many times the node is inserted

    Trie() {
        for (int i = 0; i < MAX_SIZE; i++)
            child[i] = nullptr;
    }

    ~Trie() {
        for (int i = 0; i < MAX_SIZE; i++) {
            if (child[i] != nullptr)
                delete child[i];
        }
    }

    void insert(const vector<int> &vec, int i = 0) {
        count++;
        if (i == vec.size()) { // nothing to insert
            is_leaf = true;
            return;
        }

        int cur = vec[i];
        if (child[cur] == nullptr) {
            child[cur] = new Trie();
            child[cur]->value = cur;
        }

        child[cur]->insert(vec, i + 1);
    }

    int search(const vector<int> &bits, int i = 0) {
        if (i == bits.size()) return 0;
        if (child[bits[i] ^ 1] != nullptr) {
            return child[bits[i] ^ 1]->search(bits, i + 1) + ((bits[i] ^ 1) << (bits.size() - i - 1));
        }
        assert(child[bits[i]] != nullptr);
        return child[bits[i]]->search(bits, i + 1) + (bits[i] << (bits.size() - i - 1));
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Trie<2> t;
    t.insert(vector<int>(32));

    int px = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        px ^= a[i];
        vector<int> bits;
        for (int i = 31; i >= 0; i--) {
            bits.push_back(px >> i & 1);
        }

        // search using the trie for the best previos px so we can get the max answer
        int previous = t.search(bits);
        ans = max(ans, px ^ previous);
        t.insert(bits);
    }

    cout << ans << endl;

    return 0;
}
