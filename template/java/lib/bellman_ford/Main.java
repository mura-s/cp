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

    static class Edge {
        int from;
        int to;
        int cost;

        Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }

    static class Solver {
        int MAX_V = 1001;
        int MAX_E = 2001;

        // 辺
        Edge[] es = new Edge[MAX_E];
        // 最短距離
        int[] d = new int[MAX_V];
        int V, E;
        int r;

        // 単一始点全点間最短路を求めるアルゴリズム。
        // 負辺があっても動作する。また負閉路も検出する。
        // ref. https://ei1333.github.io/luzhiled/snippets/graph/bellman-ford.html
        //
        // 計算量: O(VE)
        //
        // - falseを返す場合は負の経路が存在.
        // - d[i]がINFの場合は経路が存在しない.
        boolean bellmanFord(int s) {
            Arrays.fill(d, INF);
            d[s] = 0;

            for (int i = 0; i < V - 1; i++) {
                for (int j = 0; j < E; j++) {
                    Edge e = es[j];
                    if (d[e.from] == INF) {
                        continue;
                    }
                    d[e.to] = Math.min(d[e.to], d[e.from] + e.cost);
                }
            }

            for (int j = 0; j < E; j++) {
                Edge e = es[j];
                if (d[e.from] == INF) {
                    continue;
                }
                if (d[e.from] + e.cost < d[e.to]) {
                    return false;
                }
            }

            return true;
        }

        // write your code
        void solve(InputReader in, PrintWriter out) {
            V = in.nextInt();
            E = in.nextInt();
            r = in.nextInt();
            for (int i = 0; i < E; i++) {
                int si = in.nextInt();
                int ti = in.nextInt();
                int di = in.nextInt();
                es[i] = new Edge(si, ti, di);
            }

            boolean flag = bellmanFord(r);
            if (!flag) {
                out.println("NEGATIVE CYCLE");
                return;
            }
            for (int i = 0; i < V; i++) {
                if (d[i] == INF) {
                    out.println("INF");
                } else {
                    out.println(d[i]);
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
