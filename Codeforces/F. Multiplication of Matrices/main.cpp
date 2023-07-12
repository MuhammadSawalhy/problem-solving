#include <iostream>

using namespace std;

int main() {
  int r1, c1, r2, c2;

  cin >> r1 >> c1;
  int arr1[r1][c1];
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c1; j++) {
      cin >> arr1[i][j];
    }
  }

  cin >> r2 >> c2;
  int arr2[r2][c2];
  for (int i = 0; i < r2; i++) {
    for (int j = 0; j < c2; j++) {
      cin >> arr2[i][j];
    }
  }

  int m[r1][c2];
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      m[i][j] = 0;
      for (int k = 0; k < r2; k++) {
        m[i][j] += arr1[i][k] * arr2[k][j];
      }
    }
  }

  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
}

