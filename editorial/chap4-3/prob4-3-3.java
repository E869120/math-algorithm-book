import java.util.*;

class Main {
	public static void main(String[] args) {
		double l = 1.0;
		double r = 2.0;
		for (int i = 1; i <= 20; i++) {
			double m = (l + r) / 2.0;
			if (m * m < 2.0) l = m;
			else r = m;
			System.out.format("Step #%d: m = %.12f\n", i, m);
		}
	}
}