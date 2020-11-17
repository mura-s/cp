import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    static int INF = (1 << 31) - 1;
    // static long L_INF = (1L << 62) - 1;
    // static long MOD = (long) 1e9 + 7;

    static class Solver {
        int MAX_V = 101;

        int[][] d = new int[MAX_V][MAX_V];
        int V, E;

        // 隣接行列で表されるグラフの全点間最短路を求めるアルゴリズム。
        // 負辺があっても動作する。負閉路が存在する場合はそれも検出する。
        // https://ei1333.github.io/luzhiled/snippets/graph/warshall-floyd.html
        //
        // 計算量: O(V^3)
        void warshall_floyd() {
            for (int k = 0; k < V; k++) {
                for (int i = 0; i < V; i++) {
                    for (int j = 0; j < V; j++) {
                        if (d[i][k] == INF || d[k][j] == INF) {
                            continue;
                        }
                        d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
        }

        // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp
        // write your code
        void solve(InputReader in, PrintWriter out) {
            V = in.nextInt();
            E = in.nextInt();
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (i == j) {
                        d[i][j] = 0;
                    } else {
                        d[i][j] = INF;
                    }
                }
            }
            for (int i = 0; i < E; i++) {
                int si = in.nextInt();
                int ti = in.nextInt();
                int di = in.nextInt();
                d[si][ti] = di;
            }

            warshall_floyd();
            for (int i = 0; i < V; i++) {
                if (d[i][i] < 0) {
                    out.println("NEGATIVE CYCLE");
                    return;
                }
            }

            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (j != 0) {
                        out.print(" ");
                    }
                    if (d[i][j] == INF) {
                        out.print("INF");
                    } else {
                        out.print(d[i][j]);
                    }
                }
                out.println();
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
