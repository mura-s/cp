import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    static int INF = (1 << 30) - 1;
    // static long L_INF = (1L << 62) - 1;
    // static long MOD = (long) 1e9 + 7;

    static class Point {
        int y;
        int x;
        int dist;

        Point(int y, int x, int dist) {
            this.y = y;
            this.x = x;
            this.dist = dist;
        }
    }

    static class Solver {
        int R, C, sy, sx, gy, gx;
        char[][] c;

        int[] dy = { -1, 0, 1, 0 };
        int[] dx = { 0, -1, 0, 1 };

        // write your code
        void solve(InputReader in, PrintWriter out) {
            R = in.nextInt();
            C = in.nextInt();
            sy = in.nextInt() - 1;
            sx = in.nextInt() - 1;
            gy = in.nextInt() - 1;
            gx = in.nextInt() - 1;
            c = new char[R][C];
            for (int i = 0; i < R; i++) {
                String s = in.next();
                for (int j = 0; j < C; j++) {
                    c[i][j] = s.charAt(j);
                }
            }

            int[][] ans = new int[R][C];
            for (int i = 0; i < R; i++) {
                Arrays.fill(ans[i], INF);
            }
            ArrayDeque<Point> que = new ArrayDeque<>();
            que.add(new Point(sy, sx, 0));
            while (!que.isEmpty()) {
                Point p = que.poll();
                if (ans[p.y][p.x] != INF) {
                    continue;
                }
                ans[p.y][p.x] = p.dist;
                for (int i = 0; i < 4; i++) {
                    int ny = p.y + dy[i];
                    int nx = p.x + dx[i];
                    if (c[ny][nx] == '.') {
                        que.offer(new Point(ny, nx, p.dist + 1));
                    }
                }
            }
            out.println(ans[gy][gx]);
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
