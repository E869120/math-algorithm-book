#include <math.h>
#include <stdio.h>

int main() {
	long long a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	if (sqrt(a) + sqrt(b) < sqrt(c)) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}
