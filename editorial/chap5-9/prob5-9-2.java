import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] A = new long[N];
		long[] B = new long[N];
		for (int i = 1; i <= N; i++) A[i - 1] = sc.nextLong();
		for (int i = 1; i <= N; i++) B[i - 1] = sc.nextLong();
		
		// 配列 A, B をソートする
		Arrays.sort(A);
		Arrays.sort(B);
		
		// 答えを求める
		long Answer = 0;
		for (int i = 1; i <= N; i++) {
			Answer += Math.abs(A[i - 1] - B[i - 1]);
		}
		
		// 出力
		System.out.println(Answer);
	}
}