import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		long H = sc.nextLong();
		long W = sc.nextLong();
		
		// 場合分け
		if (H == 1 || W == 1) {
			System.out.println(1);
		}
		else {
			System.out.println((H * W + 1) / 2);
		}
	}
}