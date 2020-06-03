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
    static long MOD = (long) 1e9 + 7;

    static class Solver {
        int N;
        char[][] S;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            S = new char[2][N];
            String S1 = in.next();
            for (int i = 0; i < N; i++) {
                S[0][i] = S1.charAt(i);
            }
            String S2 = in.next();
            for (int i = 0; i < N; i++) {
                S[1][i] = S2.charAt(i);
            }

            boolean[] used = new boolean[N];
            long ans = 0;
            if (S[0][0] == S[1][0]) {
                ans = 3;
                used[0] = true;
            } else {
                ans = 6;
                used[0] = true;
                used[1] = true;
            }
            for (int i = 1; i < N; i++) {
                if (used[i]) {
                    continue;
                }
                if (S[0][i] == S[1][i]) {
                    ans *= ((S[0][i - 1] == S[1][i - 1]) ? 2 : 1);
                    used[i] = true;
                } else {
                    ans *= ((S[0][i - 1] == S[1][i - 1]) ? 2 : 3);
                    used[i] = true;
                    used[i + 1] = true;
                }
                ans %= MOD;
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
