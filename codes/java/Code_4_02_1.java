import java.util.*;
import java.io.*;

class Code_4_02_1 {
	public static void main(String[] args) throws IOException {
		// 入力（高速な入出力のため、Scanner の代わりに BufferedReader を使っています）
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(buff.readLine());
		int N = Integer.parseInt(st.nextToken());
		int Q = Integer.parseInt(st.nextToken());
		int[] A = new int[N + 1];
		int[] L = new int[Q + 1];
		int[] R = new int[Q + 1];
		st = new StringTokenizer(buff.readLine());
		for (int i = 1; i <= N; i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}
		for (int j = 1; j <= Q; j++) {
			st = new StringTokenizer(buff.readLine());
			L[j] = Integer.parseInt(st.nextToken());
			R[j] = Integer.parseInt(st.nextToken());
		}
		
		// 累積和を求める
		int[] B = new int[N + 1];
		B[0] = 0;
		for (int i = 1; i <= N; i++) {
			B[i] = B[i - 1] + A[i];
		}
		
		// 答えを計算して出力
		for (int j = 1; j <= Q; j++) {
			System.out.println(B[R[j]] - B[L[j] - 1]);
		}
	}
}
