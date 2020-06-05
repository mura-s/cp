import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    // static int INF = (1 << 30) - 1;
    // static long L_INF = (1L << 62) - 1;
    // static long MOD = (long) 1e9 + 7;

    // 数列に対し, ある要素に値を加える操作と,
    // 区間和を求める操作をそれぞれ対数時間で行うことが出来るデータ構造。
    // 計算量: O(logN)
    //
    // sum: 区間[1, i]の合計を求める。
    // add: 要素iに値xを加える。
    static class BIT {
        // [1, n]
        int bit[];
        int n;

        BIT(int n) {
            this.bit = new int[n + 1];
            this.n = n;
        }

        int sum(int i) {
            int s = 0;
            while (i > 0) {
                s += bit[i];
                i -= i & -i;
            }
            return s;
        }

        void add(int i, int x) {
            while (i <= n) {
                bit[i] += x;
                i += i & -i;
            }
        }
    }

    static class Solver {
        int n, q;

        // write your code
        // // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp
        void solve(InputReader in, PrintWriter out) {
            n = in.nextInt();
            q = in.nextInt();
            BIT bit = new BIT(n);
            while (q > 0) {
                int com = in.nextInt();
                int x = in.nextInt();
                int y = in.nextInt();
                if (com == 0) {
                    bit.add(x, y);
                } else {
                    out.println(bit.sum(y) - bit.sum(x - 1));
                }
                q--;
            }
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
        BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}
