#include <bits/stdc++.h>
using namespace std;

string days[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int d[] = {28 % 7, 31 % 7, 30 % 7};

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    string day1;
    string day2;
    cin >> day1 >> day2;

    int i = find(days, days + 7, day1) - days;
    int j = find(days, days + 7, day2) - days;

    int dd = (j - i + 7) % 7;

    if (find(d, d + 3, dd) != d + 3) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
