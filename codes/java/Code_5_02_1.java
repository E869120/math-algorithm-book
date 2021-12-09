import java.util.*;

class Code_5_02_1 {
	public static void main(String[] args) {
		// 注意：以下のプログラムは N >= 1 で正しく動作します。N = 0 では答えは「1」となるので、また別の場合分けをする必要があります。
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		if (N % 4 == 1) {
			System.out.println(2);
		}
		if (N % 4 == 2) {
			System.out.println(4);
		}
		if (N % 4 == 3) {
			System.out.println(8);
		}
		if (N % 4 == 0) {
			System.out.println(6);
		}
	}
}
