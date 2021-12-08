#include <iostream>
#include <algorithm>
using namespace std;

int N, A[200009];

int main() {
	// 入力（たとえば N=5, A[1]=3, A[2]=1, A[3]=4, A[4]=1, A[5]=5 を入力したとする）
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// ソート（半開区間 [1, N+1) をソートするので、引数に A+1, A+N+1 を指定している）
	// sort 関数により、配列の中身が [3,1,4,1,5] から [1,1,3,4,5] に書き換えられる
	sort(A + 1, A + N + 1);

	// 出力（1, 1, 3, 4, 5 の順に出力される）
	for (int i = 1; i <= N; i++) cout << A[i] << endl;
	return 0;
}