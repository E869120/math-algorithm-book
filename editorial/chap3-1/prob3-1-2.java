import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		long N = sc.nextLong();
		
		// 素因数分解・出力（空白区切りの場合）
		boolean flag = false;
		for (long i = 2; i * i <= N; i++) {
			while (N % i == 0) {
				if (flag == true) System.out.print(" ");
				flag = true;
				N /= i;
				System.out.print(i);
			}
		}
		
		// 最後に残った N
		if (N >= 2) {
			if (flag == true) System.out.print(" ");
			flag = true;
			System.out.print(N);
		}
		System.out.println();
	}
}