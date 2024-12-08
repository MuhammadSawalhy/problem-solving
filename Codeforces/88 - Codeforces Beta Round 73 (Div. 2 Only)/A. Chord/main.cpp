#include <bits/stdc++.h>
using namespace std;

const string notes[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    string cur[3];
    cin >> cur[0] >> cur[1] >> cur[2];

    sort(cur, cur + 3);

    do {
        int i = find(notes, notes + 12, cur[0]) - notes;
        int j = find(notes, notes + 12, cur[1]) - notes;
        int k = find(notes, notes + 12, cur[2]) - notes;
        int d1 = (j - i + 12) % 12;
        int d2 = (k - j + 12) % 12;
        if (d1 == 4 && d2 == 3)
            return cout << "major" << endl, 0;
        else if (d1 == 3 && d2 == 4)
            return cout << "minor" << endl, 0;
    } while (next_permutation(cur, cur + 3));

    cout << "strange" << endl;

    return 0;
}
