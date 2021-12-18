import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		// 答えの計算
		double Answer = 0.0;
		for (int i = N; i >= 1; i--) {
			Answer += 1.0 * N / i;
		}
		
		// 出力
		System.out.format("%.12f\n", Answer);
	}
}