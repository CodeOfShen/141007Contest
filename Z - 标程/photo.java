// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   photo.java                                               *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
	static BigInteger ONE = new BigInteger("1");
	static BigInteger TWO = new BigInteger("2");
	public static void main(String[] args) throws IOException
	{
		/**
		Scanner cin = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		**/
		Scanner cin = new Scanner(new FileReader("photo.in"));
		PrintWriter out = new PrintWriter("photo.out");
		int t = 0, tt = 0;
		t = cin.nextInt();
		while (t-- != 0)
		{
			BigInteger n = cin.nextBigInteger();
			BigInteger m = cin.nextBigInteger();
			BigInteger k = cin.nextBigInteger();
			BigInteger maxVoid = n.subtract(ONE).divide(TWO);
			maxVoid = maxVoid.multiply((m.subtract(ONE).divide(TWO)));
			BigInteger maxElem = n.multiply(m);
			BigInteger minElem = maxElem.subtract(maxVoid);
			String res;
			if (maxElem.compareTo(k) >= 0 
				&& minElem.compareTo(k) <= 0) res = "yes";
			else res = "no";
			out.println("Case #" + (++tt) + ": " + res);
		}
		cin.close();
		out.close();
	}
}
