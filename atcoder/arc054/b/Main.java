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
        double P;

        boolean delta(double v1, double v2) {
            return Math.abs(v1 - v2) < 0.0000000001;
        }

        double deriv(double t) {
            return 1.0 + P * Math.pow(Math.pow(2.0, -1.0 / 1.5), t) * Math.log(Math.pow(2.0, -1.0 / 1.5));
        }

        double binarySearch() {
            double left = 0.0;
            double right = P;
            while (!delta(left, right)) {
                double mid = (left + right) / 2.0;
                if (deriv(mid) < 0.0) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            return left;
        }

        // write your code
        void solve(InputReader in, PrintWriter out) {
            P = in.nextDouble();
            double t = binarySearch();
            double ans = t + P / Math.pow(2.0, t / 1.5);
            out.printf("%.10f\n", ans);
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

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}
