import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] X = new long[N];
		long[] Y = new long[N];
		for (int i = 1; i <= N; i++) {
			X[i - 1] = sc.nextLong();
			Y[i - 1] = sc.nextLong();
		}
		
		// 配列 X, Y をソートする
		Arrays.sort(X);
		Arrays.sort(Y);
		
		// パーツ 1 の答え（x 座標の差の絶対値の総和）
		long Part1 = 0;
		for (int i = 1; i <= N; i++) Part1 += X[i - 1] * (-N + 2L * i - 1L);
		
		// パーツ 2 の答え（y 座標の差の絶対値の総和）
		long Part2 = 0;
		for (int i = 1; i <= N; i++) Part2 += Y[i - 1] * (-N + 2L * i - 1L);
		
		// 出力
		System.out.println(Part1 + Part2);
	}
}