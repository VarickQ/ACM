import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        int x = 0;
		
		for(x = 0;x<T;x++)
		{
		    BigDecimal ans = new BigDecimal(0.0);
		   // BigDecimal anst = new BigDecimal(0.0000000000000000000000000000000000001);
		    BigDecimal a = cin.nextBigDecimal();
		    while(true) {
		    	if(a.toString().equals("0"))break;
		    	ans = ans.add(a);
		    	a = cin.nextBigDecimal();
		    	//System.out.println(ta);
		    }
		    String as = ans.toString();
		    int len = as.length()-1;
		    int di = as.indexOf(".");
		    if(di!=-1){
		     while(len>=0&&as.charAt(len)=='0')len--;
		     if(len>=0&&as.charAt(len)=='.')len--;
		    }
		    for(int i=0;i<=len;i++) {
		    	System.out.print(as.charAt(i));
		    }
		    System.out.println();
		    
		}
			
	}
}