#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 4) {
            cout << "2 1 3 4" << endl;
            continue;
        }

        for (int i = 0; i < n - 5; i++)
            cout << i + 4 << " ";

        cout << "2 3 1 " << n - 1 << " " << n << endl;
    }

    return 0;
}