import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int X = sc.nextInt();
		int Y = sc.nextInt();
		
		// 場合分け（a, b が負になってしまう場合）
		if ((2 * Y - X) < 0 || (2 * X - Y) < 0) {
			System.out.println("0");
		}
		
		// 場合分け（a, b が整数にならない場合）
		else if ((2 * Y - X) % 3 != 0 || (2 * X - Y) % 3 != 0) {
			System.out.println("0");
		}
		
		// 答えがゼロではない場合
		else {
			long MOD = 1000000007;
			long bunshi = 1, bunbo = 1;
			long a = (2 * Y - X) / 3;
			long b = (2 * X - Y) / 3;
			
			// 二項係数の分子と分母を求める（手順 1.／手順 2.）
			for (int i = 1; i <= a + b; i++) {
				bunshi = (bunshi * i) % MOD;
			}
			for (int i = 1; i <= a; i++) {
				bunbo = (bunbo * i) % MOD;
			}
			for (int i = 1; i <= b; i++) {
				bunbo = (bunbo * i) % MOD;
			}
			
			// 答えを求める（手順 3.）
			long answer = division(bunshi, bunbo, MOD);
			System.out.println(answer);
		}
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