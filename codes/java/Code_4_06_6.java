import java.util.*;

class Code_4_06_6 {
	public static void main(String[] args) {
		// 配列 fact の初期化（fact[i] は i の階乗を 1000000007 で割った余り）
		fact = new long[LIMIT + 1];
		fact[0] = 1;
		for (int i = 1; i <= LIMIT; i++) {
			fact[i] = fact[i - 1] * i % MOD;
		}
		
		// 入力 → 答えの出力
		Scanner sc = new Scanner(System.in);
		int X = sc.nextInt();
		int Y = sc.nextInt();
		System.out.println(ncr(X + Y, Y));
	}
	static final long MOD = 1000000007;
	static final int LIMIT = 200000;
	static long[] fact;
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
	static long division(long a, long b, long m) {
		// division(a, b, m) は a÷b mod m を返す関数
		return (a * modpow(b, m - 2, m)) % m;
	}
	static long ncr(int n, int r) {
		// ncr は n! を r! × (n-r)! で割った値
		return division(fact[n], fact[r] * fact[n - r] % MOD, MOD);
	}
}
