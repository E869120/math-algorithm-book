import java.util.*;

class Code_4_02_2 {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Q = sc.nextInt();
		int[] L = new int[Q + 1];
		int[] R = new int[Q + 1];
		int[] X = new int[Q + 1];
		for (int i = 1; i <= Q; i++) {
			L[i] = sc.nextInt();
			R[i] = sc.nextInt();
			X[i] = sc.nextInt();
		}
		
		// 階差の計算
		int[] B = new int[N + 2];
		for (int i = 1; i <= N + 1; i++) {
			B[i] = 0;
		}
		for (int i = 1; i <= Q; i++) {
			B[L[i]] += X[i];
			B[R[i] + 1] -= X[i];
		}
		
		// 答えを計算して出力
		String answer = "";
		for (int i = 2; i <= N; i++) {
			if (B[i] > 0) answer += "<";
			if (B[i] == 0) answer += "=";
			if (B[i] < 0) answer += ">";
		}
		System.out.println(answer);
	}
}
