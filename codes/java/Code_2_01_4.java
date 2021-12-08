import java.util.*;

class Code_2_01_4 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(); // 入力部分
		String answer = ""; // String は文字列型
		while (N >= 1) {
			// N % 2 は N を 2 で割った余り（例：N = 13 の場合 1）
			// N / 2 は N を 2 で割った余り（例：N = 13 の場合 6）
			if (N % 2 == 0) {
				answer = "0" + answer;
			}
			if (N % 2 == 1) {
				answer = "1" + answer;
			}
			N = N / 2;
		}
		System.out.println(answer);
	}
};
