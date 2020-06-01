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

    static class Edge {
        int to;
        int cost;

        Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }

    static class Vertex implements Comparable<Vertex> {
        // 重み
        int cost;
        // 頂点の番号
        int v;

        Vertex(int cost, int v) {
            this.cost = cost;
            this.v = v;
        }

        @Override
        public int compareTo(Vertex vert) {
            return Integer.compare(this.cost, vert.cost);
        }
    }

    static class Solver {
        int V, E;
        ArrayList<ArrayList<Edge>> G;

        // 最小全域木 (全域木のうち、その辺群の重みの総和が最小になる木)
        // を求めるアルゴリズム
        // https://ei1333.github.io/luzhiled/snippets/graph/prim.html
        //
        // 計算量: O(ElogV)
        int prim() {
            int ans = 0;
            boolean[] used = new boolean[V];
            Arrays.fill(used, false);
            PriorityQueue<Vertex> que = new PriorityQueue<>();
            que.add(new Vertex(0, 0));
            while (!que.isEmpty()) {
                Vertex vert = que.poll();
                int v = vert.v;
                if (used[v]) {
                    continue;
                }
                used[v] = true;
                ans += vert.cost;

                int size = G.get(v).size();
                for (int i = 0; i < size; i++) {
                    que.add(new Vertex(G.get(v).get(i).cost, G.get(v).get(i).to));
                }
            }
            return ans;
        }

        // write your code
        // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
        void solve(InputReader in, PrintWriter out) {
            V = in.nextInt();
            E = in.nextInt();
            G = new ArrayList<>();
            for (int i = 0; i < V; i++) {
                ArrayList<Edge> al = new ArrayList<>();
                G.add(al);
            }
            for (int i = 0; i < E; i++) {
                int si = in.nextInt();
                int ti = in.nextInt();
                int wi = in.nextInt();
                G.get(si).add(new Edge(ti, wi));
                G.get(ti).add(new Edge(si, wi));
            }

            out.println(prim());
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
