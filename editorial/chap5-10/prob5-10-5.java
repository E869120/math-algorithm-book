import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		
		// c = 1 のときの場合分け
		if (c == 1) {
			System.out.println("No\n");
			System.exit(0);
		}
		
		// 右辺の計算（c の b 乗）
		long v = 1;
		for (long i = 1; i <= b; i++) {
			if (a / c < v) {
				// この条件分岐は a < (v * c) を言い換えただけ
				// 条件の言い換えをした理由は、v, c が 10^18 程度になる可能性があるため
				// a < v * c にすると最悪の場合 v * c = 10^36 になりオーバーフローするから
				System.out.println("Yes\n");
				System.exit(0);
			}
			v *= c;
		}
		
		// ループが打ち切られない場合
		System.out.println("No\n");
	}
}