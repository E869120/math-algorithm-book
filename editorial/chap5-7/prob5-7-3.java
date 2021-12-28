import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] A = new long[N];
		for (int i = 1; i <= N; i++) {
			A[i - 1] = sc.nextLong();
		}
		
		// 配列 A 全体をソートする
		Arrays.sort(A);
		
		// 答えを求める
		long Answer = 0;
		for (int i = 1; i <= N; i++) {
			Answer += A[i - 1] * (-N + 2L * i - 1L);
		}
		
		// 出力
		System.out.println(Answer);
	}
}