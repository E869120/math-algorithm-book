import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long Answer = 0;
		
		// 10000 円札を支払う
		Answer += (N / 10000); N %= 10000;
		
		// 5000 円札を支払う
		Answer += (N / 5000); N %= 5000;
		
		// 1000 円札を支払う
		Answer += (N / 1000); N %= 1000;
		
		// 出力
		System.out.println(Answer);
	}
}