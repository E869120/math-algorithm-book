import java.util.*;

class Code_2_01_3 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		int answer = 0;
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
			answer += A[i];
		}
		System.out.println(answer);
	}
};
