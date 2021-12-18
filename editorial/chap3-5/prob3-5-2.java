import java.util.*;

class Main {
	public static void main(String[] args) {
		Random rd = new Random();
		int N = 1000000; // N は試行回数（適宜変更する）
		int M = 0;
		for (int i = 1; i <= N; i++) {
			double px = 6.0 * rd.nextDouble();
			double py = 9.0 * rd.nextDouble();
			
			// 点 (3, 3) との距離。この値が 3 以下であれば半径 3 の円に含まれる
			double dist_33 = Math.sqrt((px - 3.0) * (px - 3.0) + (py - 3.0) * (py - 3.0));
			
			// 点 (3, 7) との距離。この値が 2 以下であれば半径 2 の円に含まれる
			double dist_37 = Math.sqrt((px - 3.0) * (px - 3.0) + (py - 7.0) * (py - 7.0));
			
			if (dist_33 <= 3.0 || dist_37 <= 2.0) M += 1;
		}
		System.out.println(M);
	}
}