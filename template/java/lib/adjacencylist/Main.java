package template.java.lib.adjacencylist;

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

    // 辺に属性がある場合
    // static class Edge {
    // int to;
    // int cost;

    // Edge(int to, int cost) {
    // this.to = to;
    // this.cost = cost;
    // }
    // }

    static class Solver {
        // グラフの隣接リストでの表現。 (蟻本参照)
        // 辺があるかの判定: 最悪|V|
        // メモリ: |V| + |E|
        ArrayList<ArrayList<Integer>> g;
        int N;

        // write your code
        // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_A&lang=jp
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            g = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                ArrayList<Integer> al = new ArrayList<>();
                in.nextInt();
                int k = in.nextInt();
                for (int j = 0; j < k; j++) {
                    int vi = in.nextInt() - 1;
                    al.add(vi);
                }
                g.add(al);
            }

            int[][] ans = new int[N][N];
            for (int i = 0; i < N; i++) {
                int size = g.get(i).size();
                for (int j = 0; j < size; j++) {
                    ans[i][g.get(i).get(j)] = 1;
                }
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (j != 0) {
                        out.print(" ");
                    }
                    out.print(ans[i][j]);
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
