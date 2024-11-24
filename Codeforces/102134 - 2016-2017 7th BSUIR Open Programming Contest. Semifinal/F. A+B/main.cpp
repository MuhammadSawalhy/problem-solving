#include <bits/stdc++.h>
using namespace std;

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

long long rand_int(long long x, long long y) {
    return uniform_int_distribution<long long>(x, y)(rng);
}

struct Node {
    long long prior;
    int value, nines, cnt = 1;
    bool carry = false;
    Node *l = nullptr, *r = nullptr;

    Node(int val) {
        prior = rand_int(1, 1e18), carry = val / 10, value = val, nines = val == 9;
    }
};

inline int val(Node *it) { return it ? it->value : 0; }
inline int cnt(Node *it) { return it ? it->cnt : 0; }
inline int nines(Node *it) { return it ? it->nines : 0; }
inline int carry(Node *it) { return it ? it->carry : 0; }

void pull(Node *it) {
    if (it) {
        Node *l = it->l, *r = it->r;

        it->cnt = cnt(l) + cnt(r) + 1;

        it->nines = val(it) == 9 ? nines(l) + 1 : 0;
        if (nines(r) == cnt(r)) it->nines += nines(r);
        else it->nines = nines(r);

        if (nines(l) == cnt(l)) {
            assert(!carry(l));
            it->carry = (val(it) / 10) || (val(it) == 9 && carry(r));
        } else {
            it->carry = carry(l);
        }
    }
}

void push(Node *it) {
}

void merge(Node *&t, Node *l, Node *r) {
    push(l), push(r);
    if (!l || !r) t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    pull(t);
}

void split(Node *t, Node *&l, Node *&r, int key, int add = 0) {
    if (!t) return void(l = r = nullptr);
    push(t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split(t->l, l, t->l, key, add), r = t;
    else
        split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
    pull(t);
}

Node *get_index(Node *t, int i) {
    if (!t) return nullptr;
    push(t);
    if (cnt(t->l) == i) return t;
    if (cnt(t->l) > i) return get_index(t->l, i);
    return get_index(t->r, i - cnt(t->l) - 1);
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    Node *Z = new Node(0);

    vector<int> v{0};

    while (n--) {
        int op, k;
        cin >> op >> k;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            Node *left, *right;
            split(Z, left, right, k);
            merge(Z, left, new Node(a + b));
            merge(Z, Z, right);
        } else if (op == 2) {
            k--;
            Node *left, *mid, *right;
            split(Z, left, right, k);
            split(right, mid, right, 1);
            assert(mid != nullptr);
            merge(Z, left, right);
        } else {
            k--;
            if (k >= cnt(Z) + carry(Z)) {
                cout << "-1\n";
                continue;
            }

            if (carry(Z)) {
                k--;
            }

            if (k == -1) {
                cout << carry(Z) << endl;
            } else {
                Node *left, *digit, *right;
                split(Z, left, right, k);
                split(right, digit, right, 1);
                cout << (get_index(digit, 0)->value + carry(right)) % 10 << endl;
                merge(Z, left, digit);
                merge(Z, Z, right);
            }
        }
    }

    return 0;
}
