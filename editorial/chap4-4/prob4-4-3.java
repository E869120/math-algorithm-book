import java.util.*;
 
class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 入力 → 配列の初期化
		int N = sc.nextInt();
		long[] F = new long[N + 1];
		for (int i = 1; i <= N; i++) F[i] = 0;
		
		// F[1], F[2], ..., F[N] を計算する
		for (int i = 1; i <= N; i++) {
			// F[i], F[2i], F[3i], ... に 1 を加算する
			for (int j = i; j <= N; j += i) F[j] += 1;
		}
		
		// 答えを求める
		long Answer = 0;
		for (int i = 1; i <= N; i++) {
			Answer += F[i] * i;
		}
		System.out.println(Answer);
	}
}