import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;
import java.awt.Point;

public class Main {
    // static int INF = (1 << 30) - 1;
    // static long L_INF = (1L << 62) - 1;
    // static long MOD = (long) 1e9 + 7;

    static class Solver {
        int N, M;
        long[] P;

        boolean checkUpper(long[] arr, int idx, long v) {
            // implement check if needed
            return arr[idx] > v;
        }

        long upperBound(long[] arr, long v) {
            long left = 0;
            long right = arr.length; // always satisfied with the check.
            while (left < right) {
                long mid = (left + right) / 2;
                if (checkUpper(arr, (int) mid, v)) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        }

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            M = in.nextInt();
            P = new long[N + 1];
            P[0] = 0;
            for (int i = 1; i <= N; i++) {
                P[i] = in.nextLong();
            }

            int size = (N + 1) * (N + 1);
            long[] comb = new long[size];
            for (int i = 0; i < N + 1; i++) {
                for (int j = 0; j < N + 1; j++) {
                    comb[i * (N + 1) + j] = P[i] + P[j];
                }
            }
            Arrays.sort(comb);

            long ans = 0;
            for (int i = 0; i < size; i++) {
                long p = M - comb[i];
                if (p == 0) {
                    ans = M;
                    break;
                } else if (p < 0) {
                    continue;
                } else {
                    int idx = (int) upperBound(comb, p);
                    ans = Math.max(ans, comb[i] + comb[idx - 1]);
                }
            }
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
