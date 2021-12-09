import java.util.*;

class Code_5_10_3 {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long X = sc.nextLong();
		long Y = sc.nextLong();
		
		// 4 つの整数 (a, b, c, d) の全探索
		boolean flag = false;
		for (int a = 1; a <= N; a++) {
			for (int b = a; b <= N; b++) {
				for (int c = b; c <= N; c++) {
					for (int d = c; d <= N; d++) {
						if (a + b + c + d == X && (long)a * b * c * d == Y) {
							flag = true; // 答えが見つかったら flag を true にする
						}
					}
				}
			}
		}
		
		// 答えの出力
		if (flag == true) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}
