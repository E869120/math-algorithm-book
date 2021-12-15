import java.util.*;

class Code_4_02_1 {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Q = sc.nextInt();
		int[] A = new int[N + 1];
		int[] L = new int[Q + 1];
		int[] R = new int[Q + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		for (int j = 1; j <= Q; j++) {
			L[j] = sc.nextInt();
			R[j] = sc.nextInt();
		}
		
		// 累積和を求める
		int[] B = new int[N + 1];
		B[0] = 0;
		for (int i = 1; i <= N; i++) {
			B[i] = B[i - 1] + A[i];
		}
		
		// 答えを計算して出力
		for (int j = 1; j <= Q; j++) {
			System.out.println(B[R[j]] - B[L[j] - 1]);
		}
	}
}
