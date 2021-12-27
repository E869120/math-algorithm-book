import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		
		// 最小公倍数が 10^18 を超えるか判定
		if (A / GCD(A, B) > 1000000000000000000L / B) {
			System.out.println("Large");
		}
		else {
			System.out.println(A / GCD(A, B) * B);
		}
	}
	static long GCD(long A, long B) {
		if (B == 0) return A;
		return GCD(B, A % B);
	}
}