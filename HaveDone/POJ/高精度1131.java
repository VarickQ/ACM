import java.math.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigDecimal one = new BigDecimal(1.0);
		BigDecimal eight = new BigDecimal(8.0);
		
		while( cin.hasNext() ){
			
			BigDecimal ans = new BigDecimal(0.0);
			BigDecimal f = one.divide( eight );
			
			String a = cin.next();
			for(int i=2 ; i < a.length() ; ++i){
				
				BigDecimal now = new BigDecimal(a.charAt(i)-'0');
				ans = ans.add( now.multiply(f) );
				f = f.divide( eight );
			}
			System.out.println(a+" [8] = "+ans.toString().trim()+" [10]");
		}
		
	}

}
