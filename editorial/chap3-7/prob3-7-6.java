import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		
		// 配列の初期化
		long[] dp1 = new long[N + 1];
		long[] dp2 = new long[N + 1];
		dp1[0] = 0;
		dp2[0] = 0;
		
		// 動的計画法
		for (int i = 1; i <= N; i++) {
			dp1[i] = dp2[i - 1] + A[i];
			dp2[i] = Math.max(dp1[i - 1], dp2[i - 1]);
		}
		
		// 答えを計算して出力
		long Answer = Math.max(dp1[N], dp2[N]);
		System.out.println(Answer);
	}
}