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
        int H, W, N;
        char[][] area;
        Point start;

        int[] dy = { -1, 0, 1, 0 };
        int[] dx = { 0, -1, 0, 1 };

        // write your code
        void solve(InputReader in, PrintWriter out) {
            H = in.nextInt();
            W = in.nextInt();
            N = in.nextInt();
            area = new char[H][W];
            for (int i = 0; i < H; i++) {
                String s = in.next();
                for (int j = 0; j < W; j++) {
                    area[i][j] = s.charAt(j);
                    if (area[i][j] == 'S') {
                        start = new Point(i, j, 0);
                    }
                }
            }

            int ans = 0;
            for (int i = 1; i <= N; i++) {
                ArrayDeque<Point> que = new ArrayDeque<>();
                boolean[][] visited = new boolean[H][W];
                que.offer(start);
                while (!que.isEmpty()) {
                    Point p = que.poll();
                    if (area[p.y][p.x] - '0' == i) {
                        ans += p.dist;
                        start = new Point(p.y, p.x, 0);
                        break;
                    }
                    if (visited[p.y][p.x]) {
                        continue;
                    }
                    visited[p.y][p.x] = true;
                    for (int j = 0; j < 4; j++) {
                        int newY = p.y + dy[j];
                        int newX = p.x + dx[j];
                        if (newY >= 0 && newY < H && newX >= 0 && newX < W && area[newY][newX] != 'X') {
                            que.offer(new Point(newY, newX, p.dist + 1));
                        }
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
