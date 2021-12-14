#include <iostream>
using namespace std;

long long N, S, A[61];

int main() {
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 全パターンを探索：(1LL << N) は 2 の N 乗
	for (long long i = 0; i < (1LL << N); i++) {
		long long sum = 0;
		for (int j = 1; j <= N; j++) {
			// (i & (1LL << (j-1))) != 0LL の場合、i の 2 進法表記の下から j 桁目が 1
			// (1LL << (j-1)) は C++ では「2 の j-1 乗」を意味します
			if ((i & (1LL << (j-1))) != 0LL) sum += A[j];
		}
		if (sum == S) { cout << "Yes" << endl; return 0; }
	}
	cout << "No" << endl;
	return 0;
}
