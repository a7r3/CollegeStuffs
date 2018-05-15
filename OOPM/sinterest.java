import java.util.*;
/// Program which calculates Simple Interest

class sinterest
{
	public static void main(String args[])
	{
		/* Inbuilt class
			Object Name
			Creates an Object
			Constructor
			Input stream object
		*/
		Scanner sc = new Scanner(System.in);
		System.out.println("\nSpecify the Principal Amount\n");
		int p = sc.nextInt();
		System.out.println("\nSpecify the Rate of Interest\n");
		float r = sc.nextFloat();
		System.out.println("\nSpecify the number of years\n");
		int n = sc.nextInt();
		System.out.println("\nCalculating Simple Interest\n");
		float si = ( p * r * n ) / 100;
		System.out.println("Simple Interest is : " + si);
		System.out.println("\n\nMehTM\n\n");
	}
}
