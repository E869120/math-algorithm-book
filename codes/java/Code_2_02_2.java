import java.util.*;

class Code_2_02_2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt(); // a を入力する
		int b = sc.nextInt(); // b を入力する
		System.out.println(a & b); // a AND b の値を出力する
		System.out.println(a | b); // a OR b の値を出力する
		System.out.println(a ^ b); // a XOR b の値を出力する
	}
};
