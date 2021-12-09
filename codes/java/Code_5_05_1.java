import java.util.*;

class Code_5_05_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		long d = sc.nextLong();
		long answer = Collections.max(Arrays.asList(a * c, a * d, b * c, b * d));
		System.out.println(answer);
	}
}
