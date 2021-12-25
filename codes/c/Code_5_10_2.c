#include <stdio.h>

int main() {
	long long a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	if (c - a - b < 0LL) {
		printf("No\n");
	}
	else if (4LL * a * b < (c - a - b) * (c - a - b)) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}
