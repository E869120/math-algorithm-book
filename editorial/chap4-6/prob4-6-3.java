import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// 答えの計算
		final long MOD = 1000000007;
		long V = modpow(4, N + 1, MOD) - 1;
		long Answer = division(V, 3, MOD);
		
		// 出力
		System.out.println(Answer);
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
	static long division(long a, long b, long m) {
		// division(a, b, m) は a÷b mod m を返す関数
		return (a * modpow(b, m - 2, m)) % m;
	}
}