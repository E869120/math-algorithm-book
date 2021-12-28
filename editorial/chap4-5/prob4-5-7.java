import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
		// 入力（高速な入出力のため、Scanner の代わりに BufferedReader を使っています）
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(buff.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[] A = new int[M + 1];
		int[] B = new int[M + 1];
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(buff.readLine());
			A[i] = Integer.parseInt(st.nextToken());
			B[i] = Integer.parseInt(st.nextToken());
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
		color = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			color[i] = 0;
		}
		for (int i = 1; i <= N; i++) {
			if (color[i] == 0) {
				// 頂点 i は白である（まだ探索されていない連結成分である）
				color[i] = 1;
				dfs(i);
			}
		}

		// 二部グラフかどうかの判定
		boolean answer = true;
		for (int i = 1; i <= M; i++) {
			if (color[A[i]] == color[B[i]]) {
				answer = false;
			}
		}
		if (answer == true) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
	
	static int[] color;
	static ArrayList<Integer>[] G;
	static void dfs(int pos) {
		for (int i : G[pos]) {
			if (color[i] == 0) {
				// color[pos] = 1 のとき 2、color[pos] = 2 のとき 1
				color[i] = 3 - color[pos];
				dfs(i);
			}
		}
	}
}
