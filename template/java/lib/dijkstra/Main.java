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
        int to;
        int cost;

        Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }

    static class Vertex implements Comparable<Vertex> {
        // 最短距離
        int minDist;
        // 頂点の番号
        int v;

        Vertex(int minDist, int v) {
            this.minDist = minDist;
            this.v = v;
        }

        @Override
        public int compareTo(Vertex vert) {
            return Integer.compare(this.minDist, vert.minDist);
        }
    }

    static class Solver {
        int MAX_V = 100001;

        int V, E;
        int r; // 始点
        ArrayList<ArrayList<Edge>> G;
        int[] d = new int[MAX_V];
        int[] prevPath = new int[MAX_V]; // prev_path[i]の流入元の点

        // 負辺のない単一始点全点間最短路を求めるアルゴリズム。
        // 蟻本参照
        void dijkstra(int s) {
            PriorityQueue<Vertex> que = new PriorityQueue<>();
            Arrays.fill(d, INF);
            Arrays.fill(prevPath, -1);
            d[s] = 0;
            que.add(new Vertex(0, s));

            while (!que.isEmpty()) {
                Vertex vert = que.poll();
                int v = vert.v;
                if (d[v] < vert.minDist) {
                    continue;
                }

                int size = G.get(v).size();
                for (int i = 0; i < size; i++) {
                    Edge e = G.get(v).get(i);
                    if (d[e.to] > d[v] + e.cost) {
                        d[e.to] = d[v] + e.cost;
                        que.add(new Vertex(d[e.to], e.to));
                        prevPath[e.to] = v;
                    }
                }
            }
        }

        // 経路復元
        ArrayList<Integer> getPath(int e) {
            ArrayList<Integer> path = new ArrayList<>();
            for (; e != -1; e = prevPath[e]) {
                path.add(e);
            }
            Collections.reverse(path);
            return path;
        }

        // write your code
        // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
        void solve(InputReader in, PrintWriter out) {
            V = in.nextInt();
            E = in.nextInt();
            r = in.nextInt();
            G = new ArrayList<>();
            for (int i = 0; i < V; i++) {
                ArrayList<Edge> al = new ArrayList<>();
                G.add(al);
            }
            for (int i = 0; i < E; i++) {
                int si = in.nextInt();
                int ti = in.nextInt();
                int di = in.nextInt();
                G.get(si).add(new Edge(ti, di));
            }
            dijkstra(r);

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
