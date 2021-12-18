import java.util.*;

class Main {
	public static void MergeSort(int[] A, int[] C, int l, int r) {
		// r-l=1 の場合、既にソートされているので何もしない
		if (r - l == 1) return;
		
		// 2 つに分割した後、小さい配列をソート
		int m = (l + r) / 2;
		MergeSort(A, C, l, m);
		MergeSort(A, C, m, r);
		
		// この時点で以下の 2 つの配列がソートされている
		// 列 A' に相当するもの [A[l], A[l+1], ..., A[m−1]]
		// 列 B' に相当するもの [A[m], A[m+1], ..., A[r−1]]
		// 以下が Merge 操作となります。
		int c1 = l, c2 = m, cnt = 0;
		while (c1 != m || c2 != r) {
			if (c1 == m) {
				// 列 A' が空の場合
				C[cnt] = A[c2]; c2++;
			}
			else if (c2 == r) {
				// 列 B' が空の場合
				C[cnt] = A[c1]; c1++;
			}
			else {
				// そのいずれでもない場合
				if (A[c1] <= A[c2]) {
					C[cnt] = A[c1]; c1++;
				}
				else {
					C[cnt] = A[c2]; c2++;
				}
			}
			cnt++;
		}
		
		// 列 A', 列 B' を合併した配列 C を A に移す
		// [C[0], C[1], ..., C[cnt-1]] -> [A[l], A[l+1], ..., A[r-1]]
		for (int i = 0; i < cnt; i++) A[l + i] = C[i];
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		int[] C = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();
		
		// マージソート
		MergeSort(A, C, 1, N + 1);
		
		// 出力
		for (int i = 1; i <= N; i++) {
			System.out.println(A[i]);
		}
	}
}