#include <iostream>

using namespace std;

int gen(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1]));
  int t = 1;
  cout << t << endl;
  while (t--) {
    int n, m;;
    n = gen(2, 10);
    m = gen(1, 20);
    cout << n << " " << m << endl;

    cout << gen(1, 20) << " ";
    n--;
    while (n--) {
        cout << 1 << " ";
    }
    cout << endl;
  }

  return 0;
}
