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

    static class Pair {
        long v;
        long num;

        Pair(long v, long num) {
            this.v = v;
            this.num = num;
        }
    }

    static class Solver {
        // 素因数分解
        ArrayList<Pair> primeFactor(long n) {
            ArrayList<Pair> pf = new ArrayList<>();
            for (long p = 2; p * p <= n; ++p) {
                if (n % p != 0) {
                    continue;
                }
                long num = 0;
                while (n % p == 0) {
                    ++num;
                    n /= p;
                }
                pf.add(new Pair(p, num));
            }

            if (n != 1) {
                pf.add(new Pair(n, 1));
            }
            return pf;
        }

        // write your code
        void solve(InputReader in, PrintWriter out) {
            long M = 48;
            ArrayList<Pair> primes = primeFactor(M);
            for (Pair p : primes) {
                out.printf("%d %d\n", p.v, p.num);
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
