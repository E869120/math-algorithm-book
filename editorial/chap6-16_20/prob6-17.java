import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// 縦の長さを 1 から √N まで全探索
		long answer = (1L << 60);
		for (long x = 1; x * x <= N; x++) {
			if (N % x == 0) {
				answer = Math.min(answer, 2 * x + 2 * (N / x));
			}
		}
		
		// 答えの出力
		System.out.println(answer);
	}
}