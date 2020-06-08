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
    static long L_INF = (1L << 62) - 1;
    // static long MOD = (long) 1e9 + 7;

    static class Solver {
        int N, K;
        long[] A;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            K = in.nextInt();
            A = new long[N];
            for (int i = 0; i < N; i++) {
                A[i] = in.nextLong();
            }

            long[] maxes = new long[N + 1];
            for (int i = 0; i < N; i++) {
                maxes[i + 1] = Math.max(maxes[i], A[i]);
            }

            long ans = L_INF;
            for (int i = 0; i < (1 << N); i++) {
                if (Integer.bitCount(i) != K) {
                    continue;
                }
                ArrayList<Integer> al = new ArrayList<>();
                int bit = i;
                int d = 0;
                while (bit > 0) {
                    if ((bit & 1) == 1) {
                        al.add(d);
                    }
                    bit /= 2;
                    d++;
                }
                long cost = 0;
                long before = 0;
                for (int j = 0; j < al.size(); j++) {
                    int idx = al.get(j);
                    long v = A[idx];
                    if (v <= Math.max(before, maxes[idx])) {
                        cost += Math.max(before, maxes[idx]) - v + 1;
                        before = Math.max(before, maxes[idx]) + 1;
                    }
                }
                ans = Math.min(ans, cost);
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
