import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    static int INF = (1 << 31) - 1;
    // static long L_INF = (1L << 62) - 1;
    // static long MOD = (long) 1e9 + 7;

    // セグメント木による RMQ (Range Minimum Query) の実装
    // RMQ以外にする場合は、minの部分を全て他の関数に置換する
    //
    // 計算量
    // - 初期化: O(nlogn)
    // - O(n)でも実装できるが、O(nlogn)の実装になっている
    // - init後にupdateで初期化
    // - update: O(logn)
    // - query: O(logn)
    static class SegmentTree {
        int MAX_N = 1 << 17; // 131072

        int n;
        int[] dat = new int[2 * MAX_N - 1];

        SegmentTree(int n_) {
            // 簡単のため、要素数を2のべき乗に
            n = 1;
            while (n < n_) {
                n *= 2;
            }
            // すべての値をINFに
            for (int i = 0; i < 2 * n - 1; i++) {
                dat[i] = INF;
            }
        }

        // k番目の値 (0-indexed) をaに変更
        void update(int k, int a) {
            // 葉の節点
            k += n - 1;
            dat[k] = a;
            // 登りながら更新
            while (k > 0) {
                k = (k - 1) / 2;
                dat[k] = Math.min(dat[k * 2 + 1], dat[k * 2 + 2]);
            }
        }

        // [a, b) の最小値を求める
        // 後ろのほうの引数は、計算の簡単のための引数。
        // kは節点の番号、l, rはその節点が [l, r) に対応づいていることを表す。
        // したがって、外からは inner_query(a, b, 0, 0, n) として呼ぶ。
        int inner_query(int a, int b, int k, int l, int r) {
            // [a, b) と [l, r) が交差しなければ INF
            if (r <= a || b <= l) {
                return INF;
            }

            // [a, b) が [l, r) を完全に含んでいれば、この節点の値
            if (a <= l && r <= b) {
                return dat[k];
            } else {
                // そうでなければ、2つの子の最小値
                int vl = inner_query(a, b, k * 2 + 1, l, (l + r) / 2);
                int vr = inner_query(a, b, k * 2 + 2, (l + r) / 2, r);
                return Math.min(vl, vr);
            }
        }

        // [a, b) の最小値を求める
        int query(int a, int b) {
            return inner_query(a, b, 0, 0, n);
        }
    }

    static class Solver {
        int n, q;

        // write your code
        // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
        void solve(InputReader in, PrintWriter out) {
            n = in.nextInt();
            q = in.nextInt();
            SegmentTree st = new SegmentTree(n);
            for (int i = 0; i < q; i++) {
                int com = in.nextInt();
                int xi = in.nextInt();
                int yi = in.nextInt();
                if (com == 0) {
                    st.update(xi, yi);
                } else {
                    out.println(st.query(xi, yi + 1));
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
