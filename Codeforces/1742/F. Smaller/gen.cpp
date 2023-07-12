#include <iostream>

using namespace std;

int gen(int a = 1, int b = 10) { return a + rand() % (b - a + 1); }

string genx() {
  int l = 1;
  string r;

  while (l--) {
    r += 'a';
    // r += 'a' + gen(0, 1);
  }

  return r;
}

int main(int argc, char *argv[]) {
  srand(atoi(argv[1]));
  int t = 1;
  cout << t << endl;
  while (t--) {
    int q = 1e5;
    cout << q << endl;
    while (q--) {
      cout << 1 << " " << (int)1e5 << " " << genx() << endl;
    }
  }

  return 0;
}
