import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		int K = sc.nextInt();
		long[] V = new long[K + 1];
		for (int i = 1; i <= K; i++) {
			V[i] = sc.nextLong();
		}
		
		// ビット全探索
		long Answer = 0;
		for (int i = 1; i < (1 << K); i++) {
			int cnt = 0; // 選んだ数の個数
			long lcm = 1; // 最小公倍数
			for (int j = 0; j < K; j++) {
				if ((i & (1 << j)) != 0) {
					cnt += 1;
					lcm = LCM(lcm, V[j + 1]);
				}
			}
			long num = N / lcm; // 選ばれた数すべての倍数であるものの個数
			if (cnt % 2 == 1) Answer += num;
			if (cnt % 2 == 0) Answer -= num;
		}
		
		// 出力
		System.out.println(Answer);
	}
	static long GCD(long A, long B) {
		// 最大公約数を返す関数
		if (B == 0) return A;
		return GCD(B, A % B);
	}
	static long LCM(long A, long B) {
		// 最小公倍数を返す関数
		return (A / GCD(A, B)) * B;
	}
}