#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double u, v, w, l;
        cin >> u >> v >> w >> l;
        double time = l / (u + v);
        cout << fixed << setprecision(3) << time * w << endl;
    }
    return 0;
}
