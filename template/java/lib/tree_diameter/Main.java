import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main implements Runnable {
    // static int INF = (1 << 30) - 1;
    // static long L_INF = (1L << 62) - 1;
    // static long MOD = (long) 1e9 + 7;

    static class Edge {
        int to;
        int cost;

        Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }

    static class Pair {
        int cost;
        int idx;

        Pair(int cost, int idx) {
            this.cost = cost;
            this.idx = idx;
        }
    }

    static class Solver {
        int n;
        ArrayList<ArrayList<Edge>> g;

        Pair dfs(int idx, int parent) {
            Pair ret = new Pair(0, idx);
            for (Edge e : g.get(idx)) {
                if (e.to == parent) {
                    continue;
                }
                Pair p = dfs(e.to, idx);
                p.cost += e.cost;
                if (ret.cost < p.cost) {
                    ret = p;
                }
            }
            return ret;
        }

        int treeDiameter() {
            Pair p = dfs(0, -1);
            Pair q = dfs(p.idx, -1);
            return q.cost;
        }

        // write your code
        // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp
        void solve(InputReader in, PrintWriter out) {
            n = in.nextInt();
            g = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                ArrayList<Edge> al = new ArrayList<>();
                g.add(al);
            }
            for (int i = 0; i < n - 1; i++) {
                int si = in.nextInt();
                int ti = in.nextInt();
                int wi = in.nextInt();
                g.get(si).add(new Edge(ti, wi));
                g.get(ti).add(new Edge(si, wi));
            }

            int ans = treeDiameter();
            out.println(ans);
        }

        void debug(Object... os) {
            System.err.println(Arrays.deepToString(os));
        }
    }

    public void run() {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        solver.solve(in, out);
        out.close();
    }

    public static void main(String[] args) {
        // 256MBスタックを確保して実行
        new Thread(null, new Main(), "", 256 * 1024 * 1024).start();
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
