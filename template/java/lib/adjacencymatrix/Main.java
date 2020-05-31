package template.java.lib.adjacencymatrix;

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

    static class Solver {
        // グラフの隣接行列での表現。 (蟻本参照)
        // 辺があるかの判定: 定数時間
        // メモリ: |V|^2
        //
        // 無向グラフの場合、 g[i][j] == g[j][i] となるように設定する。
        // 有向グラフの場合、 i->jに向かう辺があるなら、g[i][j] == 1 となる。

        int MAX_V = 101;

        int N;
        int[][] G = new int[MAX_V][MAX_V];

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            for (int i = 0; i < N; i++) {
                int u = in.nextInt() - 1;
                int k = in.nextInt();
                for (int j = 0; j < k; j++) {
                    int vi = in.nextInt() - 1;
                    G[i][vi] = 1;
                }
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (j != 0) {
                        out.print(" ");
                    }
                    out.print(G[i][j]);
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
