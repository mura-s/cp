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
        long d;
        int n, m;
        long[] ds;

        boolean checkLower(long[] arr, int idx, long v) {
            // implement check if needed
            return arr[idx] >= v;
        }

        long lowerBound(long[] arr, long v) {
            long left = 0;
            long right = arr.length; // always satisfied with the check.
            while (left < right) {
                long mid = (left + right) / 2;
                if (checkLower(arr, (int) mid, v)) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        }

        // write your code
        void solve(InputReader in, PrintWriter out) {
            d = in.nextLong();
            n = in.nextInt();
            m = in.nextInt();
            ds = new long[n + 1];
            ds[0] = 0;
            for (int i = 1; i < n; i++) {
                ds[i] = in.nextLong();
            }
            ds[n] = d;
            Arrays.sort(ds);

            long ans = 0;
            for (int i = 0; i < m; i++) {
                long m = in.nextLong();
                int idx = (int) lowerBound(ds, m);
                if (idx != 0) {
                    ans += Math.min(Math.abs(m - ds[idx]), Math.abs(m - ds[idx - 1]));
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
