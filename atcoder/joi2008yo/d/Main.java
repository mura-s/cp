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
        int m;
        int n;
        Point[] p;
        HashSet<Point> hs;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            m = in.nextInt();
            p = new Point[m];
            for (int i = 0; i < m; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                p[i] = new Point(x, y);
            }
            n = in.nextInt();
            hs = new HashSet<>();
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                hs.add(new Point(x, y));
            }

            int ansX = 0;
            int ansY = 0;
            for (Point q : hs) {
                int dx = q.x - p[0].x;
                int dy = q.y - p[0].y;
                boolean flag = true;
                for (int i = 1; i < m; i++) {
                    if (!hs.contains(new Point(p[i].x + dx, p[i].y + dy))) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ansX = dx;
                    ansY = dy;
                }
            }
            out.printf("%d %d\n", ansX, ansY);
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
