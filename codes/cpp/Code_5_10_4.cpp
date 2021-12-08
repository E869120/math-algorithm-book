#include <iostream>
#include <string>
using namespace std;

int N, depth = 0;
string S;

int main() {
	// “ü—Í
	cin >> N >> S;

	// '(' ‚Ì” - ')' ‚Ì”‚ğ depth ‚Æ‚·‚é
	// “r’†‚Å depth ‚ª•‰‚É‚È‚Á‚½‚ç‚±‚Ì“_‚Å No
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') depth += 1;
		if (S[i] == ')') depth -= 1;
		if (depth < 0) {
			cout << "No" << endl;
			return 0;
		}
	}

	// ÅŒãAdepth = 0 ['(' ‚Æ ')' ‚Ì”‚ª“¯‚¶] ‚©‚Ç‚¤‚©‚Åê‡•ª‚¯
	if (depth == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}