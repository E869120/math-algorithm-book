import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		long N = sc.nextInt();

		// 答えの計算
		long Answer = 1;
		for (int i = 1; i <= N; i++) Answer *= i;

		// 出力
		System.out.println(Answer);
	}
};