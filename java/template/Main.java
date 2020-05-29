import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
  static class Solver {
    // int INF = (1 << 30) - 1;
    // long L_INF = (1L << 62) - 1;
    // long MOD = (long) 1e9 + 7;

    int N;
    // int[] A;

    // write your code
    public void solve(InputReader in, PrintWriter out) {
      N = in.nextInt();
      //   A = new int[N];
      //   for (int i = 0; i < N; i++) {
      //     A[i] = in.nextInt();
      //   }

      int ans = 0;
      out.println(ans);
    }

    void debug(Object... os) {
      System.err.println(Arrays.deepToString(os));
    }
  }

  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    Solver solver = new Solver();
    solver.solve(in, out);
    out.close();
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }

    public long nextLong() {
      return Long.parseLong(next());
    }
  }
}
