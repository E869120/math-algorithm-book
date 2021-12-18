import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int n = sc.nextInt();
		int r = sc.nextInt();
		
		// 会場の計算
		long fact_n = 1, fact_r = 1, fact_nr = 1;
		for (int i = 1; i <= n; i++) fact_n *= i;
		for (int i = 1; i <= r; i++) fact_r *= i;
		for (int i = 1; i <= n - r; i++) fact_nr *= i;
		
		// 出力
		System.out.println(fact_n / (fact_r * fact_nr));
	}
}