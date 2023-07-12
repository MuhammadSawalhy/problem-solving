#include <iostream>
#include <set>

using namespace std;

int gen(int a = 1, int b = 10) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1]));
  int t = 1;
  cout << t << endl;
  while (t--) {
    int n;
    n = gen();
    cout << n << endl;
    set<int> s;
    while (s.size() < n) {
      s.insert(gen(1, 10 * n));
    }

    for (auto i: s)
      cout << i << " ";
    cout << endl;
  }

  return 0;
}
