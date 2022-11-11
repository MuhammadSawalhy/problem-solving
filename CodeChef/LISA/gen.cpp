#include <iostream>

using namespace std;

int gen(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1]));
  int t = 1;
  cout << t << endl;
  while (t--) {
    int n;
    n = gen(1, 10);
    cout << n << endl;

    while (n--) {
      cout << gen(1, 10) << " ";
    }
    cout << endl;
  }

  return 0;
}
