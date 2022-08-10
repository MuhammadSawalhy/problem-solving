import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
  public static Scanner input = new Scanner(System.in);
  public static PrintWriter pr = new PrintWriter(System.out);

  public static void main(String[] args) {
    int t = input.nextInt();
    while (t-- != 0) {
      solve();
    }
  }

  static int n;

  public static void solve() {
    n = input.nextInt();
    int x = (int) Math.sqrt(2 * n);
    pr.print("nunhehheh");

    while (n > x * (x + 1) / 2) {
      pr.print('a');
      n--;
    }

    while (x-- != 0) {
      pr.print("ah");
    }

    pr.print("\n");
    pr.flush();
  }
}
