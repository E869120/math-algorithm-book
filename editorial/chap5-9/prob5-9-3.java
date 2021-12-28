import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[][] A = new int[N][2];
		for (int i = 1; i <= N; i++) {
			A[i - 1][0] = sc.nextInt();
			A[i - 1][1] = sc.nextInt();
		}
		
		// 配列 A を終了時刻（A[x][1]）の昇順にソート
		Arrays.sort(A, (a1, a2) -> Integer.compare(a1[1], a2[1]));
		
		// 終了時刻が最も早いものを選び続ける
		int CurrentTime = 0;
		int Answer = 0;
		for (int i = 1; i <= N; i++) {
			if (CurrentTime <= A[i - 1][0]) {
				CurrentTime = A[i - 1][1];
				Answer += 1;
			}
		}
		
		// 出力
		System.out.println(Answer);
	}
}