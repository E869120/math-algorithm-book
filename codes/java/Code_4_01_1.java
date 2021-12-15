import java.util.*;

class Code_4_01_1 {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		long ax = sc.nextInt(), ay = sc.nextInt();
		long bx = sc.nextInt(), by = sc.nextInt();
		long cx = sc.nextInt(), cy = sc.nextInt();
		
		// ベクトル BA, BC, CA, CB の成分表示を求める
		long BAx = ax - bx, BAy = ay - by;
		long BCx = cx - bx, BCy = cy - by;
		long CAx = ax - cx, CAy = ay - cy;
		long CBx = bx - cx, CBy = by - cy;
		
		// どのパターンに当てはまるか判定する
		int pattern = 2;
		if (BAx * BCx + BAy * BCy < 0L) {
			pattern = 1;
		}
		if (CAx * CBx + CAy * CBy < 0L) {
			pattern = 3;
		}
		
		// 点と直線の距離を求める
		double answer = 0.0;
		if (pattern == 1) {
			answer = Math.sqrt(BAx * BAx + BAy * BAy);
		}
		if (pattern == 3) {
			answer = Math.sqrt(CAx * CAx + CAy * CAy);
		}
		if (pattern == 2) {
			double S = Math.abs(BAx * CAy - BAy * CAx);
			double BCLength = Math.sqrt(BCx * BCx + BCy * BCy);
			answer = S / BCLength;
		}
		
		// 答えの出力
		System.out.format("%.12f\n", answer);
	}
}
