import java.util.*;

class Code_4_05_1 {
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
			G[i] = new ArrayList<Integer>(); // G[i] は頂点 i に隣接する頂点のリスト
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(B[i]); // 頂点 A[i] に隣接する頂点として B[i] を追加
			G[B[i]].add(A[i]); // 頂点 B[i] に隣接する頂点として A[i] を追加
		}
		
		// 出力（G[i].size() は頂点 i に隣接する頂点のリストの大きさ ＝ 次数）
		for (int i = 1; i <= N; i++) {
			System.out.format("%d: {", i);
			for (int j = 0; j < G[i].size(); j++) {
				if (j >= 1) {
					System.out.print(",");
				}
				System.out.print(G[i].get(j)); // G[i].get(j) は頂点 i に隣接する頂点のうち j+1 番目のもの
			}
			System.out.println("}");
		}
	}
}
