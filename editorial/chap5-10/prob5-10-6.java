import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long B = sc.nextLong();
		
		// 各桁の積の候補を列挙
		func(0, 0);
		
		// m - f(m) == B になるかどうかチェック
		long Answer = 0;
		for (long fm : fm_cand) {
			long m = fm + B;
			long prod_m = product(m);
			if (m - prod_m == B && m <= N) {
				Answer += 1;
			}
		}
		
		// 出力
		System.out.println(Answer);
	}
	
	static Set<Long> fm_cand = new TreeSet<Long>();
	
	static void func(int digit, long m) {
		// 桁数は 11 桁のときに打ち切って良い
		// 注：余った桁を 1 で埋めれば、全部 11 桁と仮定しても良い
		if (digit == 11) {
			fm_cand.add(product(m));
			return;
		}
		
		// 次の桁を探索
		// min_value は cur の最後の桁（単調増加にするためには次の桁がそれ以上でなければならない）
		int min_value = (int)(m % 10);
		for (int i = min_value; i <= 9; i++) {
			func(digit + 1, 10L * m + 1L * i);
		}
	}
	
	// m の各桁の積を返す関数
	static long product(long m) {
		// m = 0 
		if (m == 0) {
			return 0;
		}
		else {
			long ans = 1;
			while (m >= 1) {
				ans *= (m % 10);
				m /= 10;
			}
			return ans;
		}
	}
}