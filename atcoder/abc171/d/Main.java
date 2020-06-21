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
        long[] A;
        HashMap<Long, Long> mp;
        long sum;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            A = new long[N];
            mp = new HashMap<>();
            for (int i = 0; i < N; i++) {
                A[i] = in.nextLong();
                sum += A[i];
                Long l = 0l;
                mp.putIfAbsent(A[i], l);
                mp.put(A[i], mp.get(A[i]) + 1);
            }
            int Q = in.nextInt();
            for (int i = 0; i < Q; i++) {
                long b = in.nextLong();
                long c = in.nextLong();
                Long v = mp.get(b);
                if (v != null) {
                    Long l = 0l;
                    long bNum = mp.get(b);
                    sum -= (bNum * b);
                    // long cNum = mp.get(c);
                    mp.putIfAbsent(c, l);
                    mp.put(c, mp.get(c) + v);
                    mp.put(b, l);
                    sum += (bNum * c);
                }
                out.println(sum);
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
