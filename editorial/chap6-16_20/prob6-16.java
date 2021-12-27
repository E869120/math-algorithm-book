import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int X = sc.nextInt();
		
		// すべての (a, b, c) の組み合わせを試す
		int answer = 0;
		for (int a = 1; a <= N; a++) {
			for (int b = a + 1; b <= N; b++) {
				for (int c = b + 1; c <= N; c++) {
					if (a + b + c == X) {
						answer += 1;
					}
				}
			}
		}
		
		// 答えの出力
		System.out.println(answer);
	}
}