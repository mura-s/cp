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
        int N, K;
        int[] A;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            K = in.nextInt();
            A = new int[N];
            for (int i = 0; i < N; i++) {
                A[i] = in.nextInt();
            }

            for (int i = 0; i < K; i++) {
                int[] imos = new int[N + 2];
                for (int j = 0; j < N; j++) {
                    imos[Math.max(0, j + 1 - A[j])] += 1;
                    imos[Math.min(N + 1, j + 2 + A[j])] -= 1;
                }
                int v = 0;
                for (int j = 0; j < N + 2; j++) {
                    v += imos[j];
                    if (j >= 1 && j <= N) {
                        A[j - 1] = v;
                    }
                }

                boolean flag = true;
                for (int j = 0; j < N; j++) {
                    if (A[j] != N) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }

            for (int i = 0; i < N; i++) {
                if (i != 0) {
                    out.print(" ");
                }
                out.print(A[i]);
            }
            out.println();
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
