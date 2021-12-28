import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		
		// 隣接リストの作成
		ArrayList<PairInt>[] G = new ArrayList[K];
		for (int i = 0; i < K; i++) {
			G[i] = new ArrayList<PairInt>();
		}
		
		// グラフの辺を追加
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < 10; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				G[i].add(new PairInt((i * 10 + j) % K, j));
			}
		}
		
		// ダイクストラ法：配列の初期化など
		int[] dist = new int[K];
		boolean[] used = new boolean[K];
		for (int i = 0; i < K; i++) {
			dist[i] = (1 << 30);
			used[i] = false;
		}
		Queue<PairInt> Q = new PriorityQueue<PairInt>();
		Q.add(new PairInt(0, 0)); // ここでは dist[0] = 0 にはしないことに注意！
		
		// ダイクストラ法：優先度付きキューの更新
		while (Q.size() >= 1) {
			int pos = Q.poll().second;
			if (used[pos] == true) {
				continue;
			}
			used[pos] = true;
			for (PairInt i : G[pos]) {
				int to = i.first;
				int cost = dist[pos] + i.second;
				if (pos == 0) {
					cost = i.second; // 頂点 0 の場合は例外
				}
				if (dist[to] > cost) {
					dist[to] = cost;
					Q.add(new PairInt(dist[to], to));
				}
			}
		}
		
		// 答えを出力
		System.out.println(dist[0]);
	}
	
	// int 型のペアのクラス PairInt
	static class PairInt implements Comparable<PairInt> {
		int first, second;
		public PairInt(int first_, int second_) {
			super();
			this.first = first_;
			this.second = second_;
		}
		@Override public int compareTo(PairInt p) {
			// PairInt 型同士の比較をする関数
			if (this.first < p.first || (this.first == p.first && this.second < p.second)) {
				return -1;
			}
			if (this.first > p.first || (this.first == p.first && this.second > p.second)) {
				return 1;
			}
			return 0;
		}
	}
}
