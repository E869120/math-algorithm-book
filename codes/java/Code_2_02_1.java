import java.util.*;

class Code_2_02_1 {
	public static void main(String[] args) {
		// 四則演算
		System.out.println(869 + 120); // 989 と出力
		System.out.println(869 - 120); // 749 と出力
		System.out.println(869 * 120); // 104280 と出力
		System.out.println(869 / 120); // 7 と出力（整数型同士の割り算では、整数に切り捨てられることに注意）
		
		// 剰余 (mod)
		System.out.println(8 % 5); // 3 と出力
		System.out.println(869 % 120); // 29 と出力
		
		// 絶対値 (abs)
		System.out.println(Math.abs(-45)); // 45 と出力
		System.out.println(Math.abs(15)); // 15 と出力
		
		// 累乗 (pow)
		System.out.println((int)Math.pow(10.0, 2.0)); // 100 と出力
		System.out.println((int)Math.pow(3.0, 4.0)); // 81 と出力
		
		// 平方根 (sqrt)
		System.out.format("%.5f\n", Math.sqrt(4.0)); // 2.00000 と出力
		System.out.format("%.5f\n", Math.sqrt(2.0)); // 1.41421 と出力
	}
};
