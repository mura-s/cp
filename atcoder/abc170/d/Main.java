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
        int N;
        int[] a;
        HashMap<Integer, Integer> mp;
        boolean[] ps;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            mp = new HashMap<>();
            a = new int[N];
            for (int i = 0; i < N; i++) {
                a[i] = in.nextInt();
                mp.putIfAbsent(a[i], 0);
                int v = mp.get(a[i]);
                mp.put(a[i], v + 1);
            }
            ps = new boolean[1000001];
            for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
                int v = entry.getKey();
                int tmp = v + v;
                while (tmp < 1000001) {
                    ps[tmp] = true;
                    tmp += v;
                }
            }

            int ans = 0;
            for (int i = 0; i < N; i++) {
                int v = a[i];
                if (!ps[v] && mp.get(v) == 1) {
                    ans++;
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
