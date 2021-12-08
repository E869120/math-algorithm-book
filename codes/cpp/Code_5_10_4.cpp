#include <iostream>
#include <string>
using namespace std;

int N, depth = 0;
string S;

int main() {
	// ����
	cin >> N >> S;

	// '(' �̐� - ')' �̐��� depth �Ƃ���
	// �r���� depth �����ɂȂ����炱�̎��_�� No
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') depth += 1;
		if (S[i] == ')') depth -= 1;
		if (depth < 0) {
			cout << "No" << endl;
			return 0;
		}
	}

	// �Ō�Adepth = 0 ['(' �� ')' �̐�������] ���ǂ����ŏꍇ����
	if (depth == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}