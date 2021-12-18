import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}

		// 答えの計算
		int Answer = 0;
		for (int i = 1; i <= N; i++) {
			Answer += A[i];
		}

		// 出力
		System.out.println(Answer % 100);
	}
};
