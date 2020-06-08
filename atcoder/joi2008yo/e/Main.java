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
        int R, C;
        boolean[][] a;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            R = in.nextInt();
            C = in.nextInt();
            a = new boolean[R][C];
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    int v = in.nextInt();
                    if (v == 0) {
                        a[i][j] = true;
                    } else {
                        a[i][j] = false;
                    }
                }
            }

            int ans = 0;
            for (int i = 0; i < (1 << R); i++) {
                boolean[] flips = new boolean[R];
                int bit = i;
                int d = 0;
                while (bit > 0) {
                    flips[d] = (bit & 1) == 1;
                    bit /= 2;
                    d++;
                }

                boolean[][] cookies = new boolean[R][C];
                for (int j = 0; j < R; j++) {
                    for (int k = 0; k < C; k++) {
                        cookies[j][k] = flips[j] ? !a[j][k] : a[j][k];
                    }
                }

                int sum = 0;
                for (int k = 0; k < C; k++) {
                    int numZero = 0;
                    int numOne = 0;
                    for (int j = 0; j < R; j++) {
                        if (cookies[j][k]) {
                            numZero++;
                        } else {
                            numOne++;
                        }
                    }
                    sum += Math.max(numZero, numOne);
                }
                ans = Math.max(ans, sum);
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
