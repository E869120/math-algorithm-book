import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();
		
		// 答えを求める
		long[] cnt = new long[100009];
		for (int i = 1; i <= 99999; i++) cnt[i] = 0;
		for (int i = 1; i <= N; i++) cnt[A[i]] += 1;
		
		long Answer = 0;
		for (int i = 1; i <= 49999; i++) Answer += cnt[i] * cnt[100000 - i];
		Answer += cnt[50000] * (cnt[50000] - 1) / 2;
		
		// 出力
		System.out.println(Answer);
	}
}