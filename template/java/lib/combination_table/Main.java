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
        // ref. http://drken1215.hatenablog.com/entry/2018/06/08/210000
        int MAX = 200001;

        // fac[n]: n!
        // finv[n]: (n!)^-1
        // inv[n]: nの逆元
        long[] fac = new long[MAX];
        long[] finv = new long[MAX];
        long[] inv = new long[MAX];

        // テーブルを作る前処理
        void combInit() {
            fac[0] = fac[1] = 1;
            finv[0] = finv[1] = 1;
            inv[1] = 1;
            for (int i = 2; i < MAX; i++) {
                fac[i] = fac[i - 1] * i % MOD;
                inv[i] = MOD - inv[(int) MOD % i] * (MOD / i) % MOD;
                finv[i] = finv[i - 1] * inv[i] % MOD;
            }
        }

        // 二項係数計算 (combination)
        // nCk = (n!) * (k!)^-1 * ((n-k)!)^-1 として計算
        long comb(int n, int k) {
            if (n < k) {
                return 0;
            }
            if (n < 0 || k < 0) {
                return 0;
            }
            return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
        }

        int W, H;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            W = in.nextInt() - 1;
            H = in.nextInt() - 1;
            combInit();

            long ans = comb(W + H, W);
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
