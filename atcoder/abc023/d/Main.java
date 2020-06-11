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

    static class Ballon implements Comparable<Ballon> {
        long turn;
        long h;
        long s;

        Ballon(long v, long h, long s) {
            this.turn = (v - h) / s;
            this.h = h;
            this.s = s;
        }

        @Override
        public int compareTo(Ballon b) {
            return Long.compare(this.turn, b.turn);
        }
    }

    static class Solver {
        int N;
        long[] H, S;
        long ans;

        boolean checkLower(long v) {
            Ballon[] bs = new Ballon[N];
            for (int i = 0; i < N; i++) {
                if (H[i] > v) {
                    return false;
                }
                bs[i] = new Ballon(v, H[i], S[i]);
            }
            Arrays.sort(bs);
            long max = 0;
            for (int i = 0; i < N; i++) {
                if (bs[i].turn < i) {
                    return false;
                }
                max = Math.max(max, bs[i].h + bs[i].s * i);
            }
            ans = max;
            return true;
        }

        long lowerBound(long max) {
            long left = 0;
            long right = max + 1; // always satisfied with the check.
            while (left < right) {
                long mid = (left + right) / 2;
                if (checkLower(mid)) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        }

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            H = new long[N];
            S = new long[N];
            long max = 0;
            for (int i = 0; i < N; i++) {
                H[i] = in.nextLong();
                S[i] = in.nextLong();
                max = Math.max(max, H[i] + S[i] * (N - 1));
            }

            lowerBound(max);
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
