#include <stdio.h>
#include <math.h>

int main() {
	int N = 1000;
	double Answer = 0.0;

	for (int i = 0; i < N; i++) {
		double x = 1.0 * (2 * i + 1) / (2 * N);
		double value = pow(2.0, x * x); // f((2i+1)/2N) の値
		Answer += value;
	}
	printf("%.14lf\n", Answer / N);
	return 0;
}