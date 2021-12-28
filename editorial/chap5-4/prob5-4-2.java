import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int[][] A = new int[H + 2][W + 2];
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) A[i][j] = Integer.parseInt(sc.next());
		}
		
		// 行の総和を計算する
		int[] gyou = new int[H + 2];
		for (int i = 1; i <= H; i++) {
			gyou[i] = 0;
			for (int j = 1; j <= W; j++) gyou[i] += A[i][j];
		}
		
		// 列の総和を計算する
		int[] retu = new int[W + 2];
		for (int j = 1; j <= W; j++) {
			retu[j] = 0;
			for (int i = 1; i <= H; i++) retu[j] += A[i][j];
		}
		
		// 各マスに対する答えを計算する
		int[][] Answer = new int[H + 2][W + 2];
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				Answer[i][j] = gyou[i] + retu[j] - A[i][j];
			}
		}
		
		// 空白区切りで出力
		StringBuilder ans = new StringBuilder();
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (j != 1) ans.append(' ');
				ans.append(Answer[i][j]);
			}
			ans.append('\n');
		}
		System.out.println(ans.toString());
	}
}