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
        int N, M;
        HashSet<Point> hs;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            M = in.nextInt();
            hs = new HashSet<>();
            for (int i = 0; i < M; i++) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                hs.add(new Point(x, y));
            }

            if (M == 0) {
                out.println(1);
                return;
            }

            int ans = 0;
            for (int i = 1; i < (1 << N); i++) {
                ArrayList<Integer> al = new ArrayList<>();
                int bit = i;
                int n = 0;
                while (bit > 0) {
                    if (bit % 2 == 1) {
                        al.add(n);
                    }
                    bit /= 2;
                    n++;
                }

                boolean flag = true;
                for (int j = 0; j < al.size(); j++) {
                    for (int k = j + 1; k < al.size(); k++) {
                        if (!hs.contains(new Point(al.get(j), al.get(k)))) {
                            flag = false;
                        }
                    }
                }
                if (flag) {
                    ans = Math.max(ans, al.size());
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
