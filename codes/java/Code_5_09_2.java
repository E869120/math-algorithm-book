import java.util.*;

class Code_5_09_2 {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] L = new int[N + 1];
		int[] R = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			L[i] = sc.nextInt();
			R[i] = sc.nextInt();
		}
		
		// 映画の選び方のシミュレーション
		// 見れる映画の終了時刻の最小値 minEndtime は、最初 1000000 (INF で設定）のようなあり得ない値にセットする
		final int INF = 1000000;
		int currentTime = 0; // currentTime は現在時刻（直前に見た映画の終了時刻）
		int answer = 0;
		while (true) {
			int minEndtime = INF;
			for (int i = 1; i <= N; i++) {
				if (L[i] >= currentTime) {
					minEndtime = Math.min(minEndtime, R[i]);
				}
			}
			if (minEndtime == INF) {
				break;
			}
			currentTime = minEndtime;
			answer += 1;
		}
		
		// 答えの出力
		System.out.println(answer);
	}
}
