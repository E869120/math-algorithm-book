import java.util.*;

class Code_4_06_2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] a = new int[N + 1];
		a[1] = 1; a[2] = 1;
		for (int i = 3; i <= N; i++) {
			a[i] = (a[i - 1] + a[i - 2]) % 1000000007;
		}
		System.out.println(a[N] % 1000000007);
	}
}
