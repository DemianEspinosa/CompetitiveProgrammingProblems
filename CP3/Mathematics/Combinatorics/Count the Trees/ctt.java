import java.util.*;
import java.math.*;

class Main{
	public static void main (String[] args){
		Scanner sc = new Scanner(System.in);
		BigInteger[] cat = new BigInteger[305];
		BigInteger[] fac = new BigInteger[305];
		cat[0] = BigInteger.valueOf(1);
		fac[0] = BigInteger.valueOf(1);
		for(int i = 1; i <= 300; i++)
			cat[i] = (cat[i - 1].multiply(BigInteger.valueOf(2 * (2 * i - 1)))).divide(BigInteger.valueOf(i + 1));
		for(int i = 1; i <= 300; i++)
			fac[i] = fac[i - 1].multiply(BigInteger.valueOf(i));
		int N;
		N = sc.nextInt();
		while(N != 0){
			System.out.println(cat[N].multiply(fac[N]));
			N = sc.nextInt();
			}
		}
	}

