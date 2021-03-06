import java.util.*;

class Code_3_02_2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		System.out.println(GCD(A, B));
	}
	static long GCD(long A, long B) {
		// 正の整数 A と B の最大公約数を返す関数
		// GCD は Greatest Common Divisor（最大公約数）の略
		while (A >= 1 && B >= 1) {
			if (A < B) {
				B %= A; // A < B の場合、大きい方 B を書き換える
			}
			else {
				A %= B; // A >= B の場合、大きい方 A を書き換える
			}
		}
		if (A >= 1) {
			return A;
		}
		return B;
	}
}
