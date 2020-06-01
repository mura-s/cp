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
        int[] P, Q;
        int[] arr;

        boolean nextPermutation(int[] array) {
            for (int i = array.length - 1; i > 0; i--) {
                if (array[i - 1] < array[i]) {
                    int j = find(array, array[i - 1], i, array.length - 1);
                    int temp = array[j];
                    array[j] = array[i - 1];
                    array[i - 1] = temp;
                    Arrays.sort(array, i, array.length);
                    return true;
                }
            }
            return false;
        }

        int find(int[] array, int dest, int f, int l) {
            if (f == l) {
                return f;
            }
            int m = (f + l + 1) / 2;
            return (array[m] <= dest) ? find(array, dest, f, m - 1) : find(array, dest, m, l);
        }

        // write your code
        // https://atcoder.jp/contests/abc150/tasks/abc150_c
        void solve(InputReader in, PrintWriter out) {
            N = in.nextInt();
            P = new int[N];
            Q = new int[N];
            arr = new int[N];
            for (int i = 0; i < N; i++) {
                P[i] = in.nextInt();
            }
            for (int i = 0; i < N; i++) {
                Q[i] = in.nextInt();
            }
            for (int i = 0; i < N; i++) {
                arr[i] = i + 1;
            }

            int a = 1;
            do {
                boolean flag = true;
                for (int i = 0; i < N; i++) {
                    if (P[i] != arr[i]) {
                        a++;
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            } while (nextPermutation(arr));

            Arrays.sort(arr);
            int b = 1;
            do {
                boolean flag = true;
                for (int i = 0; i < N; i++) {
                    if (Q[i] != arr[i]) {
                        b++;
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            } while (nextPermutation(arr));

            out.println(Math.abs(a - b));
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
