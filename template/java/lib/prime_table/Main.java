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
        int MAX_N = 10000;

        int[] prime = new int[MAX_N];
        boolean[] isPrime = new boolean[MAX_N + 1];

        // prime table
        int eratosthenes(int n) {
            int p = 0;
            for (int i = 0; i <= n; i++) {
                isPrime[i] = true;
            }
            isPrime[0] = false;
            isPrime[1] = false;

            for (int i = 2; i <= n; i++) {
                if (!isPrime[i]) {
                    continue;
                }
                prime[p] = i;
                p++;
                for (int j = 2 * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
            return p;
        }

        // write your code
        void solve(InputReader in, PrintWriter out) {
            int N = 100;
            int p = eratosthenes(N);
            for (int i = 0; i < p; i++) {
                out.println(prime[i]);
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
