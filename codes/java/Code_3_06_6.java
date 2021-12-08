import java.util.*;

class Code_3_06_6 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int answer = func(N);
		System.out.println(answer);
	}
	static int func(int N) {
		// func(N) → func(N-1) → ... → func(0) → func(-1) → func(-2) → ... と無限に呼び出されるので、プログラムが正常に動作しない
		return func(N - 1) * N;
	}
}
