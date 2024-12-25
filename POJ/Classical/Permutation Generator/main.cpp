#include <bits/stdc++.h>
using namespace std;

struct Node {
    int prior, value, toadd, ind;
    Node *l = nullptr, *r = nullptr;

    Node(int val, int i) {
        prior = rand(), value = val, ind = i, toadd = 0;
    }
};

void push(Node *t) {
    if (t && t->toadd) {
        if (t->l) t->l->toadd += t->toadd, t->l->value += t->toadd;
        if (t->r) t->r->toadd += t->toadd, t->r->value += t->toadd;
        t->toadd = 0;
    }
}

void merge(Node *&t, Node *l, Node *r) {
    push(l), push(r);
    if (!l || !r) t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
}

void split(Node *t, Node *&l, Node *&r, int key) {
    if (!t) return void(l = r = nullptr);
    push(t);
    if (key <= t->value)
        split(t->l, l, t->l, key), r = t;
    else
        split(t->r, t->r, r, key), l = t;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Node *t = new Node(a[0], 0);

    for (int i = 1; i < n; i++) {
        Node *l, *r;
        split(t, l, r, a[i]);
        merge(l, l, new Node(a[i], i));
        if (r) r->toadd += 1, r->value += 1;
        merge(t, l, r);
    }

    vector<Node *> nodes{t};
    int ans[n];
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i]) {
            push(nodes[i]);
            ans[nodes[i]->ind] = nodes[i]->value;
            nodes.push_back(nodes[i]->l);
            nodes.push_back(nodes[i]->r);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
