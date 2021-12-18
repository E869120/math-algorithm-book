import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int N = sc.nextInt();
		int S = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		
		// 配列の初期化
		boolean[][] dp = new boolean[N + 1][S + 1];
		dp[0][0] = true;
		for (int i = 1; i <= S; i++) {
			dp[0][i] = false;
		}
		
		// 動的計画法
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= S; j++) {
				if (j < A[i]) {
					// j < A[i] のとき、カード i を選べない
					dp[i][j] = dp[i - 1][j];
				}
				else {
					// j >= A[i] のとき、選ぶ / 選ばない 両方の選択肢がある
					if (dp[i - 1][j] == true || dp[i - 1][j - A[i]] == true) {
						dp[i][j] = true;
					}
					else {
						dp[i][j] = false;
					}
				}
			}
		}
		
		// 答えを計算して出力
		if (dp[N][S] == true) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}