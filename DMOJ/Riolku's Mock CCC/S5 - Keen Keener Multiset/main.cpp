#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

const int b = 9, sz = 1 << b, N = (1 << 19) / sz;

const int mask = ((1 << b) - 1);
int n, q;

struct Block {
    int val = 0, lazy = 0, count = 0;
    bitset<sz> a;

    void toggle(int x) {
        assert(0 <= x && x < sz);
        a.flip(x), val ^= x;
        if (a[x]) count++;
        else count--;
    }

    void apply_lazy() {
        if (!lazy) return;
        bitset<sz> newa;
        for (int i = a._Find_first(); i < sz; i = a._Find_next(i)) newa[i ^ lazy].flip();
        if (count & 1) val ^= lazy;
        swap(a, newa), lazy = 0;
    }

    int get_val(int id) {
        if (count & 1) return (id << b) ^ lazy ^ val;
        return val;
    }
};

Block *blks[N], *temp[N];

void toggle(int x) {
    blks[x >> b]->toggle((x & mask) ^ blks[x >> b]->lazy);
}

void merge(Block *&f, Block *&s, int ida) {
    if (f->count < s->count) swap(f, s);
    s->apply_lazy();
    s->val = s->count = 0;
    for (int i = s->a._Find_first(); i < sz; i = s->a._Find_next(i))
        s->a.flip(i), toggle((ida << b) ^ i);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < N; i++) blks[i] = new Block(), temp[i] = new Block();

    cin >> n >> q;
    for (int i = 0, x; i < n; i++) cin >> x, toggle(x);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            toggle(x);
        } else if (type == 2) {
            int l, r, up;
            cin >> l >> r >> up;
            int lblk = l >> b, rblk = r >> b;
            blks[lblk]->apply_lazy();
            blks[rblk]->apply_lazy();
            if (lblk == rblk) {
                auto blk = new Block(*blks[lblk]);
                for (int i = l; i <= r; i++)
                    if (blk->a[i & mask]) toggle(i), toggle(i ^ up);
            } else {
                for (int i = lblk + 1; i < rblk; i++) swap(blks[i], temp[i]);
                auto blk1 = new Block(*blks[lblk]), blk2 = new Block(*blks[rblk]);
                for (int i = l; i < sz * (lblk + 1); i++)
                    if (blk1->a[i & mask]) toggle(i), toggle(i ^ up);
                for (int i = rblk * sz; i <= r; i++)
                    if (blk2->a[i & mask]) toggle(i), toggle(i ^ up);
                for (int blk = lblk + 1; blk < rblk; blk++) {
                    temp[blk]->lazy ^= up & mask;
                    int ida = blk ^ (up >> b);
                    merge(blks[ida], temp[blk], ida);
                }
            }
        } else {
            int l, r;
            cin >> l >> r;
            int lblk = l >> b, rblk = r >> b;
            int ans = 0;
            blks[lblk]->apply_lazy();
            blks[rblk]->apply_lazy();
            if (lblk == rblk) {
                for (int i = l; i <= r; i++)
                    if (blks[lblk]->a[i & mask]) ans ^= i;
            } else {
                for (int i = lblk + 1; i < rblk; i++)
                    ans ^= blks[i]->get_val(i);
                for (int i = l; i < sz * (lblk + 1); i++)
                    if (blks[lblk]->a[i & mask]) ans ^= i;
                for (int i = rblk * sz; i <= r; i++)
                    if (blks[rblk]->a[i & mask]) ans ^= i;
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
