import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		int[] B = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
		}
		
		// 答えの計算・出力
		double Answer = 0.0;
		for (int i = 1; i <= N; i++) {
			Answer += (1.0 / 3.0) * A[i] + (2.0 / 3.0) * B[i];
		}
		System.out.format("%.12f\n", Answer);
	}
}