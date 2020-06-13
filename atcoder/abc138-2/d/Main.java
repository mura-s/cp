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
        int N, Q;
        ArrayList<Integer>[] g;
        int[] x;
        int[] ans;
        boolean[] visited;

        void dfs(int v, int before) {
            if (visited[v]) {
                return;
            }
            visited[v] = true;
            ans[v] += x[v];
            if (before != -1) {
                ans[v] += ans[before];
            }
            for (int i = 0; i < g[v].size(); i++) {
                dfs(g[v].get(i), v);
            }
        }

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            Q = in.nextInt();
            g = new ArrayList[N];
            for (int i = 0; i < N; i++) {
                ArrayList<Integer> al = new ArrayList<>();
                g[i] = al;
            }
            for (int i = 0; i < N - 1; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                g[a].add(b);
                g[b].add(a);
            }
            x = new int[N];
            for (int i = 0; i < Q; i++) {
                int pi = in.nextInt() - 1;
                int xi = in.nextInt();
                x[pi] += xi;
            }
            ans = new int[N];
            visited = new boolean[N];
            dfs(0, -1);
            for (int i = 0; i < N; i++) {
                if (i != 0) {
                    out.print(" ");
                }
                out.print(ans[i]);
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
