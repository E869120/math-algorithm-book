import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		long L = sc.nextLong();
		long R = sc.nextLong();
		int D = (int)(R - L);
		
		// 配列の初期化
		boolean[] isprime = new boolean[D + 1];
		for (int i = 0; i <= D; i++) {
			isprime[i] = true;
		}

		// L = 1 のときの場合分け（コーナーケース）
		if (L == 1) {
			isprime[0] = false;
		}
		
		// ふるい
		for (int i = 2; (long)i * i <= R; i++) {
			int start = (int)(((L + i - 1) / i * i) - L); // (L 以上で最小の i の倍数) - L
			// L 以上 R 以下の（i を除く）i の倍数すべてにバツを付ける
			for (int j = start; j <= D; j += i) {
				if (j + L == (long)i) continue;
				isprime[j] = false;
			}
		}
		
		// 個数を数えて出力
		int answer = 0;
		for (int i = 0; i <= D; i++) {
			if (isprime[i] == true) {
				answer += 1;
			}
		}
		System.out.println(answer);
	}
}