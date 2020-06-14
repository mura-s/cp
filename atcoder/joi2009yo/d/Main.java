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
        int m, n;
        int[][] space;
        int ans;

        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };

        void rec(boolean[][] visited, int depth, int i, int j) {
            if (visited[i][j] || space[i][j] == 0) {
                ans = Math.max(ans, depth);
                return;
            }
            visited[i][j] = true;
            for (int k = 0; k < 4; k++) {
                if (i + dy[k] >= 0 && i + dy[k] < n && j + dx[k] >= 0 && j + dx[k] < m) {
                    rec(visited, depth + 1, i + dy[k], j + dx[k]);
                } else {
                    ans = Math.max(ans, depth + 1);
                }
            }
            visited[i][j] = false;
        }

        // write your code
        void solve(InputReader in, PrintWriter out) {
            m = in.nextInt();
            n = in.nextInt();
            space = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    space[i][j] = in.nextInt();
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (space[i][j] == 1) {
                        rec(new boolean[n][m], 0, i, j);
                    }
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
