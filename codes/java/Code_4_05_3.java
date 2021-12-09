import java.util.*;

class Code_4_05_3 {
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
		
		// 幅優先探索の初期化 (dist[i] = -1 のとき、未到達の白色頂点である）
		int[] dist = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			dist[i] = -1;
		}
		Queue<Integer> Q = new LinkedList<>(); // キュー Q を定義する
		dist[1] = 0;
		Q.add(1); // Q に 1 を追加（操作 1）

		// 幅優先探索
		while (Q.size() >= 1) {
			int pos = Q.remove(); // Q の先頭を調べ、これを取り出す（操作 2, 3）
			for (int i = 0; i < G[pos].size(); i++) {
				int nex = G[pos].get(i);
				if (dist[nex] == -1) {
					dist[nex] = dist[pos] + 1;
					Q.add(nex); // Q に nex を追加（操作 1）
				}
			}
		}
		
		// 頂点 1 から各頂点までの最短距離を出力
		for (int i = 1; i <= N; i++) {
			System.out.println(dist[i]);
		}
	}
}
