import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
  public static Scanner input = new Scanner(System.in);

  public static void main(String[] args) {
    int t = input.nextInt();
    int t_ = t;
    while (t-- != 0) {
      solve(t_ - t);
    }
  }

  static boolean[][] v;
  static String[] m;
  static int n;

  public static void solve(int t) {
    ans = 0;
    n = input.nextInt();
    v = new boolean[n][n];
    m = new String[n];
    input.nextLine();
    input.next();
    for (int i = 0; i < n; i++) {
      m[i] = input.nextLine();
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; ++j) {
        if (v[i][j])
          continue;
        if (m[i].charAt(j) == '.')
          continue;
        if (doit(i, j))
          ans++;
      }
    }

    System.out.println(String.format("Case %d: %d", t, ans));
  }

  static int ans;

  static boolean doit(int i, int j) {
    if (i >= 0 && j >= 0 && i < n && j < n && m[i].charAt(j) != '.') {
      if (v[i][j])
        return false;
      v[i][j] = true;
      char c = m[i].charAt(j);
      if (c == '@') {
        boolean ret = false;
        if (doit(i + 1, j))
          ret = true;
        if (doit(i - 1, j))
          ret = true;
        if (doit(i, j + 1))
          ret = true;
        if (doit(i, j - 1))
          ret = true;
        return ret;
      } else {
        doit(i + 1, j);
        doit(i - 1, j);
        doit(i, j + 1);
        doit(i, j - 1);
        return true;
      }
    }

    return false;
  }
}
