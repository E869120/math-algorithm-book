import java.util.*;

class Code_4_07_1 {
	public static void main(String[] args) {
		// 入力 → 累乗の計算（N が 2 以上でなければ正しく動作しないので注意）
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long[][] A = new long[2][2];
		A[0][0] = 1; A[0][1] = 1;
		A[1][0] = 1; A[1][1] = 0;
		long[][] B = copyMatrix(power(A, N - 1));
		
		// 答えの計算 → 出力（下から 9 桁目が 0 の場合、最初に 0 を含まない形で出力していることに注意）
		long answer = (B[1][0] + B[1][1]) % MOD;
		System.out.println(answer);
	}
	static final int MOD = 1000000000;
	static long[][] copyMatrix(long[][] A) {
		// 行列のコピー（そのまま「M = A;」とコピーすると、参照がコピーされるだけなので注意）
		long[][] M = new long[2][2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				M[i][j] = A[i][j];
			}
		}
		return M;
	}
	static long[][] multiplication(long[][] A, long[][] B) {
		// 2×2 行列 A, B の積を返す関数
		long[][] C = new long[2][2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					C[i][j] += A[i][k] * B[k][j];
					C[i][j] %= MOD;
				}
			}
		}
		return C;
	}
	static long[][] power(long[][] A, long n) {
		// A の n 乗を返す関数
		long[][] P = copyMatrix(A);
		long[][] Q = { { 0, 0 }, { 0, 0 } };
		boolean flag = false;
		for (int i = 0; i < 60; i++) {
			if ((n & (1L << i)) != 0L) {
				if (flag == false) {
					Q = copyMatrix(P);
					flag = true;
				}
				else {
					Q = copyMatrix(multiplication(Q, P));
				}
			}
			P = copyMatrix(multiplication(P, P));
		}
		return Q;
	}
}
