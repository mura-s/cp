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
        int H, W;
        int N;
        int[] A;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            H = in.nextInt();
            W = in.nextInt();
            N = in.nextInt();
            A = new int[N];
            for (int i = 0; i < N; i++) {
                A[i] = in.nextInt();
            }

            int[][] ans = new int[H][W];
            int cur = 0;
            for (int i = 0; i < N; i++) {
                while (A[i] > 0) {
                    int h = cur / W;
                    int w = cur % W;
                    if (h % 2 != 0) {
                        w = W - w - 1;
                    }
                    ans[h][w] = i + 1;
                    A[i]--;
                    cur++;
                }
            }

            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (j != 0) {
                        out.print(" ");
                    }
                    out.print(ans[i][j]);
                }
                out.println();
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
