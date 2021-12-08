import java.util.*;

class Code_3_08_1 {
	public static void main(String[] args) {
		// 入力（注意：ここでは配列は A[0] から A[N-1] までの順に入力しています。添え字を 0 から始めることを 0-indexed などといいます。）
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long X = sc.nextLong();
		long[] A = new long[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextLong();
		}
		
		// 配列のソート
		Arrays.sort(A);
		
		// 二分探索・出力
		String answer = "No";
		int left = 0, right = N - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (A[mid] == X) {
				answer = "Yes";
				break;
			}
			if (A[mid] > X) {
				right = mid - 1;
			}
			if (A[mid] < X) {
				left = mid + 1;
			}
			System.out.println(left + " " + right);
		}
		System.out.println(answer);
	}
}
