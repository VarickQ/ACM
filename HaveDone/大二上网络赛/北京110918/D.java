import java.util.*;
import java.math.*;

public class Main {

	public static void main(String[] args) {
		////////////////////////////////////////////////////////
		Scanner cin = new Scanner(System.in);
		BigInteger a,b,c,two;
		two = new BigInteger("2");
		BigInteger one = new BigInteger("1");
		int t = cin.nextInt();
		while(t != 0)
		{
			t--;
			int n = cin.nextInt();
			BigInteger temp = new BigInteger("1");
			BigInteger tt = one;
			a = b = c = one;
			for(int i = 0;i < n;++i)
			{
				a = a.multiply(temp);
				temp = temp.add(two);
				b = b.multiply(tt);
				tt = tt.add(one);
				c = c.multiply(two);
			}
			b = b.multiply(c);
			BigInteger gc = a.gcd(b);
			System.out.println(a.divide(gc) + "/" + b.divide(gc));
		}
	}
}