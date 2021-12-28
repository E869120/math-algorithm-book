import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// N = 2^k-1 の形で表されるかどうか調べる
		boolean flag = false;
		for (int i = 1; i <= 60; i++) {
			if (N == (1L << i) - 1) {
				flag = true;
			}
		}
		
		// 出力
		if (flag == true) System.out.println("Second");
		else System.out.println("First");
	}
}