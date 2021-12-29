// このソースコードは、深さ優先探索 (DFS) をスタックを用いて実装したものです。
// スタックは「一番上に要素を積む」「一番上の要素を調べる」「一番上に積まれた要素を取り除く」という 3 種類の操作ができるデータ構造です。
// 深さ優先探索の部分は、コード 4.5.3 の queue を stack に変更したものをベースに書かれています。

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
		ArrayList<Integer>[] G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(B[i]);
			G[B[i]].add(A[i]);
		}
		
		// 深さ優先探索の初期化
		boolean[] visited = new boolean[N + 1];
		for (int i = 1; i <= N; i++) {
			visited[i] = false;
		}
		Stack<Integer> S = new Stack<>(); // スタック S を定義する
		visited[1] = true;
		S.push(1); // S に 1 を追加

		// 深さ優先探索
		while (S.size() >= 1) {
			int pos = S.pop(); // S の先頭を調べ、これを取り出す
			for (int nex : G[pos]) {
				if (visited[nex] == false) {
					visited[nex] = true;
					S.push(nex); // S に nex を追加
				}
			}
		}
		
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
}