import java.util.*;

class Code_5_10_4 {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String S = sc.next();
		
		// '(' の数 - ')' の数を depth とする
		// 途中で depth が負になったら、この時点で No
		int depth = 0;
		boolean flag = true;
		for (int i = 0; i < N; i++) {
			if (S.charAt(i) == '(') {
				depth += 1;
			}
			if (S.charAt(i) == ')') {
				depth -= 1;
			}
			if (depth < 0) {
				flag = false;
			}
		}
		
		// 最後、depth = 0 ['(' と ')' の数が同じ] であるかも追加で判定する
		if (flag == true && depth == 0) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}
