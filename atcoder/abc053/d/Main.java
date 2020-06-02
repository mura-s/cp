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
        int N;
        HashMap<Integer, Integer> mp;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            mp = new HashMap<>();
            for (int i = 0; i < N; i++) {
                int a = in.nextInt();
                mp.putIfAbsent(a, 0);
                mp.put(a, mp.get(a) + 1);
            }

            int dup = 0;
            for (Map.Entry<Integer, Integer> e : mp.entrySet()) {
                if (e.getValue() > 1) {
                    dup += e.getValue() - 1;
                }
            }

            int ans = 0;
            if (dup % 2 == 0) {
                ans = N - dup;
            } else {
                ans = N - dup - 1;
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
