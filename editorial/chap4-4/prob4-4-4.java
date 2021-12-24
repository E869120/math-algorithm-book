import java.util.*;
 
class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cnt = 0;
		double LIMIT = 23; // これを 30 にすると答えが求められる
		double Current = 0;
		
		// 1 つずつ足していく
		while (Current < LIMIT) {
			cnt += 1;
			Current += 1.0 / cnt;
		}
		
		// 出力
		System.out.println(cnt);
	}
}
