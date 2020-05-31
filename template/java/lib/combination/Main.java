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

    static class Solver {
        // ref. https://www.kaoken.cg0.xyz/math_combination/

        // 組み合わせ (combination) を求める
        long nCr(long n, long r) {
            if (r > n) {
                return 0;
            }
            if (r == 0 || n == r) {
                return 1;
            }
            if (r * 2 > n) {
                r = n - r;
            }

            long result = n;
            for (long i = 2; i <= r; i++) {
                result *= (n - i + 1);
                result /= i;
            }
            return result;
        }

        // 重複組み合わせを求める
        // r個のものをn種類にわける
        //
        // ref. https://mathtrain.jp/tyohukuc
        long nHr(long n, long r) {
            return nCr(n + r - 1, r);
        }

        int N;
        // int[] A;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            out.println(nCr(10, 0));
            out.println(nCr(10, 1));
            out.println(nCr(10, 3));
            out.println(nCr(10, 9));
            out.println(nCr(10, 10));
            out.println(nHr(7, 3));
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
