import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		double[] A = new double[N + 1];
		double[] B = new double[N + 1];
		double[] C = new double[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextDouble();
			B[i] = sc.nextDouble();
			C[i] = sc.nextDouble();
		}
		
		// 交点を全探索
		double Answer = 0.0;
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				// 交点をもたない場合
				if (A[i] * B[j] == A[j] * B[i]) continue;
				
				// i 番目の直線（条件式の境界）と j 番目の直線（条件式の境界）の交点を求める
				double px = (C[i] * B[j] - C[j] * B[i]) / (A[i] * B[j] - A[j] * B[i]);
				double py = (C[i] * A[j] - C[j] * A[i]) / (B[i] * A[j] - B[j] * A[i]);
				
				// 座標 (px, py) が N 個の条件すべてを満たすか調べる
				// C++ のコードにおける check 関数に相当
				boolean ret = true;
				for (int k = 1; k <= N; k++) {
					if (A[k] * px + B[k] * py > C[k]) ret = false;
				}
				if (ret == true) {
					Answer = Math.max(Answer, px + py);
				}
			}
		}
		
		// 出力
		System.out.format("%.12f\n", Answer);
	}
}