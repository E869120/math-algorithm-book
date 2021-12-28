import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long K = sc.nextLong();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();
		
		// 配列の初期化
		long[] First = new long[N + 1];
		long[] Second = new long[N + 1];
		for (int i = 1; i <= N; i++) First[i] = -1;
		for (int i = 1; i <= N; i++) Second[i] = -1;
		
		// 答えを求める（cur は現在いる町の番号）
		long cnt = 0;
		int cur = 1;
		while (true) {
			// First, Second の更新
			if (First[cur] == -1) First[cur] = cnt;
			else if (Second[cur] == -1) Second[cur] = cnt;
			
			// K 回の移動後に町 cur にいるか判定
			if (cnt == K) {
				System.out.println(cur);
				System.exit(0);
			}
			else if (Second[cur] != -1L && (K - First[cur]) % (Second[cur] - First[cur]) == 0) {
				System.out.println(cur);
				System.exit(0);
			}
			
			// 移動
			cur = A[cur];
			cnt += 1;
		}
	}
}