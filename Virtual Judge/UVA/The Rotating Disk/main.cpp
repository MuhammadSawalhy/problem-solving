#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

void change(vector<int> &v, int i) {
    int n = v.size();
    int a = i;
    int b = i + 1;
    int c = i + 2;
    int d = i + 3;
    if (b >= n) b = n;
    if (c >= n) c = n;
    if (d >= n) d = n;
    swap(v[a], v[d]);
    swap(v[b], v[c]);
}

vector<int> shiftleft(vector<int> &v, int x) {
    vector<int> ret;
    for (int i = 0, j = x; i < v.size(); i++, j++) {
        if (j == v.size()) j = 0;
        ret.push_back(v[j]);
    }
    return ret;
}

bool isok(vector<int> &v) {
    vector<int> a = shiftleft(v, find(v.begin(), v.end(), 1) - v.begin());
    return is_sorted(a.begin(), a.end());
}

void output(vector<int> &v, int l) {
    int r = l + 3;
    if (r >= v.size()) r -= v.size();
    for (int i = 0; i < v.size(); i++) {
        if (i == l) putchar('*');
        printf("%d", v[i]);
        if (i == r) putchar('*');
        putchar(" \n"[i + 1 == v.size()]);
    }
}

bool check(vector<int> &v) {
    int rev = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] > v[j])
                rev++;
        }
    }
    if (rev & 1) {
        if (v.size() & 1) return false;
        v.push_back(v[0]);
        v.erase(v.begin());
    }
    return true;
}

void refrain(vector<int> &v) {
    int n = v.size();
    for (int o = n; o > 6; o--) {
        int k = o - 1;
        while (v[k] != o) {
            int pos = find(v.begin(), v.end(), o) - v.begin();
            if ((k - pos) % 3 == 0 || pos == 0 || pos == 1) {
                change(v, pos);
                output(v, pos);
            } else {
                change(v, pos - 2);
                output(v, pos - 2);
            }
        }
    }
}

void solveSmall(vector<int> &v0) {
    v0 = shiftleft(v0, find(v0.begin(), v0.end(), 1) - v0.begin());
    int n = v0.size();
    map<vector<int>, int> mc;
    vector<int> key = v0;
    sort(key.begin(), key.end());
    queue<vector<int>> q;
    q.push(key);
    mc[key] = -2;
    while (!q.empty()) {
        if (mc.count(v0)) break;
        auto v = q.front();
        q.pop();
        for (int i = 0; i < v.size(); i++) {
            change(v, i);
            int pos = find(v.begin(), v.end(), 1) - v.begin();
            vector<int> t = shiftleft(v, pos);
            if (!mc.count(t)) {
                q.push(t);
                mc[t] = (i - pos + n) % n;
            }
            change(v, i);
        }
    }
    if (!mc.count(v0)) {
        puts("It is not possible to rearrange these disks in natural order.");
        return;
    }
    while (mc[v0] != -2) {
        int pos = mc[v0];
        v0 = shiftleft(v0, pos);
        pos = 0;
        change(v0, pos);
        output(v0, pos);
        int ox = find(v0.begin(), v0.end(), 1) - v0.begin();
        v0 = shiftleft(v0, ox);
    }
}

void solveBig(vector<int> &v0) {
    refrain(v0);
    int n = v0.size();
    map<vector<int>, int> mc;
    vector<int> key = v0;
    sort(key.begin(), key.end());
    queue<vector<int>> q;
    q.push(key);
    mc[key] = -2;
    while (!q.empty()) {
        if (mc.count(v0)) break;
        auto v = q.front();
        q.pop();
        for (int i = 0; i <= 2; i++) {
            change(v, i);
            if (!mc.count(v)) {
                q.push(v);
                mc[v] = i;
            }
            change(v, i);
        }
    }
    while (mc[v0] != -2) {
        int pos = mc[v0];
        change(v0, pos);
        output(v0, pos);
    }
}

int main() {
    string str;
    int ks = 0;
    while (getline(cin, str)) {
        if (ks++) puts("");
        stringstream sin(str);
        vector<int> v0;
        int x;
        while (sin >> x) {
            v0.push_back(x);
        }
        output(v0, -INF);
        if (!check(v0)) {
            puts("It is not possible to rearrange these disks in natural order.");
        } else if (v0.size() < 6) {
            solveSmall(v0);
        } else {
            solveBig(v0);
        }
    }
    return 0;
}
