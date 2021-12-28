import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] A = new int[M + 1];
		int[] B = new int[M + 1];
		for (int i = 1; i <= M; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
		}
		
		// 隣接リストの作成
		ArrayList<Integer>[] G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(B[i]);
			G[B[i]].add(A[i]);
		}
		
		// 答えを求める
		int answer = 0;
		for (int i = 1; i <= N; i++) {
			int cnt = 0;
			for (int j = 0; j < G[i].size(); j++) {
				// G[i].get(j) は頂点 i に隣接している頂点のうち j+1 個目
				if (G[i].get(j) < i) {
					cnt += 1;
				}
			}
			// 自分自身より番号が小さい隣接頂点が 1 つであれば answer に 1 を加算する
			if (cnt == 1) {
				answer += 1;
			}
		}
		
		// 答えを出力
		System.out.println(answer);
	}
}
