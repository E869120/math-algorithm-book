import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] B = new int[N];
		for (int i = 1; i <= N - 1; i++) {
			B[i] = sc.nextInt();
		}
	
		// 数列 A の要素の合計を求める
		int answer = B[1] + B[N - 1];
		for (int i = 2; i <= N - 1; i++) {
			answer += Math.min(B[i - 1], B[i]);
		}
		
		// 答えの出力
		System.out.println(answer);
	}
}