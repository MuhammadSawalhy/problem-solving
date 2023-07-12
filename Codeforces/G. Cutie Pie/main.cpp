#include <bits/stdc++.h>
#include <iostream>
using namespace std;

char word[20][20];
int num, row, col;

char w (int i, int j) {
  if (i < 0 || i >= row || j < 0 || j >= col)
    return ' ';
  return (char)word[i][j];
}

int main() {
  bool flag = 0;
  cin >> num;

  while (num--) {
    flag = 0;
    cin >> row >> col;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cin >> word[i][j];
      }
    }

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (w(i, j) == 'p' && w(i, j + 1) == 'i' && w(i, j + 2) == 'e') flag = 1;
        if (w(i, j) == 'p' && w(i, j - 1) == 'i' && w(i, j - 2) == 'e') flag = 1;
        if (w(i, j) == 'p' && w(i + 1, j) == 'i' && w(i + 2, j) == 'e') flag = 1;
        if (w(i, j) == 'p' && w(i - 1, j) == 'i' && w(i - 2, j) == 'e') flag = 1;
        if (w(i, j) == 'p' && w(i + 1, j + 1) == 'i' && w(i + 2, j + 2) == 'e') flag = 1;
        if (w(i, j) == 'p' && w(i - 1, j - 1) == 'i' && w(i - 2, j - 2) == 'e') flag = 1;
        if (w(i, j) == 'p' && w(i + 1, j - 1) == 'i' && w(i + 2, j - 2) == 'e') flag = 1;
        if (w(i, j) == 'p' && w(i - 1, j + 1) == 'i' && w(i - 2, j + 2) == 'e') flag = 1;
        if (flag) break;
      }

      if (flag) break;
    }

    if (flag)
      cout << "Cutie Pie!" << endl;
    else
      cout << "Sorry Man" << endl;
  }
}
