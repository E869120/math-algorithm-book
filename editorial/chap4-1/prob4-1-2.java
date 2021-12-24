import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		double[] x = new double[N + 1];
		double[] y = new double[N + 1];
		for (int i = 1; i <= N; i++) {
			x[i] = sc.nextDouble();
			y[i] = sc.nextDouble();
		}
		
		// 全探索
		double Answer = 1000000000.0;
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				double dist = Math.sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
				Answer = Math.min(Answer, dist);
			}
		}
		
		// 出力
		System.out.format("%.12f\n", Answer);
	}
}