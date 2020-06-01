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
    static long MOD = (long) 1e9 + 7;

    static class Solver {
        // 拡張 Euclid の互除法を用いて、mod MOD での a の逆元 a^{-1} を計算する
        // 計算量: O(logMOD)
        //
        // ref.
        // https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#3-%E5%89%B2%E3%82%8A%E7%AE%97-a--b
        long modinv(long a) {
            long b = MOD, u = 1, v = 0;
            while (b > 0) {
                long t = a / b;
                a -= t * b;

                // swap
                long tmp1 = a;
                a = b;
                b = tmp1;

                u -= t * v;

                // swap
                long tmp2 = u;
                u = v;
                v = tmp2;
            }
            u %= MOD;
            if (u < 0) {
                u += MOD;
            }
            return u;
        }

        // write your code
        void solve(InputReader in, PrintWriter out) {
            long x = 678813585;
            long y = 100000;
            out.println(x * modinv(y) % MOD);
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
