import java.util.*;

class Code_4_06_4 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		final long MOD = 1000000007;
		long a = sc.nextLong();
		long b = sc.nextLong();
		long answer = modpow(a, b, MOD);
		System.out.println(answer);
	}
	static long modpow(long a, long b, long m) {
		// 繰り返し二乗法（p は a^1, a^2, a^4, a^8, ... といった値をとる）
		long p = a, answer = 1;
		for (int i = 0; i < 30; i++) {
			if ((b & (1 << i)) != 0) {
				answer = (answer * p) % m;
			}
			p = (p * p) % m;
		}
		return answer;
	}
}
