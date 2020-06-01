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
        int N;
        int[] A, B;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            A = new int[N + 1];
            B = new int[N + 1];
            for (int i = 1; i < N + 1; i++) {
                A[i] = in.nextInt();
                B[i] = in.nextInt();
            }
            Arrays.sort(A);
            Arrays.sort(B);

            if (N % 2 != 0) {
                int midA = A[(N + 1) / 2];
                int midB = B[(N + 1) / 2];
                out.println(midB - midA + 1);
            } else {
                int midA = (A[N / 2] + A[N / 2 + 1]);
                int midB = (B[N / 2] + B[N / 2 + 1]);
                out.println(midB - midA + 1);
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
