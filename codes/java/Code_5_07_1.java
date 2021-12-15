import java.util.*;

class Code_5_07_1 {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		// 答えを求める
		long answer = 0;
		for (int i = 1; i <= N; i++) {
			answer += (long)A[i] * (-N + 2 * i - 1);
		}
		
		// 答えの出力
		System.out.println(answer);
	}
}
