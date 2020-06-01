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

    static class UfTree {
        int[] par;
        int[] sizes;

        UfTree(int n) {
            par = new int[n];
            sizes = new int[n];
            for (int i = 0; i < n; i++) {
                par[i] = i;
                sizes[i] = 1;
            }
        }

        int find(int x) {
            if (x == par[x]) {
                return x;
            }
            par[x] = find(par[x]);
            return par[x];
        }

        void unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return;
            }
            if (sizes[x] < sizes[y]) {
                int tmp = x;
                x = y;
                y = tmp;
            }
            par[y] = x;
            sizes[x] += sizes[y];
        }

        boolean same(int x, int y) {
            return find(x) == find(y);
        }

        int size(int x) {
            return sizes[find(x)];
        }
    }

    static class Solver {
        int n, q;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            n = in.nextInt();
            q = in.nextInt();
            UfTree uf = new UfTree(n);
            for (int i = 0; i < q; i++) {
                int com = in.nextInt();
                int xi = in.nextInt();
                int yi = in.nextInt();
                if (com == 0) {
                    uf.unite(xi, yi);
                } else {
                    out.println(uf.same(xi, yi) ? 1 : 0);
                }
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
