#include <iostream>
#include <algorithm>
using namespace std;

int N, L[2009], R[2009];
int Current_Time = 0, Answer = 0; // Current_Time �͌��ݎ����i���O�Ɍ����f��̏I�������j

int main() {
	// ����
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];

	// �f��̑I�ѕ��̃V�~�����[�V����
	// �����f��̏I�������̍ŏ��l min_endtime �͍ŏ� 1000000 �̂悤�Ȃ��蓾�Ȃ��l�ɐݒ肷��
	while (true) {
		int min_endtime = 1000000;
		for (int i = 1; i <= N; i++) {
			if (L[i] < Current_Time) continue;
			min_endtime = min(min_endtime, R[i]);
		}
		if (min_endtime == 1000000) break;
		Current_Time = min_endtime;
		Answer += 1;
	}

	// �����̏o��
	cout << Answer << endl;
	return 0;
}