#include <bits/stdc++.h>

using namespace std;

int gen(int a = 1, int b = 10) { return a + rand() % (b - a + 1); }

string genstr(int len) {
    string s;
    for (int i = 0; i < len; i++)
        s += 'a' + gen(0, 25);
    return s;
}

vector<int> genperm(int n, int mx = -1) {
    if (mx == -1) mx = n;
    vector<int> v;
    set<int> s;
    while (v.size() < n) {
        int x = gen(1, mx);
        if (!s.count(x)) {
            s.insert(x);
            v.push_back(x);
        }
    }
    return v;
}

int main(int argc, char *argv[]) {
    if (argc > 1) srand(atoi(argv[1]));
    else
        srand(time(NULL));
    int t = 1;
    cout << t << endl;
    while (t--) {
        int n = gen(2, 30), m = 2, d = 1;
        cout << n << " " << m << " " << d << endl;

        auto p = genperm(n);
        for (int i = 0; i < n; i++)
            cout << p[i] << " ";
        cout << endl;
        auto a = genperm(m, n);
        for (int i = 0; i < m; i++)
            cout << a[i] << " ";
        cout << endl;
        
        cout << endl;
    }

    return 0;
}
