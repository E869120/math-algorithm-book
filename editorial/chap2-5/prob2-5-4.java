import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int N = sc.nextInt();
		
		// 出力
		for (int i = 2; i <= N; i++) {
			if (isPrime(i) == true) {
				if (i >= 3) System.out.print(" ");
				System.out.print(i);
			}
		}
		System.out.println();
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