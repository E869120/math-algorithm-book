import java.util.*;

class Code_5_10_2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		if (c - a - b < 0) {
			System.out.println("No");
		}
		else if (4 * a * b < (c - a - b) * (c - a - b)) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}
