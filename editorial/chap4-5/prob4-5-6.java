import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt(), W = sc.nextInt();
		int sx = sc.nextInt(), sy = sc.nextInt();
		int gx = sc.nextInt(), gy = sc.nextInt();
		String[] c = new String[H + 1];
		for (int i = 1; i <= H; i++) {
			c[i] = sc.next();
		}
		int start = (sx - 1) * W + sy;
		int goal = (gx - 1) * W + gy;
		
		// 隣接リストの作成
		ArrayList<Integer>[] G = new ArrayList[H * W + 1];
		for (int i = 1; i <= H * W; i++) {
			G[i] = new ArrayList<Integer>();
		}
		
		// 横方向の辺 [(i, j) - (i, j+1)] をグラフに追加
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W - 1; j++) {
				if (c[i].charAt(j - 1) == '.' && c[i].charAt(j) == '.') {
					int idx1 = (i - 1) * W + j; // マス (i, j) の頂点番号
					int idx2 = (i - 1) * W + (j + 1); // マス (i, j + 1) の頂点番号
					G[idx1].add(idx2);
					G[idx2].add(idx1);
				}
			}
		}
		
		// 縦方向の辺 [(i, j) - (i+1, j)] をグラフに追加
		for (int i = 1; i <= H - 1; i++) {
			for (int j = 1; j <= W; j++) {
				if (c[i].charAt(j - 1) == '.' && c[i + 1].charAt(j - 1) == '.') {
					int idx1 = (i - 1) * W + j; // マス (i, j) の頂点番号
					int idx2 = i * W + j; // マス (i + 1, j) の頂点番号
					G[idx1].add(idx2);
					G[idx2].add(idx1);
				}
			}
		}
		
		// 幅優先探索の初期化 (dist[i] = -1 のとき、未到達の白色頂点である）
		int[] dist = new int[H * W + 1];
		for (int i = 1; i <= H * W; i++) {
			dist[i] = -1;
		}
		Queue<Integer> Q = new LinkedList<>(); // キュー Q を定義する
		dist[start] = 0;
		Q.add(start); // Q に start を追加

		// 幅優先探索
		while (Q.size() >= 1) {
			int pos = Q.remove(); // Q の先頭を調べ、これを取り出す
			for (int i = 0; i < G[pos].size(); i++) {
				int nex = G[pos].get(i);
				if (dist[nex] == -1) {
					dist[nex] = dist[pos] + 1;
					Q.add(nex); // Q に nex を追加
				}
			}
		}
		
		// 答えを出力
		System.out.println(dist[goal]);
	}
}
