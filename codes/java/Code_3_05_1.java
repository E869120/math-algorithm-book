import java.util.*;

class Code_3_05_1 {
	public static void main(String[] args) {
		Random rd = new Random();
		int N = 10000; // N は試行回数（適宜変更する）
		int M = 0;
		for (int i = 1; i <= N; i++) {
			double px = rd.nextDouble(); // 0 以上 1 未満の乱数を生成（C++ のコード 3.5.1 では 0 以上 1 以下の乱数を生成しているが、ほとんど同じ）
			double py = rd.nextDouble(); // 0 以上 1 未満の乱数を生成（C++ のコード 3.5.1 では 0 以上 1 以下の乱数を生成しているが、ほとんど同じ）
			// 原点からの距離は sqrt(px * px + py * py)
			// これが 1 以下であれば良いので、条件は「px * px + py * py <= 1」
			if (px * px + py * py <= 1.0) {
				M++;
			}
		}
		System.out.format("%.12f\n", 4.0 * M / N);
	}
}
