import java.util.*;
import java.math.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigInteger f[] = new BigInteger[520];
		f[1] = new BigInteger("1");
		f[2] = new BigInteger("2");
		for(int i=3 ; i < 510 ; ++i )
			f[i] = f[i-1].add(f[i-2]);
		
		while( true ){
			BigInteger a = cin.nextBigInteger();
			BigInteger b = cin.nextBigInteger();
			if( a.toString().charAt(0)=='0' && b.toString().charAt(0)=='0' )
				break;
			int ans = 0;
			for(int i=1 ; i < 510 ; ++i ){
				if( f[i].compareTo(a) >= 0 && f[i].compareTo(b) <= 0 )
					ans++;
			}
			System.out.println(ans);
		}
	}

}