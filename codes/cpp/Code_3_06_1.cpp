#include <iostream>
#include <algorithm>
using namespace std;

int N, A[200009];

int main() {
	// ���́i���Ƃ��� N=5, A[1]=3, A[2]=1, A[3]=4, A[4]=1, A[5]=5 ����͂����Ƃ���j
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// �\�[�g�i���J��� [1, N+1) ���\�[�g����̂ŁA������ A+1, A+N+1 ���w�肵�Ă���j
	// sort �֐��ɂ��A�z��̒��g�� [3,1,4,1,5] ���� [1,1,3,4,5] �ɏ�����������
	sort(A + 1, A + N + 1);

	// �o�́i1, 1, 3, 4, 5 �̏��ɏo�͂����j
	for (int i = 1; i <= N; i++) cout << A[i] << endl;
	return 0;
}