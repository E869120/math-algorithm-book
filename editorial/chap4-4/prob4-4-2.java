import java.util.*;

class Main {
	public static void main(String[] args) {
		int N = 1000;
		double Answer = 0.0;
		
		for (int i = 0; i < N; i++) {
			double x = 1.0 * (2 * i + 1) / (2 * N);
			double value = Math.pow(2.0, x * x); // f((2i+1)/2N) の値
			Answer += value;
		}
		
		System.out.format("%.12f\n", Answer / N);
	}
}