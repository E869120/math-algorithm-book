import java.util.*;

class Code_3_06_1 {
	public static void main(String[] args) {
		// 入力（たとえば N = 5, A = [3, 1, 4, 1, 5] を入力したとする）
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		for (int i = 1; i <= N; i++) {
			A[i - 1] = sc.nextInt();
		}
		
		// 配列 A 全体をソートする
		Arrays.sort(A);
		
		// 出力（1, 1, 3, 4, 5 の順に出力される）
		for (int i = 1; i <= N; i++) {
			System.out.println(A[i - 1]);
		}
	}
}
