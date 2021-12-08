import java.util.*;

class Code_3_02_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		long answer = GCD(A, B);
		System.out.println(answer);
	}
	static long GCD(long A, long B) {
		// 正の整数 A と B の最大公約数を返す関数
		// GCD は Greatest Common Divisor（最大公約数）の略
		long ans = 0;
		for (long i = 1; i <= A && i <= B; i++) {
			if (A % i == 0 && B % i == 0) {
				ans = i;
			}
		}
		return ans;
	}
}
