#include <iostream>
#include <algorithm>
using namespace std;
 
long long N, A[200009];
long long Answer = 0;
 
int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// ソート（コード 5.7.1 から追加した唯一の部分）
	sort(A + 1, A + N + 1);
	
	// 答えを求める → 答えの出力
	for (int i = 1; i <= N; i++) Answer += A[i] * (-N + 2LL * i - 1LL);
	cout << Answer << endl;
	return 0;
}