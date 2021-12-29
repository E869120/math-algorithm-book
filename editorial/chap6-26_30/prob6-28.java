import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String C = sc.next();
		
		// 答えを求める
		int answer = 0;
		for (int i = 0; i < N; i++) {
			int code = -1;
			if (C.charAt(i) == 'B') code = 0;
			if (C.charAt(i) == 'W') code = 1;
			if (C.charAt(i) == 'R') code = 2;
			answer += code * ncr(N - 1, i);
			answer %= 3;
		}
		
		// 答えを (-1)^(N-1) で掛ける
		if (N % 2 == 0) {
			answer = (3 - answer) % 3;
		}
		
		// 答えを出力（"BWR" の answer 文字目）
		System.out.println("BWR".charAt(answer));
	}
	
	// リュカの定理で ncr mod 3 を計算
	static int ncr(int x, int y) {
		if (x < 3 && y < 3) {
			if (x < y) return 0;
			if (x == 2 && y == 1) return 2;
			return 1;
		}
		return ncr(x / 3, y / 3) * ncr(x % 3, y % 3) % 3;
	}
}