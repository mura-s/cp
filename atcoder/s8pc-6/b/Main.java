import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    // static int INF = (1 << 30) - 1;
    static long L_INF = (1L << 62) - 1;
    // static long MOD = (long) 1e9 + 7;

    static class Solver {
        int N;
        long[] A, B;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            A = new long[N];
            B = new long[N];
            for (int i = 0; i < N; i++) {
                A[i] = in.nextLong();
                B[i] = in.nextLong();
            }

            long ans = L_INF;
            for (int a = 0; a < N; a++) {
                for (int b = 0; b < N; b++) {
                    long sum = 0;
                    for (int i = 0; i < N; i++) {
                        sum += Math.abs(A[a] - A[i]) + Math.abs(B[i] - A[i]) + Math.abs(B[b] - B[i]);
                    }
                    ans = Math.min(ans, sum);
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
