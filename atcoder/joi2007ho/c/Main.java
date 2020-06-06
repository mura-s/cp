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
        HashSet<Point> hs;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            hs = new HashSet<>();
            for (int i = 0; i < N; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                hs.add(new Point(x, y));
            }

            int ans = 0;
            Point p1 = new Point(0, 0);
            Point p2 = new Point(0, 0);
            for (Point p : hs) {
                for (Point q : hs) {
                    if (p.equals(q)) {
                        continue;
                    }
                    int dx = p.x - q.x;
                    int dy = p.y - q.y;
                    p1.x = p.x - dy;
                    p1.y = p.y + dx;
                    p2.x = q.x - dy;
                    p2.y = q.y + dx;
                    if (hs.contains(p1) && hs.contains(p2)) {
                        ans = Math.max(ans, Math.abs(dx) * Math.abs(dx) + Math.abs(dy) * Math.abs(dy));
                    }

                    p1.x = p.x + dy;
                    p1.y = p.y - dx;
                    p2.x = q.x + dy;
                    p2.y = q.y - dx;
                    if (hs.contains(p1) && hs.contains(p2)) {
                        ans = Math.max(ans, Math.abs(dx) * Math.abs(dx) + Math.abs(dy) * Math.abs(dy));
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
