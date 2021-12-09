import java.util.*;

class Code_4_03_1 {
	public static void main(String[] args) {
		double r = 2.0; // √2 を求めたいから
		double a = 2.0; // 初期値を適当に 2.0 にセットする
		for (int i = 1; i <= 5; i++) {
			// 点 (a, f(a)) の x 座標と y 座標を求める
			double zahyou_x = a;
			double zahyou_y = a * a;
			
			// 接線の式を y = sessen_A * x + sessen_b を求める
			double sessen_A = 2.0 * zahyou_x;
			double sessen_b = zahyou_y - sessen_A * zahyou_x;
			
			// 次の a の値を求める
			double next_A = (r - sessen_b) / sessen_A;
			System.out.format("Step #%d: a = %.12f -> %.12f\n", i, a, next_A);
			a = next_A;
		}
	}
}
