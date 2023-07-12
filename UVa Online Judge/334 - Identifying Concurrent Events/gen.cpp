#include <iostream>
#include <set>

using namespace std;

int gen(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1]));
  int t = gen(1, 3);
  while (t--) {
    int nc = gen(1, 5);

    cout << nc << endl;

    int cnt = 0;

    while (nc--) {
      int n = gen(1, 5);
      cout << n;
      while (n--)
        cout << " " << cnt++;
      cout << endl;
    }

    int nm = gen(0, min(5, (cnt) * (cnt - 1) / 2));
    cout << nm << endl;
    set<pair<int, int>> s;
    while (nm--) {
      int i = gen(0, cnt - 1);
      int j;
      do {
        j = gen(1, cnt - 1);
      } while (i == j && s.count({i, j}));
      s.insert({i, j});
      cout << i << " " << j << endl;
    }
  }
  cout << 0 << endl;

  return 0;
}
