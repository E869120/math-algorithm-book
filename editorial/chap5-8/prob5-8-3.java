import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] A = new int[M + 1];
		int[] B = new int[M + 1];
		long[] C = new long[M + 1];
		for (int i = 1; i <= M; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
			C[i] = sc.nextLong();
		}
		
		// 隣接リストの作成
		ArrayList<PairLong>[] G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<PairLong>();
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(new PairLong((long)B[i], C[i]));
			G[B[i]].add(new PairLong((long)A[i], C[i]));
		}
		
		// ダイクストラ法：配列の初期化など
		long[] dist = new long[N + 1];
		boolean[] used = new boolean[N + 1];
		for (int i = 1; i <= N; i++) {
			dist[i] = (1L << 60);
			used[i] = false;
		}
		Queue<PairLong> Q = new PriorityQueue<PairLong>();
		dist[1] = 0L;
		Q.add(new PairLong(0L, (long)1));
		
		// ダイクストラ法：優先度付きキューの更新
		while (Q.size() >= 1) {
			int pos = (int)Q.poll().second;
			if (used[pos] == true) {
				continue;
			}
			used[pos] = true;
			for (PairLong i : G[pos]) {
				int to = (int)i.first;
				long cost = dist[pos] + i.second;
				if (dist[to] > cost) {
					dist[to] = cost;
					Q.add(new PairLong(dist[to], (long)to));
				}
			}
		}
		
		// 答えを出力
		if (dist[N] != (1L << 60)) {
			System.out.println(dist[N]);
		}
		else {
			System.out.println(-1);
		}
	}
	
	// long 型のペアのクラス PairLong
	static class PairLong implements Comparable<PairLong> {
		long first, second;
		public PairLong(long first_, long second_) {
			super();
			this.first = first_;
			this.second = second_;
		}
		@Override public int compareTo(PairLong p) {
			// PairLong 型同士の比較をする関数
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