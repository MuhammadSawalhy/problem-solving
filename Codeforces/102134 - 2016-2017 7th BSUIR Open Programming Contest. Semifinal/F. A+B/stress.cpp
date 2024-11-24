#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int N = 412345; typedef int num;
num X[N]; int en = 1, Y[N], sz[N], L[N], R[N];
num T[N];
void calc (int u) { // update node given children info
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
	// code here, no recursion
    T[u] = -1;
    int c;
    if ((c = L[u]) && T[c] != -1) {
        T[u] = T[c];
    } else {
        if (X[u] != 9) T[u] = X[u]; 
        else if ((c = R[u])) {
            T[u] = T[c];
        }
    }
}
void unlaze (int u) {
	if(!u) return;
	// code here, no recursion
}
void split_val(int u, num x, int &l, int &r) { // l gets <= x, r gets > x
	unlaze(u); if(!u) return (void) (l = r = 0);
	if(X[u] <= x) { split_val(R[u], x, l, r); R[u] = l; l = u; }
	else { split_val(L[u], x, l, r); L[u] = r; r = u; }
	calc(u);
}
void split_sz(int u, int s, int &l, int &r) { // l gets first s, r gets remaining
	unlaze(u); if(!u) return (void) (l = r = 0);
	if(sz[L[u]] < s) { split_sz(R[u], s - sz[L[u]] - 1, l, r); R[u] = l; l = u; }
	else { split_sz(L[u], s, l, r); L[u] = r; r = u; }
	calc(u);
}
int merge(int l, int r) { // els on l <= els on r
	unlaze(l); unlaze(r); if(!l || !r) return l + r; int u;
	if(Y[l] > Y[r]) { R[l] = merge(R[l], r); u = l; }
	else { L[r] = merge(l, L[r]); u = r; }
	calc(u); return u;
}
void init(int n=N-1) { // XXX call before using other funcs
	for(int i = en = 1; i <= n; i++) { Y[i] = i; sz[i] = 1; L[i] = R[i] = 0; }
	random_shuffle(Y + 1, Y + n + 1);
}

void print(int u) {
    if (!u) return;
    print(L[u]);
    printf("%d ", X[u]);
    print(R[u]);
}

int rz;

int bb(int k) {
    int l, r;
    split_sz(rz, k-1, l, r);

    int x;
    split_sz(r, 1, x, r);
    if (!x) return -1;

    int ans = X[x];
    int pn9 = T[r];
    if (pn9 >= 10) ans++;

    r = merge(x, r);
    rz = merge(l, r);

    return ans;
}

int main() {
    init(); 

    int n; scanf("%d", &n);
    rz = en++;
    X[rz] = 0;
    T[rz] = 0;
    while (n--) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int k, a, b; scanf("%d%d%d", &k, &a, &b);
            int l, r;
            split_sz(rz, k, l, r);

            int x = en++;
            X[x] = a+b;
            T[x] = X[x] == 9 ? -1 : X[x];

            l = merge(l, x);
            rz = merge(l, r);
        } else if (op == 2) {
            int k; scanf("%d", &k);
            int l, r, ign;
            split_sz(rz, k-1, l, r);
            split_sz(r, 1, ign, r);
            rz = merge(l, r);
        } else {
            int k; scanf("%d", &k);

            int d1 = bb(1);
            int ans = -1;
            if (d1 >= 10) {
                if (k == 1) ans = 1;
                else k--;
            }

            //printf("d1: %d\n", d1);

            if (ans == -1) {
                ans = bb(k);
                //printf("ans: %d\n", ans);
                if (ans != -1) ans %= 10;
            }

            printf("%d\n", ans);
        }

        //print(rz);
        //puts("");
    }

    return 0;
}
