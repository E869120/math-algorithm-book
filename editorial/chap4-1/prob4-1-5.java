import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		long X1 = sc.nextLong(); long Y1 = sc.nextLong();
		long X2 = sc.nextLong(); long Y2 = sc.nextLong();
		long X3 = sc.nextLong(); long Y3 = sc.nextLong();
		long X4 = sc.nextLong(); long Y4 = sc.nextLong();
		
		// cross の値を計算
		long ans1 = cross(X2-X1, Y2-Y1, X3-X1, Y3-Y1);
		long ans2 = cross(X2-X1, Y2-Y1, X4-X1, Y4-Y1);
		long ans3 = cross(X4-X3, Y4-Y3, X1-X3, Y1-Y3);
		long ans4 = cross(X4-X3, Y4-Y3, X2-X3, Y2-Y3);
		
		// すべて一直線上に並んでいる場合（コーナーケース）
		// pair 型が使えないので、C++ とは実装方法がやや異なります
		if (ans1 == 0 && ans2 == 0 && ans3 == 0 && ans4 == 0) {
			if (X1 == X2 && X2 == X3 && X3 == X4) {
				long a = Y1, b = Y2;
				if (a > b) { // swap(a, b)
					long tmp = b;
					b = a;
					a = tmp;
				}
				long c = Y3, d = Y4;
				if (c > d) { // swap(c, d)
					long tmp = d;
					d = c;
					c = tmp;
				}
				if (Math.max(a, c) <= Math.min(b, d)) {
					System.out.println("Yes");
				}
				else {
					System.out.println("No");
				}
			}
			else {
				long a = X1, b = X2;
				if (a > b) { // swap(a, b)
					long tmp = b;
					b = a;
					a = tmp;
				}
				long c = X3, d = X4;
				if (c > d) { // swap(c, d)
					long tmp = d;
					d = c;
					c = tmp;
				}
				if (Math.max(a, c) <= Math.min(b, d)) {
					System.out.println("Yes");
				}
				else {
					System.out.println("No");
				}
			}
		}
		
		// そうでない普通の場合
		else {
			// IsAB: 線分 AB が点 C, D を分けるか？
			// IsCD: 線分 CD が点 A, B を分けるか？
			boolean IsAB = false, IsCD = false;
			if (ans1 >= 0 && ans2 <= 0) IsAB = true;
			if (ans1 <= 0 && ans2 >= 0) IsAB = true;
			if (ans3 >= 0 && ans4 <= 0) IsCD = true;
			if (ans3 <= 0 && ans4 >= 0) IsCD = true;
			
			// 答えの出力
			if (IsAB == true && IsCD == true) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
		}
	}
	static long cross(long ax, long ay, long bx, long by) {
		return ax * by - ay * bx;
	}
};