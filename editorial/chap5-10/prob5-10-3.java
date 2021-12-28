import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		long C = sc.nextLong();
		
		// 計算
		long mod = 998244353;
		long D = A * (A + 1) / 2; D %= mod;
		long E = B * (B + 1) / 2; E %= mod;
		long F = C * (C + 1) / 2; F %= mod;
		
		// 答えを出力
		// ここで (D * E * F) % mod にしても、途中で 10^27 を扱う可能性がある
		// そのため、long long 型でもオーバーフローすることに注意！
		System.out.println((D * E % mod) * F % mod);
	}
}