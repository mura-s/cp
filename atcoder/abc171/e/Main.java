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
        int N;
        long[] A;
        StringBuilder[] sb;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            A = new long[N];
            sb = new StringBuilder[N];
            boolean allZero = true;
            for (int i = 0; i < N; i++) {
                A[i] = in.nextLong();
                sb[i] = new StringBuilder();
                if (A[i] != 0) {
                    allZero = false;
                }
            }

            if (allZero) {
                for (int i = 0; i < N; i++) {
                    if (i != 0) {
                        out.print(" ");
                    }
                    out.print(0);
                }
                out.println();
                return;
            }

            while (true) {
                boolean flag = false;
                int cnt = 0;
                for (int i = 0; i < N; i++) {
                    if (A[i] > 0) {
                        flag = true;
                        if (A[i] % 2 != 0) {
                            cnt++;
                        }
                    }
                }
                if (!flag) {
                    break;
                }
                for (int i = 0; i < N; i++) {
                    if (cnt % 2 == 0) {
                        int j = 0;
                        if (A[i] % 2 == 0) {
                            j = 0;
                        } else {
                            j = 1;
                        }
                        sb[i].append(j);
                    } else {
                        int j = 0;
                        if (A[i] % 2 == 0) {
                            j = 1;
                        } else {
                            j = 0;
                        }
                        sb[i].append(j);
                    }
                    A[i] /= 2;
                }
            }
            for (int i = 0; i < N; i++) {
                if (i != 0) {
                    out.print(" ");
                }
                sb[i].reverse();
                out.print(Long.parseLong(sb[i].toString(), 2));
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
