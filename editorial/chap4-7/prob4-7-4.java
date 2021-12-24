import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		long K = sc.nextLong();
		long N = sc.nextLong();
		
		// 行列 A の作成
		long[][] A = new long[(1 << K)][(1 << K)];
		for (int i = 0; i < (1 << K); i++) {
			for (int j = 0; j < (1 << K); j++) {
				if (K == 2) A[i][j] = Mat2[i][j];
				if (K == 3) A[i][j] = Mat3[i][j];
				if (K == 4) A[i][j] = Mat4[i][j];
			}
		}
		
		// B = A^N を計算する
		long[][] B = copyMatrix(power(A, N, (1 << K)), (1 << K));
		
		// 答えの出力
		System.out.println(B[(1 << K) - 1][(1 << K) - 1]);
	}
	static final int MOD = 1000000007;
	static final long[][] Mat2 = {
		{0, 0, 0, 1},
		{0, 0, 1, 0},
		{0, 1, 0, 0},
		{1, 0, 0, 1}
	};
	static final long[][] Mat3 = {
		{0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 1},
		{0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 1, 0}
	};
	static final long[][] Mat4 = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
		{1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1}
	};
	static long[][] copyMatrix(long[][] A, int size_) {
		// 行列のコピー（そのまま「M = A;」とコピーすると、参照がコピーされるだけなので注意）
		long[][] M = new long[size_][size_];
		for (int i = 0; i < size_; i++) {
			for (int j = 0; j < size_; j++) {
				M[i][j] = A[i][j];
			}
		}
		return M;
	}
	static long[][] multiplication(long[][] A, long[][] B, int size_) {
		// 2×2 行列 A, B の積を返す関数
		long[][] C = new long[size_][size_];
		for (int i = 0; i < size_; i++) {
			for (int j = 0; j < size_; j++) {
				for (int k = 0; k < size_; k++) {
					C[i][j] += A[i][k] * B[k][j];
					C[i][j] %= MOD;
				}
			}
		}
		return C;
	}
	static long[][] power(long[][] A, long n, int size_) {
		// A の n 乗を返す関数
		long[][] P = copyMatrix(A, size_);
		long[][] Q = new long[size_][size_];
		boolean flag = false;
		for (int i = 0; i < 60; i++) {
			if ((n & (1L << i)) != 0L) {
				if (flag == false) {
					Q = copyMatrix(P, size_);
					flag = true;
				}
				else {
					Q = copyMatrix(multiplication(Q, P, size_), size_);
				}
			}
			P = copyMatrix(multiplication(P, P, size_), size_);
		}
		return Q;
	}
}