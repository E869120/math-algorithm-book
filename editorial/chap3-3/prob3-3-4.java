import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();
		
		// 答えを求める
		long a = 0, b = 0, c = 0, d = 0;
		for (int i = 1; i <= N; i++) {
			if (A[i] == 100) a += 1;
			if (A[i] == 200) b += 1;
			if (A[i] == 300) c += 1;
			if (A[i] == 400) d += 1;
		}
		
		// 出力
		System.out.println(a * d + b * c);
	}
}