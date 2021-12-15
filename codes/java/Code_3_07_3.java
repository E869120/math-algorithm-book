import java.util.*;

class Code_3_07_3 {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int W = sc.nextInt();
		int[] w = new int[N + 1];
		int[] v = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			w[i] = sc.nextInt();
			v[i] = sc.nextInt();
		}
		
		// 配列の初期化
		long INF = 1000000000000000000L;
		long[][] dp = new long[N + 1][W + 1];
		dp[0][0] = 0;
		for (int i = 1; i <= W; i++) {
			dp[0][i] = -INF;
		}
		
		// 動的計画法
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= W; j++) {
				if (j < w[i]) {
					// j < w[i] のとき、方法 A だけしか選べない
					dp[i][j] = dp[i - 1][j];
				}
				else {
					// j >= w[i] のとき、方法 A・方法 B どちらも選べる
					dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
				}
			}
		}
		
		// 答えを計算して出力
		long answer = 0;
		for (int i = 0; i <= W; i++) {
			answer = Math.max(answer, dp[N][i]);
		}
		System.out.println(answer);
	}
}
