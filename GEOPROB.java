import java.util.*;
import java.math.BigInteger;

class GEOPROB
{
	private static Scanner input;

	public static void main (String[] args) throws java.lang.Exception
	{
		int t;
		input = new Scanner( System.in );
		t = input.nextInt();
		while( t > 0 )
		{
			BigInteger b,c,d;
			b = input.nextBigInteger();
			c = input.nextBigInteger();
			c = c.add(c);
			d = input.nextBigInteger();
			d = d.add(b);
			System.out.println(c.subtract(d));
			t = t-1;
		}
	}
}