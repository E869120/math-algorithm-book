import java.util.*;

class Code_5_09_1 {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// 支払い方のシミュレーション
		long answer = 0;
		while (N >= 10000) {
			N -= 10000; // 10000 円以上の間、10000 円札を使い続ける
			answer += 1;
		}
		while (N >= 5000) {
			N -= 5000; // 5000 円以上の間、5000 円札を使い続ける
			answer += 1;
		}
		while (N >= 1) {
			N -= 1000; // 残った金額を 1000 円札で支払う
			answer += 1;
		}
		
		// 答えの出力
		System.out.println(answer);
	}
}
