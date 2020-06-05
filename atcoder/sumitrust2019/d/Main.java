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
        String S;

        // write your code
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            S = in.next();

            int ans = 0;
            for (int i = 0; i <= 9; i++) {
                for (int j = 0; j <= 9; j++) {
                    for (int k = 0; k <= 9; k++) {
                        int cnt = 0;
                        for (int l = 0; l < N; l++) {
                            int c = S.charAt(l) - '0';
                            if (cnt == 0 && i == c) {
                                cnt++;
                            } else if (cnt == 1 && j == c) {
                                cnt++;
                            } else if (cnt == 2 && k == c) {
                                cnt++;
                            }

                            if (cnt == 3) {
                                ans++;
                                break;
                            }
                        }
                    }
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
