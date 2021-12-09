import java.util.*;

class Code_5_06_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int answer = 0;
		for (int i = 1; i <= B; i++) {
			if (shouMondai(A, B, i) == true) {
				answer = i;
			}
		}
		System.out.println(answer);
	}
	static boolean shouMondai(int A, int B, int t) {
		// 小問題 t を解く関数
		int cl = (A + t - 1) / t; // A÷t の小数点以下切り上げ
		int cr = B / t; // B÷t の小数点以下切り捨て
		return (cr - cl >= 1); // cr - cl >= 1 ならば true、そうでなければ false を返す
	}
}
