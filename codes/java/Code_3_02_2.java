import java.util.*;

class Code_3_02_2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		long answer = GCD(A, B);
		System.out.println(answer);
	}
	static long GCD(long A, long B) {
		// GCD は Greatest Common Divisor（最大公約数）の略
		while (A >= 1 && B >= 1) {
			if (A < B) {
				// A < B の場合、大きい方 B を書き換える
				B %= A;
			}
			else {
				// A >= B の場合、大きい方 A を書き換える
				A %= B;
			}
		}
		if (A >= 1) {
			return A;
		}
		return B;
	}
}
