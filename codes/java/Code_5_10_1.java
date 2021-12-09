import java.util.*;

class Code_5_10_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		if (Math.sqrt(a) + Math.sqrt(b) < Math.sqrt(c)) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}
