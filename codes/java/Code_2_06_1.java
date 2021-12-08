import java.util.*;

class Code_2_06_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int S = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		String answer = "No";
		for (long i = 0; i < (1L << N); i++) {
			int sum = 0;
			for (int j = 0; j < N; j++) {
				if ((i & (1L << j)) != 0L) {
					sum += A[j + 1];
				}
			}
			if (sum == S) {
				answer = "Yes";
				break;
			}
		}
		System.out.println(answer);
	}
}
