import java.util.*;

class Code_2_04_2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (i % X == 0 || i % Y == 0) {
				cnt++;
			}
		}
		System.out.println(cnt);
	}
}
