import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] T = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			T[i] = sc.nextInt();
		}
		
		// 配列の初期化
		int sumT = 0;
		for (int i = 1; i <= N; i++) {
			sumT += T[i];
		}
		boolean[][] dp = new boolean[N + 1][sumT + 1];
		for (int i = 1; i <= sumT; i++) {
			dp[0][i] = false;
		}
		dp[0][0] = true;
		
		// 動的計画法
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= sumT; j++) {
				if (j < T[i]) {
					if (dp[i - 1][j] == true) dp[i][j] = true;
					else dp[i][j] = false;
				}
				if (j >= T[i]) {
					if (dp[i - 1][j] == true || dp[i - 1][j - T[i]] == true) dp[i][j] = true;
					else dp[i][j] = false;
				}
			}
		}
		
		// 答えを計算して出力
		int answer = (1 << 30);
		for (int i = 0; i <= sumT; i++) {
			if (dp[N][i] == true) {
				int cookingTime = Math.max(i, sumT - i);
				answer = Math.min(answer, cookingTime);
			}
		}
		System.out.println(answer);
	}
}