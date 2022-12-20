#include <iostream>

using namespace std;

int gen(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1]));
  int t = 1;
  cout << t << endl;
  while (t--) {
    int n = gen(1, 5), p = gen(2, 10);
    cout << n << " " << p << endl;
    while (n--) {
      cout << gen(0, p - 1) << " ";
    }
    cout << endl;
  }

  return 0;
}
