import java.util.*;

class Code_3_01_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		boolean answer = isPrime(N);
		if (answer == true) {
			System.out.println("prime");
		}
		else {
			System.out.println("not prime");
		}
	}
	static boolean isPrime(long N) {
		// 2 以上の整数 N に対し、N が素数であれば true、素数でなければ false を返す関数
		for (long i = 2; i <= N - 1; i++) {
			if (N % i == 0) {
				return false;
			}
		}
		return true;
	}
}
