import java.util.*;

class Code_4_05_2 {
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
		G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(B[i]);
			G[B[i]].add(A[i]);
		}
		
		// 深さ優先探索
		visited = new boolean[N + 1];
		for (int i = 1; i <= N; ++i) {
			visited[i] = false;
		}
		dfs(1);

		// 連結かどうかの判定（answer = true のとき連結）
		boolean answer = true;
		for (int i = 1; i <= N; i++) {
			if (visited[i] == false) {
				answer = false;
			}
		}
		if (answer == true) {
			System.out.println("The graph is connected.");
		}
		else {
			System.out.println("The graph is not connected.");
		}
	}
	
	static boolean[] visited;
	static ArrayList<Integer>[] G;
	static void dfs(int pos) {
		visited[pos] = true;
		for (int i : G[pos]) {
			if (visited[i] == false) {
				dfs(i);
			}
		}
	}
}
