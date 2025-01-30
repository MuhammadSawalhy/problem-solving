#include <bits/stdc++.h>
using namespace std;

struct Segment {
    int x1, y1, x2, y2;
};

bool intersect(Segment a, Segment b) {
    int xl, xr, yl, yr;
    xl = max(min(a.x1, a.x2), min(b.x1, b.x2));
    xr = min(max(a.x1, a.x2), max(b.x1, b.x2));
    yl = max(min(a.y1, a.y2), min(b.y1, b.y2));
    yr = min(max(a.y1, a.y2), max(b.y1, b.y2));
    return xl <= xr && yl <= yr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> d;
        int x = 0, y = 0, dir = 0, step;
        vector<Segment> segs;
        bool inter = false;
        while (cin.peek() != '\n' && cin >> step) d.push_back(step);
        cin.ignore();
        cerr << d.size() << endl;

        for (int dist: d) {
            int nx = x + ((dir == 0) - (dir == 2)) * dist;
            int ny = y + ((dir == 1) - (dir == 3)) * dist;
            Segment s = {x, y, nx, ny};
            for (int i = (int) segs.size() - 2; i >= max(0, (int) segs.size() - 10); i--) {
                if (intersect(s, segs[i])) {
                    inter = true;
                    break;
                }
            }
            if (inter) break;
            segs.push_back(s);
            x = nx, y = ny;
            dir = (dir + 1) % 4;
        }
        cout << (inter ? "Yes" : "No") << endl;
    }
    return 0;
}
