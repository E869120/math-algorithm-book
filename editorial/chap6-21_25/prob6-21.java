import java.util.*;

class Main {
	public static void main(String[] args) {
		double r = 2.0; // y = e^x と y = 2 の交点を求めたいから
		double a = 1.0; // 初期値を適当に 2.0 にセットする
		for (int i = 1; i <= 5; i++) {
			// 点 (a, f(a)) の x 座標と y 座標を求める
			double zahyou_x = a;
			double zahyou_y = Math.exp(a);
			
			// 接線の式 y = sessen_a * x + sessen_b を求める
			double sessen_a = zahyou_y;
			double sessen_b = zahyou_y - sessen_a * zahyou_x;
			
			// 次の a の値 next_a を求める
			double next_a = (r - sessen_b) / sessen_a;
			System.out.format("Step #%d: a = %.15f -> %.15f\n", i, a, next_a);
			a = next_a;
		}
	}
}